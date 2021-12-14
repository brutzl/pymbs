/*
This file is part of PyMbs.

PyMbs is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as 
published by the Free Software Foundation, either version 3 of
the License, or (at your option) any later version.

PyMbs is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public 
License along with PyMbs.
If not, see <http://www.gnu.org/licenses/>.

Copyright 2011, 2012 Carsten Knoll, Christian Schubert, 
                     Jens Frenkel, Sebastian Voigt
*/

#include "Writer.h"
#include "str.h"

#ifdef WIN32
  #include <time.h>
#else
  #include <sys/time.h>
#endif

using namespace Symbolics;

/*****************************************************************************/
Writer::Writer(bool makeScalar):m_scalar(makeScalar)
/*****************************************************************************/
{
}
/*****************************************************************************/


/*****************************************************************************/
Writer::~Writer()
/*****************************************************************************/
{
}
/*****************************************************************************/


/*****************************************************************************/
double Writer::generateTarget(std::string name, std::string path, Graph::Graph& g, bool optimize)
/*****************************************************************************/
{
    // make scalar = 
    if (m_scalar)
    {
        g.makeScalar();

        // build equations
        g.buildGraph(optimize);
    }

    for (std::string::iterator it = path.begin(); it != path.end(); ++it) //Backslashs in slashs wandeln.
        if (*it=='\\') 
            *it='/';
    m_path = path;

    m_name = name;
    // 
    return generateTarget_Impl(g);
}
/*****************************************************************************/

/*****************************************************************************/
std::string Writer::getHeaderLine()
/*****************************************************************************/
{
    std::string s = "This file was generated by PyMbs on ";

    time_t st;
    st=time(NULL);
    struct tm* gmt=gmtime(&st); //VisualStudio complains about unsafe function - ignore it, otherwise its not cross platform.
	//If someone finds a way to output the timezone in a reasonable way, one can switch back to localtime here
	char time_gmt_str[20];
	strftime(time_gmt_str, sizeof(time_gmt_str), "%Y-%m-%d %H:%M:%S", gmt);

    return s + time_gmt_str +" UTC";
}
/*****************************************************************************/

/*****************************************************************************/
bool Writer::sortVariableVec (boost::intrusive_ptr<Symbolics::Symbol> a, boost::intrusive_ptr<Symbolics::Symbol> b)
/*****************************************************************************/
{   // Genutzt wird operator< in Symbol.cpp
	return (*(a.get()) < *(b.get())); 
}
/*****************************************************************************/
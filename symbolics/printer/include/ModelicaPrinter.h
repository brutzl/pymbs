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

#ifndef __MODELICA_PRINTER_H_
#define __MODELICA_PRINTER_H_

#include "Printer.h"

namespace Symbolics
{
    class ModelicaPrinter: public Symbolics::Printer
    {
    public:
        // Konstruktor
        ModelicaPrinter();
        // Destruktor
        ~ModelicaPrinter();

        //comment Funktion überschreiben
        std::string comment( std::string const& comment ) const;

        std::string dimension( BasicPtr const& basic );

    protected:
        //geforderte Funktionen überschreiben
        std::string print_Element( const Element *e );
        std::string print_Matrix( const Matrix *mat );
        std::string print_Skew( const Skew *s ); 
        std::string print_Pow( const Pow *pow );
        std::string print_Zero( const Zero *z );
        std::string print_Bool( const Bool *b );

        // Funktionen die sich vom Standard unterscheiden, ueberschreiben
        std::string print_Der( const Der *d );
		std::string print_Mul( const Mul *m );
        std::string print_If( const If *e );
        std::string print_Inverse( const Inverse *c );
        std::string print_Scalar( const Scalar *s );
        std::string print_Solve( const Solve *s );
    };
};

#endif // __MODELICA_PRINTER_H_

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

#ifndef __ATAN2_H_
#define __ATAN2_H_

#include "BinaryOp.h"
#include "List.h"

namespace Symbolics
{

    class Atan2: public BinaryOp, public List
    {
    public:
        // Konstruktor
        Atan2( BasicPtrVec const& args );
        // Konstruktor
        Atan2( BasicPtr const& arg1, BasicPtr const& arg2 );
        // Destruktor
        ~Atan2();

        // toString
        std::string toString() const;

        // Vereinfachen, wenn unverändert, dann NULL
        BasicPtr simplify();

        static BasicPtr New( BasicPtr const& arg1, BasicPtr const& arg2);

        static inline ScopePtr  getScope() { return m_scope; };
        static inline void newScope() { m_scope = ScopePtr(new Scope()); };

        // derivative
        BasicPtr der();
        BasicPtr der(BasicPtr const& symbol);
    private:
        static ScopePtr m_scope;
	protected:
		void validate();

    };

    typedef boost::intrusive_ptr< Atan2> ConstAtan2Ptr;
    typedef boost::intrusive_ptr<Atan2> Atan2Ptr;

};

#endif // __ATAN2_H_
// RNumericalMathFunctionEvaluation.h: ROpenTurns
//
// Copyright (C) 2012 - 2014   IRSN
//
// This file is part of ROpenTurns.
//
// ROpenTurns is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// ROpenTurns is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with ROpenTurns.  If not, see <http://www.gnu.org/licenses/>.

#ifndef ROPENTURNS_R_NUMERICALMATHFUNCTIONEVALUATION_H
#define ROPENTURNS_R_NUMERICALMATHFUNCTIONEVALUATION_H

#include "ROpenTurns.h"
#include <openturns/NumericalMathEvaluationImplementation.hxx>

namespace OT {

    class RNumericalMathEvaluationImplementation
        : public NumericalMathFunctionImplementation
    {
        CLASSNAME ;

    public:

        /** Default Constructor */
        RNumericalMathEvaluationImplementation() ;

        RNumericalMathEvaluationImplementation(Rcpp::Function fun_, UnsignedLong inputDimension_, UnsignedLong outputDimension_ ) ;

        /** Virtual constructor */
        virtual RNumericalMathEvaluationImplementation * clone() const;

        /** Comparison operator */
        Bool operator ==(const RNumericalMathEvaluationImplementation & other) const;

        /** String converter */
        virtual OT::String __repr__() const;


        /** Test for actual implementation */
        virtual Bool isActualImplementation() const;


        /* Here is the interface that all derived class must implement */

        /** Operator () */
        virtual NumericalPoint operator() (const NumericalPoint & inP) const;

        /** Accessor for input point dimension */
        virtual UnsignedLong getInputDimension() const;

        /** Accessor for output point dimension */
        virtual UnsignedLong getOutputDimension() const;

    private:

        Rcpp::RObject fun ;
        UnsignedLong inputDimension ;
        UnsignedLong outputDimension ;

    } ;


}

#endif

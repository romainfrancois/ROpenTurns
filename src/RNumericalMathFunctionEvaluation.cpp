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

#include "ROpenTurns.h"

namespace OT {

    CLASSNAMEINIT(RNumericalMathEvaluationImplementation);
    
    static Factory<RNumericalMathEvaluationImplementation> RegisteredFactory("RNumericalMathEvaluationImplementation");
    
    /* Default constructor */
    RNumericalMathEvaluationImplementation::RNumericalMathEvaluationImplementation()
      : NumericalMathEvaluationImplementation()
    {                                           
      // Nothing to do
    }
    
    RNumericalMathEvaluationImplementation::RNumericalMathEvaluationImplementation(Rcpp::Function fun_, UnsignedLong inputDimension_, UnsignedLong outputDimension_ )
    : NumericalMathEvaluationImplementation(), fun(fun_), inputDimension(inputDimension_), outputDimension(outputDimension_)
    {
       // Nothing to do 
    }    
    
    /* Virtual constructor */
    RNumericalMathEvaluationImplementation * RNumericalMathEvaluationImplementation::clone() const
    {
      return new RNumericalMathEvaluationImplementation(*this);
    }
    
    /* Comparison operator */
    Bool RNumericalMathEvaluationImplementation::operator ==(const RNumericalMathEvaluationImplementation & other) const
    {
      return fun == other.fun ;
    }
    
    /* String converter */
    String RNumericalMathEvaluationImplementation::__repr__() const {
      OSS oss;
      oss << "class=" << RNumericalMathEvaluationImplementation::GetClassName()
          << " name=" << getName();
      return oss;
    }
    
    /* Test for actual implementation */
    Bool RNumericalMathEvaluationImplementation::isActualImplementation() const {
      return true;
    }
    
    
    
    /* Here is the interface that all derived class must implement */
    
    /* Operator () */
    NumericalPoint RNumericalMathEvaluationImplementation::operator() (const NumericalPoint & inP) const
    {
      if (inP.getDimension() != inputDimension) throw InvalidArgumentException(HERE) << "Error: the given point has an invalid dimension. Expect a dimension " << inputDimension << ", got " << inP.getDimension();
      
      Rcpp::NumericVector R_input( inP.begin(), inP.end() ) ;
      Rcpp::Function fun_(fun) ;
      Rcpp::NumericVector R_output = fun_( R_input ) ;
      NumericalPoint result( Collection<NumericalScalar>( R_output.begin(), R_output.end() ) ) ;
      
      // if (isHistoryEnabled_)
      //   {
      //     inputStrategy_.store(inP);
      //     outputStrategy_.store(result);
      //   }
      return result;
    }
    
    /* Accessor for input point dimension */
    UnsignedLong RNumericalMathEvaluationImplementation::getInputDimension() const
    {
      return inputDimension ;
    }
    
    /* Accessor for output point dimension */
    UnsignedLong RNumericalMathEvaluationImplementation::getOutputDimension() const
    {
      return outputDimension ;
    }

}

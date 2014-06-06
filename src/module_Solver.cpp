#include "ROpenTurns.h"
    
namespace ROpenTurns{
                            
    NumericalScalar (SolverImplementation::*NumericalScalar_solve_0)(const NumericalMathFunction&, const NumericalScalar,const NumericalScalar, const NumericalScalar) const = &SolverImplementation::solve ;
    NumericalScalar (SolverImplementation::*NumericalScalar_solve_1)(const NumericalMathFunction&, const NumericalScalar,const NumericalScalar, const NumericalScalar, const NumericalScalar,const NumericalScalar) const = &SolverImplementation::solve ;
    
}

RCPP_MODULE(Solver){
    
    class_<SolverImplementation>( "SolverImplementation" )
        .constructor()
        .constructor<NumericalScalar,NumericalScalar,NumericalScalar,UnsignedLong>()
        // TODO: operator==
        SHOW(SolverImplementation)
        .method( "solve", ROpenTurns::NumericalScalar_solve_0 )
        .method( "solve", ROpenTurns::NumericalScalar_solve_1 )
        METHOD_GET_SET(SolverImplementation, AbsoluteError)
        METHOD_GET_SET(SolverImplementation, RelativeError)
        METHOD_GET_SET(SolverImplementation, MaximumFunctionEvaluation)
    ;                                                                                                              
      
    class_<Bisection>("Bisection" )
        DERIVES(SolverImplementation)
        .constructor()
        .constructor<NumericalScalar, NumericalScalar, UnsignedLong>()
    ;
    class_<Brent>("Brent" )
        DERIVES(SolverImplementation)
        .constructor()
        .constructor<NumericalScalar, NumericalScalar, UnsignedLong>()
    ;
    class_<Secant>("Secant" )
        DERIVES(SolverImplementation)
        .constructor()
        .constructor<NumericalScalar, NumericalScalar, UnsignedLong>()
    ;
    class_<Solver>( "Solver" )
        .factory( &ROpenTurns::new_Solver )
        .constructor<NumericalScalar,NumericalScalar,NumericalScalar,UnsignedLong>()
        // TODO: operator==
        METHOD_GET_SET(Solver, AbsoluteError)
        METHOD_GET_SET(Solver, RelativeError)
        METHOD_GET_SET(Solver, MaximumFunctionEvaluation)
    ;
    
    
}

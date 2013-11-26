// :folding=explicit:
#include "ROpenTurns.h"
    
namespace ROpenTurns{
    
}

RCPP_MODULE(NearestPointAlgorithm){
    
    class_<NearestPointAlgorithmImplementationResult>( "NearestPointAlgorithmImplementationResult" )
        .constructor()
        .constructor<NumericalPoint,UnsignedLong,NumericalScalar,NumericalScalar,NumericalScalar,NumericalScalar>()
        SHOW(NearestPointAlgorithmImplementationResult)
        METHOD(NearestPointAlgorithmImplementationResult,getMinimizer)
        METHOD(NearestPointAlgorithmImplementationResult,getIterationsNumber)
        METHOD(NearestPointAlgorithmImplementationResult,getAbsoluteError)
        METHOD(NearestPointAlgorithmImplementationResult,getRelativeError)
        METHOD(NearestPointAlgorithmImplementationResult,getResidualError)
        METHOD(NearestPointAlgorithmImplementationResult,getConstraintError)
    ;
    
    class_<NearestPointAlgorithmImplementation>( "NearestPointAlgorithmImplementation")
        .constructor()
        .constructor<NumericalMathFunction,Bool>()
        SHOW(NearestPointAlgorithmImplementation)
        METHOD(NearestPointAlgorithmImplementation,run)
        METHOD_GET_SET(NearestPointAlgorithmImplementation,StartingPoint)
        METHOD_GET_SET(NearestPointAlgorithmImplementation,LevelFunction)
        METHOD_GET_SET(NearestPointAlgorithmImplementation,LevelValue)
        METHOD_GET_SET(NearestPointAlgorithmImplementation,Result)
        METHOD_GET_SET(NearestPointAlgorithmImplementation,MaximumIterationsNumber)
        METHOD_GET_SET(NearestPointAlgorithmImplementation,MaximumAbsoluteError)
        METHOD_GET_SET(NearestPointAlgorithmImplementation,MaximumRelativeError)
        METHOD_GET_SET(NearestPointAlgorithmImplementation,MaximumResidualError)
        METHOD_GET_SET(NearestPointAlgorithmImplementation,MaximumConstraintError)
    ;
    
    class_<AbdoRackwitzSpecificParameters>( "AbdoRackwitzSpecificParameters" )
        .constructor()
        .constructor<NumericalScalar,NumericalScalar,NumericalScalar>()
        METHOD_GET_SET(AbdoRackwitzSpecificParameters,Tau)
        METHOD_GET_SET(AbdoRackwitzSpecificParameters,Omega)
        METHOD_GET_SET(AbdoRackwitzSpecificParameters,Smooth)
        SHOW(AbdoRackwitzSpecificParameters)
    ;
    class_<AbdoRackwitz>( "AbdoRackwitz")
        .derives<NearestPointAlgorithmImplementation>( "NearestPointAlgorithmImplementation")
        .constructor<AbdoRackwitzSpecificParameters,NumericalMathFunction>()
        METHOD_GET_SET(AbdoRackwitz, SpecificParameters )
    ; 
    class_<CobylaSpecificParameters>( "CobylaSpecificParameters" )
        .constructor()
        .constructor<NumericalScalar>()
        SHOW(CobylaSpecificParameters)
        METHOD_GET_SET(CobylaSpecificParameters,RhoBeg)
    ;
    class_<Cobyla>( "Cobyla" )
        .derives<NearestPointAlgorithmImplementation>( "NearestPointAlgorithmImplementation")
        .constructor()
        .constructor<NumericalMathFunction,Bool>()
        .constructor<CobylaSpecificParameters,NumericalMathFunction,Bool>()
        METHOD_GET_SET(Cobyla, SpecificParameters )
    ;
    class_<SQPSpecificParameters>("SQPSpecificParameters")
        .constructor()
        .constructor<NumericalScalar,NumericalScalar,NumericalScalar>()
        SHOW(SQPSpecificParameters)
        METHOD_GET_SET(SQPSpecificParameters,Tau)
        METHOD_GET_SET(SQPSpecificParameters,Omega)
        METHOD_GET_SET(SQPSpecificParameters,Smooth)
    ;
    class_<SQP>( "SQP" )
        .derives<NearestPointAlgorithmImplementation>( "NearestPointAlgorithmImplementation")
        .constructor()
        .constructor<SQPSpecificParameters,NumericalMathFunction,Bool>()
        METHOD_GET_SET(SQP, SpecificParameters )
    ;
    class_<NearestPointAlgorithm>( "NearestPointAlgorithm")
        .constructor()
        .factory( &ROpenTurns::new_NearestPointAlgorithm )
        METHOD(NearestPointAlgorithm, run )
        METHOD_GET_SET(NearestPointAlgorithm, StartingPoint )
        METHOD_GET_SET(NearestPointAlgorithm, LevelFunction )
        METHOD_GET_SET(NearestPointAlgorithm, LevelValue )
        METHOD_GET_SET(NearestPointAlgorithm, Result )
        METHOD_GET_SET(NearestPointAlgorithm, MaximumIterationsNumber )
        METHOD_GET_SET(NearestPointAlgorithm, MaximumAbsoluteError )
        METHOD_GET_SET(NearestPointAlgorithm, MaximumRelativeError )
        METHOD_GET_SET(NearestPointAlgorithm, MaximumResidualError )
        METHOD_GET_SET(NearestPointAlgorithm, MaximumConstraintError )
        METHOD_GET_SET(NearestPointAlgorithm, Verbose )
    ;    
}

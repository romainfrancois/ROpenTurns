#include "ROpenTurns.h"

RCPP_MODULE(SimulationResult){

    class_<SimulationResultImplementation>( "SimulationResultImplementation" )
        .constructor()
        .constructor<Event,NumericalScalar,NumericalScalar,UnsignedLong,UnsignedLong>()
        SHOW( SimulationResultImplementation )
        METHOD_GET_SET(SimulationResultImplementation, Event)
        METHOD_GET_SET(SimulationResultImplementation, ProbabilityEstimate)
        METHOD_GET_SET(SimulationResultImplementation, VarianceEstimate) 
        METHOD_GET_SET(SimulationResultImplementation, BlockSize)
        METHOD_GET_SET(SimulationResultImplementation, OuterSampling)
        // .method( "getConfidenceLength", &SimulationResultImplementation::getConfidenceLength )    
        METHOD(SimulationResultImplementation, getCoefficientOfVariation)
        METHOD(SimulationResultImplementation, getStandardDeviation)
        METHOD(SimulationResultImplementation, getMeanPointInEventDomain)
        METHOD(SimulationResultImplementation, getImportanceFactors)
    ;     
    class_<QuasiMonteCarloResult>( "QuasiMonteCarloResult" )
        .derives<SimulationResultImplementation>( "SimulationResultImplementation" )
        .constructor()
        .constructor<Event,NumericalScalar,NumericalScalar,UnsignedLong,UnsignedLong>()
    ;    
    
    class_<SimulationResult>( "SimulationResult" )
        .constructor()
        .factory( &ROpenTurns::new_SimulationResult )
        .constructor<Event,NumericalScalar,NumericalScalar,UnsignedLong,UnsignedLong>() 
        SHOW(SimulationResult)
        METHOD_GET_SET(SimulationResult,ProbabilityEstimate)
        METHOD_GET_SET(SimulationResult,VarianceEstimate)
        METHOD_GET_SET(SimulationResult,OuterSampling)
        METHOD_GET_SET(SimulationResult,BlockSize)
        METHOD(SimulationResult,getCoefficientOfVariation)
        METHOD(SimulationResult,getStandardDeviation)
        METHOD(SimulationResult,getMeanPointInEventDomain)
        METHOD(SimulationResult,getConfidenceLength)  
        METHOD(SimulationResult,getImportanceFactors) 
    ;
    
    
}

// :folding=explicit:
#include "ROpenTurns.h"
    
namespace ROpenTurns{
    NumericalSample WeightedExperiment_generate_1(WeightedExperiment* obj, const NumericalPoint& weights){
        return obj->generate( const_cast<NumericalPoint&>( weights ) ) ;         
    }
}

RCPP_MODULE(Experiment){
    
    class_<ExperimentImplementation>( "ExperimentImplementation")
        .constructor<OT::String>()
        SHOW(ExperimentImplementation)
        METHOD(ExperimentImplementation, generate)
    ;
    class_<StratifiedExperiment>( "StratifiedExperiment" )
        .derives<ExperimentImplementation>( "ExperimentImplementation")
        .constructor<OT::String>() 
        .constructor<NumericalPoint,NumericalPoint, OT::String>()
        METHOD_GET_SET( StratifiedExperiment, Center)
        METHOD_GET_SET( StratifiedExperiment, Levels )
    ;
    class_<WeightedExperiment>( "WeightedExperiment" )
        .derives<ExperimentImplementation>( "ExperimentImplementation")
        .constructor<OT::String>()
        .constructor<UnsignedLong,OT::String>()
        .constructor<Distribution, UnsignedLong,OT::String>()
        METHOD_GET_SET(WeightedExperiment, Distribution )
        METHOD_GET_SET(WeightedExperiment, Size )
        METHOD( WeightedExperiment, getWeight )    
        .method( "generate", ROpenTurns::WeightedExperiment_generate_1 )
    ;     
    
    class_<Experiment>( "Experiment" )
        .constructor<OT::String>()
        .factory( &ROpenTurns::new_Experiment )
        SHOW(Experiment)
        METHOD(Experiment,generate)
    ;
}

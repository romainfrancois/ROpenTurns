// :folding=explicit:
#include "ROpenTurns.h"
    
    
RCPP_MODULE(Simulation){

    class_<Simulation>( "Simulation" )
        SHOW(Simulation)
        METHOD_GET_SET(Simulation, BlockSize)
        METHOD(Simulation, getEvent)
        METHOD_GET_SET(Simulation, MaximumOuterSampling )
        METHOD_GET_SET(Simulation, MaximumCoefficientOfVariation )
        METHOD_GET_SET(Simulation, MaximumStandardDeviation )
        METHOD_GET_SET(Simulation, Verbose )
        METHOD_GET_SET(Simulation, ConvergenceStrategy)
        METHOD(Simulation, getResult )
        METHOD(Simulation, run )
    ;     
       
    class_<DirectionalSampling>( "DirectionalSampling" )
        .derives<Simulation>( "Simulation" )
        .constructor<Event>()
        METHOD_GET_SET(DirectionalSampling, RootStrategy) 
    ;
    class_<ImportanceSampling>( "ImportanceSampling" )
        .derives<Simulation>( "Simulation" )
        .constructor<Event,Distribution>()
        METHOD( ImportanceSampling, getImportanceDistribution) 
    ;
    class_<LHS>( "LHS" )
        .derives<Simulation>( "Simulation" )
        .constructor()
        .constructor<Event>()
    ;
    class_<MonteCarlo>( "MonteCarlo" )
        .derives<Simulation>( "Simulation" )
        .constructor()
        .constructor<Event>()
        SHOW(MonteCarlo)
    ;
    
}

#include "ROpenTurns.h"

namespace ROpenTurns{
    NumericalPoint (SamplingStrategyImplementation::*SamplingStrategyImplementation_getUniformUnitVectorRealization_0)(void) const = &SamplingStrategyImplementation::getUniformUnitVectorRealization ;
    NumericalPoint (SamplingStrategyImplementation::*SamplingStrategyImplementation_getUniformUnitVectorRealization_1)(const UnsignedLong) const = &SamplingStrategyImplementation::getUniformUnitVectorRealization ;
}
RCPP_MODULE(SimulationStrategy){

    class_<SamplingStrategyImplementation>( "SamplingStrategyImplementation" )
        .constructor<UnsignedLong>()
        SHOW(SamplingStrategyImplementation)
        METHOD( SamplingStrategyImplementation, generate )
        .method( "getUniformUnitVectorRealization", ROpenTurns::SamplingStrategyImplementation_getUniformUnitVectorRealization_0 )
        .method( "getUniformUnitVectorRealization", ROpenTurns::SamplingStrategyImplementation_getUniformUnitVectorRealization_1 )
        METHOD_GET_SET(SamplingStrategyImplementation, Dimension )
    ;
    class_<OrthogonalDirection>( "OrthogonalDirection" )
        .derives<SamplingStrategyImplementation>( "SamplingStrategyImplementation" ) 
        .constructor()
        .constructor<UnsignedLong,UnsignedLong>()
        METHOD( OrthogonalDirection, getUniformOrientationRealization )
    ;
    class_<RandomDirection>( "RandomDirection" )
        .derives<SamplingStrategyImplementation>( "SamplingStrategyImplementation" ) 
        .constructor()
        .constructor<UnsignedLong>()
    ;     
     
    class_<SamplingStrategy>( "SamplingStrategy" )
        .constructor()
        SHOW(SamplingStrategy)
        .factory( &ROpenTurns::new_SamplingStrategy )
        METHOD( SamplingStrategy, generate )
        METHOD_GET_SET( SamplingStrategy, Dimension )
    ;
    
}

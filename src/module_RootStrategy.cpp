#include "ROpenTurns.h"

RCPP_MODULE(RootStrategy){

    class_<RootStrategyImplementation>( "RootStrategyImplementation" )
        .constructor()
        .constructor<Solver>()
        .constructor<Solver,NumericalScalar,NumericalScalar>()
        SHOW( RootStrategyImplementation )
        METHOD_GET_SET(RootStrategyImplementation, Solver )
        METHOD_GET_SET(RootStrategyImplementation, MaximumDistance )
        METHOD_GET_SET(RootStrategyImplementation, StepSize )
        METHOD_GET_SET(RootStrategyImplementation, OriginValue )
        METHOD(RootStrategyImplementation, solve )
    ;                                                                                                              
    class_<MediumSafe>( "MediumSafe" )
        .derives<RootStrategyImplementation>( "RootStrategyImplementation" )
        .constructor()
        .constructor<Solver>()
        .constructor<Solver,NumericalScalar,NumericalScalar>()
    ;       
    class_<RiskyAndFast>( "RiskyAndFast" )
        .derives<RootStrategyImplementation>( "RootStrategyImplementation" )
        .constructor()
        .constructor<Solver>()
        .constructor<Solver,NumericalScalar>()
    ;       
    class_<SafeAndSlow>( "SafeAndSlow" )
        .derives<RootStrategyImplementation>( "RootStrategyImplementation" )
        .constructor()
        .constructor<Solver>()
        .constructor<Solver,NumericalScalar,NumericalScalar>()
    ;
    
    class_<RootStrategy>( "RootStrategy" )
        SHOW(RootStrategy)
        .factory( &ROpenTurns::new_RootStrategy )
        METHOD_GET_SET( RootStrategy, Solver )
        METHOD_GET_SET( RootStrategy, MaximumDistance )
        METHOD_GET_SET( RootStrategy, StepSize )
        METHOD_GET_SET( RootStrategy, OriginValue )
    ;
 
}

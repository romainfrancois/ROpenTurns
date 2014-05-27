// :folding=explicit:
#include "ROpenTurns.h"
    
    
RCPP_MODULE(HistoryStrategy){

    class_<HistoryStrategyImplementation>( "HistoryStrategyImplementation" )
        .constructor()
        SHOW(HistoryStrategyImplementation)
        // METHOD(HistoryStrategyImplementation, store)
        METHOD(HistoryStrategyImplementation, getSample)
    ;
    class_<Compact>( "Compact" )
        .derives<HistoryStrategyImplementation>( "HistoryStrategyImplementation" )
        .constructor()
        .constructor<UnsignedLong>()
        SHOW(Compact)
        METHOD(Compact, getHalfMaximumSize)
        METHOD(Compact, getIndex)
    ;
    class_<Full>( "Full" )
        .derives<HistoryStrategyImplementation>( "HistoryStrategyImplementation" )
        .constructor()
        SHOW(Full)
    ;
    class_<Last>( "Last" )
        .derives<HistoryStrategyImplementation>( "HistoryStrategyImplementation" )
        .constructor()
        .constructor<UnsignedLong>()
        METHOD(Last, getMaximumSize)
        METHOD(Last, getIndex)
        METHOD(Last, getHasWrapped)
    ;
    class_<Null>( "Null" )
        .derives<HistoryStrategyImplementation>( "HistoryStrategyImplementation" )
        .constructor()
    ;    
    
    class_<HistoryStrategy>( "HistoryStrategy" )
        .constructor()
        .factory( &ROpenTurns::new_HistoryStrategy ) 
        SHOW(HistoryStrategy)
        METHOD( HistoryStrategy, getSample )
        METHOD( HistoryStrategy, clear )
    ;
    
}

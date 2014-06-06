#include "ROpenTurns.h"

RCPP_MODULE(RandomVector){

    class_<RandomVector>( "RandomVector" )
        .constructor()
        .factory( &ROpenTurns::new_RandomVector )
        .factory( &ROpenTurns::new_RandomVector_2 )
        
        .method( "show", &ROpenTurns::show<RandomVector> )
        .method( "getDimension", &RandomVector::getDimension )
        .method( "getRealization", &RandomVector::getRealization )
        .method( "getSample", &RandomVector::getSample )
    ;
    function( "Compare___RandomVector___double" , &ROpenTurns::Compare___RandomVector___double ) ;
    
    class_<Event>( "Event" )  
        .constructor()
        .derives<RandomVector>( "RandomVector" ) 
        .method( "setName", &ROpenTurns::setName<Event> )
        .method( "getName", &ROpenTurns::getName<Event> )
    ;
   
}

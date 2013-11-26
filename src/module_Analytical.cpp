// :folding=explicit:
#include "ROpenTurns.h"
    
namespace ROpenTurns{
    
}

RCPP_MODULE(Analytical){
    
    class_<Analytical>( "Analytical" )
        .constructor<NearestPointAlgorithm,Event,NumericalPoint>()
        SHOW(Analytical)
        METHOD_GET_SET(Analytical,PhysicalStartingPoint)
        METHOD_GET_SET(Analytical,Event)
        METHOD_GET_SET(Analytical,NearestPointAlgorithm)
        METHOD(Analytical,getAnalyticalResult)
        METHOD(Analytical,run)
    ;
}

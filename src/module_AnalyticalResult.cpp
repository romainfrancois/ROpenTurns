// :folding=explicit:
#include "ROpenTurns.h"
    
namespace ROpenTurns{
    
}

RCPP_MODULE(AnalyticalResult){
    
    class_<AnalyticalResult>( "AnalyticalResult" )
        .constructor()
        SHOW(AnalyticalResult)
        METHOD(AnalyticalResult, getPhysicalSpaceDesignPoint )
        METHOD(AnalyticalResult, getLimitStateVariable )
        METHOD_GET_SET(AnalyticalResult, StandardSpaceDesignPoint)
        METHOD_GET_SET(AnalyticalResult, IsStandardPointOriginInFailureSpace )
        METHOD_GET_SET(AnalyticalResult, MeanPointInStandardEventDomain )
        METHOD(AnalyticalResult, getImportanceFactors)
        METHOD(AnalyticalResult, getHasoferReliabilityIndex )
        METHOD(AnalyticalResult, getHasoferReliabilityIndexSensitivity )
    ;    
    class_<FORMResult>( "FORMResult" )
        .derives<AnalyticalResult>( "AnalyticalResult" )
        .constructor()
        .constructor<NumericalPoint,Event,Bool,OT::String>()
        METHOD(FORMResult,getEventProbability)
        METHOD(FORMResult,getGeneralisedReliabilityIndex)
        METHOD(FORMResult,getEventProbabilitySensitivity)
    ;
    class_<SORMResult>( "SORMResult")
        .derives<AnalyticalResult>( "AnalyticalResult" )
        .constructor()
        .constructor<NumericalPoint,Event,Bool,OT::String>()
        METHOD(SORMResult,getEventProbabilityBreitung)
        METHOD(SORMResult,getEventProbabilityHohenBichler)
        METHOD(SORMResult,getEventProbabilityTvedt)
        METHOD(SORMResult,getGeneralisedReliabilityIndexBreitung)
        METHOD(SORMResult,getGeneralisedReliabilityIndexHohenBichler)
        METHOD(SORMResult,getGeneralisedReliabilityIndexTvedt)
        METHOD(SORMResult,getSortedCurvatures)
    ;    
        
}

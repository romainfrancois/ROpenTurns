// :folding=explicit:
#include "ROpenTurns.h"
    
namespace ROpenTurns{
   // helping overload resolution
    NumericalSample (NumericalSample::*NumericalSample__rank_0)(void) const = &NumericalSample::rank ;
    NumericalSample (NumericalSample::*NumericalSample__rank_1)(const UnsignedLong) const  = &NumericalSample::rank ;
    NumericalSample (NumericalSample::*NumericalSample__sort_0)(void) const = &NumericalSample::sort ;
    NumericalSample (NumericalSample::*NumericalSample__sort_1)(const UnsignedLong) const  = &NumericalSample::sort ;
} // namespace ROpenTurns

    
RCPP_MODULE(OpenTurns){
           
    class_<Description>( "Description" )
        .constructor()
        .factory( &ROpenTurns::new_Description )
    ;
    
    class_<NumericalPoint>( "NumericalPoint" )
        .default_constructor()
        .constructor<UnsignedLong>()  
        .constructor<UnsignedLong, NumericalScalar>()
        
        .method( "clone", &NumericalPoint::clone )
        .method( "norm", &NumericalPoint::norm )
        .method( "norm2", &NumericalPoint::norm2 )
        .method( "show", &ROpenTurns::show<NumericalPoint> )
        .method( "getDimension", &NumericalPoint::getDimension )                                
        .method( "getSize", &NumericalPoint::getSize )
        .method( "normalize", &NumericalPoint::normalize)
        .method( "normalize2", &NumericalPoint::normalize2)
    ;
    converter( "numeric", "NumericalPoint", &ROpenTurns::as_throughCollection<NumericalPoint> ) ;

    class_<NumericalPointWithDescription>( "NumericalPointWithDescription" )
        .derives<NumericalPoint>( "NumericalPoint" )
        .constructor()
        .constructor<UnsignedLong>()
        .constructor<UnsignedLong, NumericalScalar>()
        METHOD_GET_SET( NumericalPointWithDescription, Description )
    ;
    
    class_<NumericalSample>( "NumericalSample" )
        .constructor()
        .constructor<UnsignedLong,UnsignedLong>()
        SHOW(NumericalSample)
        METHOD(NumericalSample, computeMean)
        METHOD(NumericalSample, computeCovariance)
        METHOD(NumericalSample, computeStandardDeviation)
        METHOD(NumericalSample, computeStandardDeviationPerComponent)
        METHOD(NumericalSample, computePearsonCorrelation)
        METHOD(NumericalSample, computeSpearmanCorrelation)
        METHOD(NumericalSample, computeKendallTau)
        METHOD(NumericalSample, computeRangePerComponent)
        METHOD(NumericalSample, computeMedianPerComponent)
        METHOD(NumericalSample, computeVariancePerComponent)
        METHOD(NumericalSample, computeSkewnessPerComponent)
        METHOD(NumericalSample, computeKurtosisPerComponent)
        METHOD(NumericalSample, computeCenteredMomentPerComponent)
        METHOD(NumericalSample, computeQuantilePerComponent)
        METHOD(NumericalSample, computeQuantile)
        METHOD(NumericalSample, computeEmpiricalCDF)
        .method( "rank", ROpenTurns::NumericalSample__rank_0 )
        .method( "rank", ROpenTurns::NumericalSample__rank_1 )
        .method( "sort", ROpenTurns::NumericalSample__sort_0 )
        .method( "sort", ROpenTurns::NumericalSample__sort_1 )
        METHOD(NumericalSample, sortAccordingToAComponent)
        METHOD(NumericalSample, find)
        METHOD(NumericalSample, scale)
        METHOD(NumericalSample, storeToTemporaryFile)  
        .method( "getMarginal", &ROpenTurns::NumericalSample__getMarginal )
    ;
    converter( "NumericalSample", "matrix", &ROpenTurns::NumericalSample_as_Matrix ) ;
    
    class_<Interval>( "Interval" )
        .constructor<UnsignedLong>( )
        .constructor<NumericalScalar,NumericalScalar>()
                 
        .method( "show", &ROpenTurns::show<Interval> )
        .method( "isEmpty", &Interval::isEmpty )
        .method( "isNumericallyEmpty", &Interval::isNumericallyEmpty )
        .method( "contains", &Interval::contains )     
        .method( "numericallyContains", &Interval::numericallyContains )
    ;
    
    class_<Indices>( "Indices" )
        .constructor()
        .constructor<UnsignedLong>()
        .constructor<UnsignedLong,UnsignedLong>()
        METHOD(Indices, check )
        METHOD(Indices, fill )
    ;
      
    function( "NormalCopula.GetCorrelationFromSpearmanCorrelation", &ROpenTurns::NormalCopula_GetCorrelationFromSpearmanCorrelation ) ;
    function( "NormalCopula.GetCorrelationFromKendallCorrelation", &ROpenTurns::NormalCopula_GetCorrelationFromKendallCorrelation ) ;
    
    class_<NumericalMathFunction>( "NumericalMathFunction" )
        .constructor()
        .method( "show", &ROpenTurns::show<NumericalMathFunction> ) 
    ;
    function( "asNumericalMathFunction", &ROpenTurns::asNumericalMathFunction ) ;
             
    class_<NumericalPointWithDescriptionCollection>( "NumericalPointWithDescriptionCollection" )
        .constructor()
        .constructor<UnsignedLong>()
        SHOW(NumericalPointWithDescriptionCollection)
    ;
    class_<NumericalPointCollection>( "NumericalPointCollection" )
        .constructor()
        .constructor<UnsignedLong>()
        SHOW(NumericalPointCollection)
    ;
    
}


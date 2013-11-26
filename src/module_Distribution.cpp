// :folding=explicit:
#include "ROpenTurns.h"

namespace ROpenTurns{
    
    bool valid_0_or_1_int(SEXP* args, int n){
        return n == 0 || ( n == 1 && ( TYPEOF(args[0]) == INTSXP || TYPEOF(args[0]) == REALSXP ) ); 
    }
    bool valid_0_or_1_string(SEXP* args, int n){
        return n == 0 || ( n == 1 && ( TYPEOF(args[0]) == STRSXP ) ); 
    }   
    
    bool valid_1_CorrelationMatrix(SEXP* args, int n){
        return Valid_1( "CorrelationMatrix" )(args,n) ;    
    }
    
    SEXP DistributionImplementation_computeDDF( DistributionImplementation* obj, SEXP x){
        if( TYPEOF(x) == REALSXP || TYPEOF(x) == INTSXP ){
            return wrap( obj->computeDDF( as<double>(x) ) ) ;    
        }
        if( Rf_inherits(x, "Rcpp_NumericalPoint" ) ){
            return module_wrap<NumericalPoint>( obj->computeDDF( as<NumericalPoint>( x ) ) ) ;    
        }
        if( Rf_inherits(x, "Rcpp_NumericalSample" ) ){
            return module_wrap<NumericalSample>( obj->computeDDF( as<NumericalSample>( x ) ) ) ;    
        }
        // should not happen
        return R_NilValue ;
    }
    
    SEXP DistributionImplementation_computePDF( DistributionImplementation* obj, SEXP x){
        if( TYPEOF(x) == REALSXP || TYPEOF(x) == INTSXP ){
            return wrap( obj->computePDF( as<double>(x) ) ) ;    
        }
        if( Rf_inherits(x, "Rcpp_NumericalPoint" ) ){
            return module_wrap<NumericalPoint>( obj->computePDF( as<NumericalPoint>( x ) ) ) ;    
        }
        if( Rf_inherits(x, "Rcpp_NumericalSample" ) ){
            return module_wrap<NumericalSample>( obj->computePDF( as<NumericalSample>( x ) ) ) ;    
        }
        // should not happen
        return R_NilValue ;
    }
    
    SEXP DistributionImplementation_computeCDF( DistributionImplementation* obj, SEXP x, Bool tail){
        if( TYPEOF(x) == REALSXP || TYPEOF(x) == INTSXP ){
            return wrap( obj->computeCDF( as<double>(x), tail ) ) ;    
        }
        if( Rf_inherits(x, "Rcpp_NumericalPoint" ) ){
            return module_wrap<NumericalPoint>( obj->computeCDF( as<NumericalPoint>( x ), tail ) ) ;    
        }
        if( Rf_inherits(x, "Rcpp_NumericalSample" ) ){
            return module_wrap<NumericalSample>( obj->computeCDF( as<NumericalSample>( x ), tail ) ) ;    
        }
        // should not happen
        return R_NilValue ;
    }
    
    NumericalSample (DistributionImplementation::*DistributionImplementation_computePDF_4)(const NumericalScalar, const NumericalScalar, const UnsignedLong, const NumericalScalar) const = &DistributionImplementation::computePDF ;
    NumericalSample (DistributionImplementation::*DistributionImplementation_computeCDF_5)(const NumericalScalar, const NumericalScalar, const UnsignedLong, const NumericalScalar, const Bool) const = &DistributionImplementation::computeCDF ;
       
    NumericalComplex DistributionImplementation_computeCharacteristicFunction_2(DistributionImplementation* obj, const NumericalScalar x, const Bool logScale){
        return obj->computeCharacteristicFunction(x, logScale ) ;
    }
    
    SEXP DistributionImplementation_computeGeneratingFunction_2( DistributionImplementation* obj, SEXP z, Bool logScale = false ){
        if( TYPEOF(z) == INTSXP || TYPEOF(z) == REALSXP ){
            return wrap( obj->computeGeneratingFunction( as<double>( z ), logScale ) );
        }
        
        // assuming complex
        return wrap( obj->computeGeneratingFunction( as<NumericalComplex>( z ), logScale ) ) ;
    }
    
    SEXP DistributionImplementation_computeQuantile_2(DistributionImplementation* obj, SEXP prob, Bool tail = false ){
        if( TYPEOF(prob) == REALSXP || Rf_length(prob) == 1 ){
            return wrap( obj->computeQuantile( as<double>( prob ), tail ) );    
        }
        // if( Rf_inherits( prob, "Rcpp_NumericalPoint" ) ){
        //     NumericalPoint p = as<NumericalPoint>( prob ) ;
        //     return wrap( obj->computeQuantile( p, tail ) ) ;    
        // }
        Rf_error( "`prob` should be a single numeric value" ) ;
        return R_NilValue ;
    } 
    
    NumericalSample (DistributionImplementation::*DistributionImplementation_computeQuantile_5)( 
        const NumericalScalar, const NumericalScalar, const UnsignedLong, const NumericalScalar, const Bool) const = &DistributionImplementation::computeQuantile ;
    
    NumericalSample (DistributionImplementation::*DistributionImplementation_getSupport_0)(void) const = &DistributionImplementation::getSupport ;
    NumericalSample (DistributionImplementation::*DistributionImplementation_getSupport_1)(const Interval&) const = &DistributionImplementation::getSupport ;
    
    NumericalSample (DistributionImplementation::*DistributionImplementation_getGaussNodesAndWeights_0)(void) const = &DistributionImplementation::getGaussNodesAndWeights ;
    NumericalPoint DistributionImplementation_getGaussNodesAndWeights_1(DistributionImplementation* obj, const NumericalPoint& p ){
        return obj->getGaussNodesAndWeights(const_cast<NumericalPoint&>(p) ) ;
    }
    
    object<DistributionImplementation> DistributionImplementation_getMarginal_1( DistributionImplementation* obj, SEXP indices ) {
        if( ( TYPEOF(indices) == INTSXP || TYPEOF(indices) == REALSXP ) && Rf_length(indices) == 1 ){
            return obj->getMarginal( as<int>( indices ) ) ;
        }
        if( Rf_inherits( indices, "Rcpp_Indices" ) ){
            return obj->getMarginal( as<Indices>( indices ) ) ;    
        }
        Rf_error( "indices should be a int of length 1 or an instance of Indices" ) ;
    }
    
    void DistributionImplementation_setParametersCollection( DistributionImplementation* obj, SEXP params ){
        if( Rf_inherits( params, "Rcpp_NumericalPoint" ) ){
            obj->setParametersCollection( as<NumericalPoint>( params ) ) ;
        } else if( Rf_inherits( params, "Rcpp_NumericalPointCollection" ) ){
            obj->setParametersCollection( as<NumericalPointCollection>( params ) ) ;
        } else {
            obj->setParametersCollection( as<NumericalPointWithDescriptionCollection>( params ) ) ;    
        }
    }
    
}

RCPP_MODULE(Distribution){
    
    class_<DistributionImplementation>( "DistributionImplementation" )
        SHOW(DistributionImplementation)
        .constructor<OT::String>()
        METHOD_GET_SET(DistributionImplementation, Weight)
        METHOD(DistributionImplementation,getDimension)
        METHOD(DistributionImplementation,getRealization)
        .method( "computeDDF", ROpenTurns::DistributionImplementation_computeDDF )     
        
        .method( "computePDF", ROpenTurns::DistributionImplementation_computePDF )     
        .method( "computePDF", ROpenTurns::DistributionImplementation_computePDF_4 )
        
        .method( "computeCDF", ROpenTurns::DistributionImplementation_computeCDF )     
        .method( "computeCDF", ROpenTurns::DistributionImplementation_computeCDF_5 )     
        
        .method( "computeCharacteristicFunction", ROpenTurns::DistributionImplementation_computeCharacteristicFunction_2 )
        .method( "computeGeneratingFunction", ROpenTurns::DistributionImplementation_computeGeneratingFunction_2 )
        
        .method( "computeQuantile", ROpenTurns::DistributionImplementation_computeQuantile_2 )
        .method( "computeQuantile", ROpenTurns::DistributionImplementation_computeQuantile_5 )     
        
        .method( "getSupport", ROpenTurns::DistributionImplementation_getSupport_0 )
        .method( "getSupport", ROpenTurns::DistributionImplementation_getSupport_1 )
                                                                                             
        .method( "getMarginal", ROpenTurns::DistributionImplementation_getMarginal_1 )
        
        .method( "getGaussNodesAndWeights", ROpenTurns::DistributionImplementation_getGaussNodesAndWeights_0 ) 
        .method( "getGaussNodesAndWeights", ROpenTurns::DistributionImplementation_getGaussNodesAndWeights_1 )
        
        METHOD(DistributionImplementation, computeProbability )
        METHOD(DistributionImplementation, computePDFGradient)
        METHOD(DistributionImplementation, computeCDFGradient)
        METHOD(DistributionImplementation, getRange)
        METHOD(DistributionImplementation,getRoughness)
        METHOD(DistributionImplementation,getMean)
        METHOD(DistributionImplementation,getStandardDeviation)
        METHOD(DistributionImplementation,getSkewness)
        METHOD(DistributionImplementation,getKurtosis)
        METHOD(DistributionImplementation,getStandardMoment)
        METHOD(DistributionImplementation,getMoment)
        METHOD(DistributionImplementation,getCenteredMoment)
        METHOD(DistributionImplementation,getCovariance)
        METHOD(DistributionImplementation,getCorrelation)
        METHOD(DistributionImplementation,getCholesky)
        METHOD(DistributionImplementation,getInverseCholesky)
        METHOD(DistributionImplementation,isElliptical)
        METHOD(DistributionImplementation,isContinuous)
        METHOD(DistributionImplementation,isIntegral)
        METHOD(DistributionImplementation,hasEllipticalCopula)
        METHOD(DistributionImplementation,hasIndependentCopula)
        METHOD(DistributionImplementation,computeDensityGenerator)
        METHOD(DistributionImplementation,computeDensityGeneratorDerivative)
        METHOD(DistributionImplementation,computeDensityGeneratorSecondDerivative)
        METHOD(DistributionImplementation,computeRadialDistributionCDF)
        // METHOD(,getCopula)
        // METHOD(,getStandardDistribution)
        METHOD(DistributionImplementation,computeConditionalDDF)
        METHOD(DistributionImplementation,computeConditionalPDF)
        METHOD(DistributionImplementation,computeConditionalCDF)
        METHOD(DistributionImplementation,computeConditionalQuantile)
        METHOD(DistributionImplementation,getIsoProbabilisticTransformation)
        METHOD(DistributionImplementation,getInverseIsoProbabilisticTransformation)
        METHOD_GET_SET(DistributionImplementation,IntegrationNodesNumber)
        METHOD(DistributionImplementation,getParametersCollection)
        .method( "setParametersCollection", ROpenTurns::DistributionImplementation_setParametersCollection )
        METHOD(DistributionImplementation,getParametersNumber)
        METHOD_GET_SET(DistributionImplementation, Description )
        METHOD(DistributionImplementation,getPDFEpsilon)
        METHOD(DistributionImplementation,getCDFEpsilon)
        METHOD(DistributionImplementation,getPositionIndicator)
        METHOD(DistributionImplementation,getDispersionIndicator)
    ;
    
    class_<ComposedDistribution>( "ComposedDistribution" )
        DERIVES(DistributionImplementation)
        .constructor()
        .constructor<DistributionCollection>()
        .constructor<DistributionCollection, Copula>()
    ;
    
    class_<Mixture>( "Mixture" )
        DERIVES(DistributionImplementation)
        .constructor()
        .constructor<DistributionCollection>()
        .constructor<DistributionCollection,NumericalPoint>()
        METHOD_GET_SET(Mixture, DistributionCollection)
    ;
#ifdef OPENTURNS_CONDITIONALDISTRIBUTION_HXX
    class_<ConditionalDistribution>( "ConditionalDistribution" )
        DERIVES(Mixture)
        .constructor()
        .constructor<Distribution,Distribution>()
        METHOD_GET_SET(ConditionalDistribution, ConditionedDistribution)
        METHOD_GET_SET(ConditionalDistribution, ConditioningDistribution)
    ;
#endif
    class_<RandomMixture>( "RandomMixture" )
        DERIVES(DistributionImplementation)
        .constructor<DistributionCollection,NumericalScalar>()
        .constructor<DistributionCollection,NumericalPoint,NumericalScalar>()
        METHOD_GET_SET(RandomMixture, DistributionCollection)
        METHOD_GET_SET(RandomMixture, Constant)
    ;
    
    
    class_<UsualDistribution>( "UsualDistribution" )
        DERIVES(DistributionImplementation)
        .constructor<OT::String>()    
    ;
    class_<ContinuousDistribution>( "ContinuousDistribution" )
        DERIVES(UsualDistribution)
        .constructor<OT::String>()   
    ;
    // TODO: other ContinuousDistribution
    
    class_<Distribution>( "Distribution" )
        SHOW(Distribution)
    ;
    
    // {{{ Copula
    class_<CopulaImplementation>( "CopulaImplementation" )
        DERIVES(ContinuousDistribution)
        .constructor<OT::String>()    
    ;
    class_<ComposedCopula>( "ComposedCopula" )
        DERIVES(CopulaImplementation)
        .constructor()
        .constructor<CopulaCollection>()  
        METHOD_GET_SET(ComposedCopula, CopulaCollection )
    ;
    // class_<FarlieGumbelMorgensternCopula>( "FarlieGumbelMorgensternCopula" )
    //     DERIVES(CopulaImplementation)
    //     .constructor()
    //     .constructor<NumericalScalar>()
    // ;
    class_<IndependentCopula>( "IndependentCopula" )
        DERIVES(IndependentCopula)
        .constructor<UnsignedLong>()   
    ;
    class_<MinCopula>( "MinCopula" )
        DERIVES(IndependentCopula)
        .constructor<UnsignedLong>()   
    ;
    class_<NormalCopula>( "NormalCopula" )
        DERIVES(CopulaImplementation)
        .constructor<UnsignedLong>("", &ROpenTurns::valid_0_or_1_int )
        .constructor<CorrelationMatrix>( "", &ROpenTurns::valid_1_CorrelationMatrix )
    ;
    class_<ArchimedeanCopula>( "ArchimedeanCopula" )
        DERIVES(CopulaImplementation)
        .constructor<OT::String>("", &ROpenTurns::valid_0_or_1_string )
    ;    
    class_<SklarCopula>( "SklarCopula" )
        DERIVES(CopulaImplementation)
        .constructor()
        .constructor<Distribution>()
    ;
    class_<Copula>( "Copula" )
        DERIVES(Distribution)
        .constructor<Distribution>()
        .constructor<DistributionImplementation,OT::String>()
    ;
    // }}}      
        
    // {{{ DiscreteDistribution
    class_<DiscreteDistribution>( "DiscreteDistribution" )
        DERIVES(UsualDistribution)
        .constructor<OT::String>()   
    ;
    class_<Bernoulli>( "Bernoulli" )
        DERIVES(DiscreteDistribution)
        .constructor()
        .constructor<NumericalScalar>()
        METHOD_GET_SET(Bernoulli, P )
    ;
    class_<Binomial>("Binomial")
        DERIVES(DiscreteDistribution)
        .constructor()
        .constructor<UnsignedLong,NumericalScalar>()
    ;
    // }}}
    
    
    class_<DistributionCollection>( "DistributionCollection" )
        .constructor()
        // .constructor<Rcpp::List>()
        SHOW(DistributionCollection) 
    ;    
    class_<CopulaCollection>( "CopulaCollection" )
        .constructor()
        // .constructor<Rcpp::List>()
        SHOW(CopulaCollection) 
    ;    
    
    
}

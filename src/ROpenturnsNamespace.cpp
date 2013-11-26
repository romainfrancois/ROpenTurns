// :folding=explicit:
#include "ROpenTurns.h"
    
using namespace Rcpp ;
using namespace OT ;

namespace ROpenTurns{

    CorrelationMatrix* NormalCopula_GetCorrelationFromSpearmanCorrelation( object<CorrelationMatrix> x ){
        return new CorrelationMatrix( NormalCopula::GetCorrelationFromSpearmanCorrelation( *x ) ) ;    
    }
    CorrelationMatrix* NormalCopula_GetCorrelationFromKendallCorrelation( object<CorrelationMatrix> x ){
        return new CorrelationMatrix( NormalCopula::GetCorrelationFromKendallCorrelation( *x ) ) ;    
    }
    
    
    void Beta_setMu( Beta* obj, NumericalScalar mu ){ obj->setMuSigma( mu, obj->getSigma() ) ; }
    void Beta_setSigma( Beta* obj, NumericalScalar sigma ){ obj->setMuSigma( obj->getMu(), sigma ) ; }
    
    void LogNormal_setMu( LogNormal* obj, NumericalScalar mu ){ obj->setMuSigma( mu, obj->getSigma() ) ; }
    void LogNormal_setSigma( LogNormal* obj, NumericalScalar sigma ){ obj->setMuSigma( obj->getMu(), sigma ) ; }
    
    // ComposedDistribution* new_ComposedDistribution_DistributionCollection( SEXP data ){
    //     if( TYPEOF(data) == VECSXP ){
    //         Rcpp::List values(data) ;
    //         DistributionCollection coll( values ) ;
    //         ComposedDistribution* result = new ComposedDistribution( coll.collection ) ;
    //         if( values.hasAttribute( "names" ) ){
    //             Rcpp::CharacterVector names = values.names() ;
    //             int n = names.size() ;
    //             Collection<String> description( n ) ;
    //             for( int i=0; i<n; i++){
    //                 description[i] = names[i] ;
    //             }
    //             result->setDescription( Description( description ) ) ;
    //         }
    //         return result ;
    //     } else {
    //         /* assuming a ComposedDistribution Object */
    //         DistributionCollection* coll = internal::as_module_object<DistributionCollection>( data );
    //         return new ComposedDistribution( coll->collection ) ;
    //     }
    // }
    // ComposedDistribution* new_ComposedDistribution_DistributionCollection_Copula( SEXP data, const CopulaImplementation& copula ){
    //     ComposedDistribution* result = new_ComposedDistribution_DistributionCollection( data ) ;
    //     result->setCopula( Copula( copula ) ) ;
    //     return result ;
    // }
    RandomVector* new_RandomVector( SEXP data ){
        /* assuming DistributionImplementation for now */
        DistributionImplementation* dist_impl = internal::as_module_object<DistributionImplementation>( data ) ;
        return new RandomVector( Distribution( *dist_impl ) ) ;        
    }
    RandomVector* new_RandomVector_2( SEXP fun, SEXP data ){
        /* assuming DistributionImplementation for now */
        RandomVector* antecedent = internal::as_module_object<RandomVector>( data ) ;
        NumericalMathFunction* pfun = internal::as_module_object<NumericalMathFunction>( fun ) ;
        return new RandomVector( *pfun, *antecedent ) ;        
    }
    
    NumericalMathFunction* asNumericalMathFunction( Rcpp::Function fun, UnsignedLong inputDimension, UnsignedLong outputDimension ){
        NumericalMathFunctionImplementation impl( 
            new RNumericalMathEvaluationImplementation( fun, inputDimension, outputDimension ),
            new NoNumericalMathGradientImplementation(), 
            new NoNumericalMathHessianImplementation()
        ) ;
        return new NumericalMathFunction(impl); 
    }
    
    NumericMatrix NumericalSample_as_Matrix(const NumericalSample& sample){
        int nc = sample.getDimension(), nr = sample.getSize() ;
        NumericMatrix res( sample.getSize(), sample.getDimension() ) ;
        double* pres = res.begin() ;
        NumericalSampleImplementation::const_iterator it = sample.getImplementation()->begin() ;
        for( int i=0; i<nr; i++){
            NSI_const_point current = *it ;
            for( int j=0; j<nc; j++, pres++, it++){
                *pres = current[j] ;
            }
        }
        return res ;
    }
    
    Event* Compare___RandomVector___double( const RandomVector& vec, double threshold, std::string op ){
        ComparisonOperatorImplementation* comp ;
        if( !op.compare( ">" ) ){
            comp = new Greater ;
        } else if( !op.compare( "<" ) ){
            comp = new Less ;    
        } else if( !op.compare( ">="  ) ){
            comp = new GreaterOrEqual() ;    
        } else if( !op.compare( "<=" ) ){
            comp = new LessOrEqual ;    
        } else {
            comp = new Equal ;    
        }
        
        return new Event( vec, *comp, threshold ) ;
    }
     
    NumericalSample NumericalSample__getMarginal( NumericalSample* sample, IntegerVector indices ){
        Indices ind( indices.begin(), indices.end() ) ;
        return sample->getMarginal( ind );
    }
                
    HistoryStrategy* new_HistoryStrategy( SEXP obj ){
        ROT_INIT_DYNAMIC_CAST(HistoryStrategyImplementation)
        ROT_DYNAMIC_CAST(Compact)
        ROT_DYNAMIC_CAST(Full)
        ROT_DYNAMIC_CAST(Last)
        ROT_DYNAMIC_CAST(Null)
        return new HistoryStrategy( *ptr ) ;
    }
    
    RootStrategy* new_RootStrategy( SEXP obj ){
        ROT_INIT_DYNAMIC_CAST(RootStrategyImplementation)
        ROT_DYNAMIC_CAST(MediumSafe)
        ROT_DYNAMIC_CAST(RiskyAndFast)
        ROT_DYNAMIC_CAST(SafeAndSlow)
        return new RootStrategy( *ptr );
    }
    
    SamplingStrategy* new_SamplingStrategy( SEXP obj ){
        ROT_INIT_DYNAMIC_CAST(SamplingStrategyImplementation)
        ROT_DYNAMIC_CAST(OrthogonalDirection)
        ROT_DYNAMIC_CAST(RandomDirection)
        return new SamplingStrategy( *ptr );
    }
    
    SimulationResult* new_SimulationResult( SEXP obj ){
        ROT_INIT_DYNAMIC_CAST(SimulationResultImplementation)
        ROT_DYNAMIC_CAST(QuasiMonteCarloResult)
        return new SimulationResult( *ptr );
    }
    
    Experiment* new_Experiment( SEXP obj, OT::String name){
        ROT_INIT_DYNAMIC_CAST(ExperimentImplementation)
        ROT_DYNAMIC_CAST(StratifiedExperiment)
        ROT_DYNAMIC_CAST(WeightedExperiment)
        return new Experiment( *ptr, name ) ;
    }
    NearestPointAlgorithm* new_NearestPointAlgorithm( SEXP obj ){
        ROT_INIT_DYNAMIC_CAST(NearestPointAlgorithmImplementation)
        ROT_DYNAMIC_CAST(AbdoRackwitz)
        ROT_DYNAMIC_CAST(Cobyla)
        ROT_DYNAMIC_CAST(SQP)
        return new NearestPointAlgorithm( *ptr ) ;
    }
    
    Solver* new_Solver( SEXP obj ){
        ROT_INIT_DYNAMIC_CAST(SolverImplementation)
        ROT_DYNAMIC_CAST(Bisection)
        ROT_DYNAMIC_CAST(Brent)
        ROT_DYNAMIC_CAST(Secant)
        return new Solver( *ptr ) ;
    }
    
    Description* new_Description( SEXP obj){
        if( TYPEOF(obj) == REALSXP | TYPEOF(obj) == INTSXP ){
            return new Description( as<int>( obj ) ) ;    
        }
        if( TYPEOF(obj) == STRSXP ){
            CharacterVector vec(obj) ;
            return new Description( Collection<OT::String>( vec.begin(), vec.end( ) ) );
        }
    }
    
    
} // namespace ROpenTurns


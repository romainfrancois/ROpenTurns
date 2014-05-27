#ifndef ROPENTURNS_ROPENTURNS_H
#define ROPENTURNS_ROPENTURNS_H

#include <Rcpp.h>

/* otherwise include Log.hxx bombs */
#undef ERROR
#undef WARN

#define ROT_DEBUG(OBJ) Rprintf( "%s\n", OBJ.__repr__().c_str() )
#define ROT_GET_CLASS(OBJ) as<std::string>( Rf_getAttrib( obj, R_ClassSymbol ) ) 
#define ROT_INIT_DYNAMIC_CAST(CLASS) std::string cl = as<std::string>( Rf_getAttrib( obj, R_ClassSymbol ) ); CLASS* ptr = 0;
#define ROT_DYNAMIC_CAST(CLASS) if( cl == "Rcpp_" # CLASS ){ ptr = internal::as_module_object< CLASS >( obj ) ; }

// some macro helpers
#define DERIVES(CLASS)  .derives<CLASS>( #CLASS )
#define METHOD(CLASS,METHOD) .method( #METHOD, &CLASS::METHOD )
#define SHOW(CLASS)          .method( "show", &ROpenTurns::show<CLASS> )
#define MATRIX_GET_SET(CLASS)                        \
    .method( "get", &ROpenTurns::Matrix_get<CLASS> ) \
    .method( "set", &ROpenTurns::Matrix_set<CLASS> )

#define METHOD_GET_SET(CLASS,WHAT)      \
    METHOD( CLASS, get ## WHAT ) \
    METHOD( CLASS, set ## WHAT )

#include <openturns/OT.hxx>

// #include "DistributionCollection.h"
#include "RNumericalMathFunctionEvaluation.h"

using namespace OT ;
using namespace Rcpp;

namespace ROpenTurns{
    
    // TODO: promote to Rcpp and handle inheritance
    class Valid_1 {
    public:
        Valid_1( const char* cl_ ) : cl("Rcpp_"){ cl += cl_ ; }
        
        inline bool operator()(SEXP* args, int n){
            return (n==1) && Rf_inherits( args[0], cl.c_str() );  
        }
        
    private:
        std::string cl ;
    } ;
    
    template <typename T>
    void show( T* obj ){
        Rprintf( "%s\n", obj->__repr__().c_str() ) ;   
    }
    
    template <typename T>
    void setName( T* obj, std::string name ){
        obj->setName( name ) ;
    }
    
    template <typename T>
    std::string getName( T* obj ){
        return obj->getName( ) ;
    }
    
    template <typename T>
    T as_throughCollection( SEXP obj ){ 
        NumericVector vec(obj); 
        Collection<NumericalScalar> coll( vec.begin(), vec.end() ) ;
        return T(coll);     
    }
    
    template <typename T>
    NumericalScalar Matrix_get( T* matrix, int i, int j ){
        return (*matrix)( i,j ) ;
    }
    template <typename T>
    void Matrix_set( T* matrix, int i, int j, NumericalScalar value ){
        (*matrix)( i,j ) = value ;
    }
    template <typename T>
    NumericMatrix as_R_matrix( const T& obj ){
        int nr = obj.getNbRows() , nc =  obj.getNbColumns() ;
        NumericMatrix res( nr , nc ) ;
        for( int i=0; i<nr; i++){
            for( int j=0; j<nc; j++){
                res(i,j) = obj(i,j) ;
            }
        }
        return res ;
    }
    CorrelationMatrix* NormalCopula_GetCorrelationFromSpearmanCorrelation( object<CorrelationMatrix> x ) ;
    CorrelationMatrix* NormalCopula_GetCorrelationFromKendallCorrelation( object<CorrelationMatrix> x ) ;
   
    void Beta_setMu( Beta* obj, NumericalScalar mu ) ;
    void Beta_setSigma( Beta* obj, NumericalScalar sigma ) ;
    
    void LogNormal_setMu( LogNormal* obj, NumericalScalar mu ) ;
    void LogNormal_setSigma( LogNormal* obj, NumericalScalar sigma ) ;
    
    // ComposedDistribution* new_ComposedDistribution_DistributionCollection( SEXP data ) ;
    // ComposedDistribution* new_ComposedDistribution_DistributionCollection_Copula( SEXP data, const CopulaImplementation& copula ) ;
    RandomVector* new_RandomVector( SEXP data ) ;
    RandomVector* new_RandomVector_2( SEXP fun, SEXP data ) ;
    
    NumericalMathFunction* asNumericalMathFunction( Rcpp::Function fun, UnsignedLong inputDimension, UnsignedLong outputDimension ) ;
    
    NumericMatrix NumericalSample_as_Matrix(const NumericalSample& sample) ;
    
    Event* Compare___RandomVector___double( const RandomVector& vec, double threshold, std::string op ) ;
    
    NumericalSample NumericalSample__getMarginal( NumericalSample* sample, IntegerVector indices ) ;
                
    HistoryStrategy* new_HistoryStrategy( SEXP obj ) ;
    RootStrategy* new_RootStrategy( SEXP obj ) ;
    SamplingStrategy* new_SamplingStrategy( SEXP obj ) ;
    Description* new_Description( SEXP obj) ;
    SimulationResult* new_SimulationResult( SEXP obj ) ;
    Experiment* new_Experiment( SEXP obj, OT::String name) ;
    NearestPointAlgorithm* new_NearestPointAlgorithm( SEXP obj ) ;
    Solver* new_Solver( SEXP obj ) ;
    
    typedef Collection<NumericalPointWithDescription> NumericalPointWithDescriptionCollection ;
    typedef Collection<NumericalPoint> NumericalPointCollection ;
    typedef Collection<Distribution> DistributionCollection ;
    typedef Collection<Copula> CopulaCollection ;
}

#include <openturns/NumericalPoint.hxx>
#include <openturns/CorrelationMatrix.hxx>
#include <openturns/OTDistribution.hxx>
#include <openturns/Interval.hxx>
#include <openturns/OTUncertainty.hxx>

RCPP_EXPOSED_ENUM_NODECL(OT::Arcsine::ParameterSet)
RCPP_EXPOSED_ENUM_NODECL(OT::Beta::ParameterSet)
RCPP_EXPOSED_ENUM_NODECL(OT::Epanechnikov::ParameterSet)
RCPP_EXPOSED_ENUM_NODECL(OT::Gamma::ParameterSet)
RCPP_EXPOSED_ENUM_NODECL(OT::Gumbel::ParameterSet)
RCPP_EXPOSED_ENUM_NODECL(OT::LogNormal::ParameterSet)
RCPP_EXPOSED_ENUM_NODECL(OT::TracyWidomGOE::ParameterSet)
RCPP_EXPOSED_ENUM_NODECL(OT::TracyWidomGSE::ParameterSet)
RCPP_EXPOSED_ENUM_NODECL(OT::TracyWidomGUE::ParameterSet)
RCPP_EXPOSED_ENUM_NODECL(OT::Weibull::ParameterSet)

RCPP_EXPOSED_CLASS_NODECL(OT::Matrix)
RCPP_EXPOSED_CLASS_NODECL(OT::CorrelationMatrix)
RCPP_EXPOSED_CLASS_NODECL(OT::CovarianceMatrix)
RCPP_EXPOSED_CLASS_NODECL(OT::SquareMatrix)

RCPP_EXPOSED_CLASS_NODECL(OT::Interval)
RCPP_EXPOSED_CLASS_NODECL(OT::Indices)

RCPP_EXPOSED_CLASS_NODECL(OT::Description)
RCPP_EXPOSED_CLASS_NODECL(OT::NumericalPoint)
RCPP_EXPOSED_CLASS_NODECL(OT::NumericalPointWithDescription)
RCPP_EXPOSED_CLASS_NODECL(OT::NumericalSample)
RCPP_EXPOSED_CLASS_NODECL(OT::RandomVector)
RCPP_EXPOSED_CLASS_NODECL(OT::NumericalMathFunction)
RCPP_EXPOSED_CLASS_NODECL(OT::Event)
RCPP_EXPOSED_CLASS_NODECL(OT::HistoryStrategyImplementation)
RCPP_EXPOSED_CLASS_NODECL(OT::HistoryStrategy)

RCPP_EXPOSED_CLASS_NODECL(OT::RootStrategyImplementation)
RCPP_EXPOSED_CLASS_NODECL(OT::MediumSafe)
RCPP_EXPOSED_CLASS_NODECL(OT::RiskyAndFast)
RCPP_EXPOSED_CLASS_NODECL(OT::SafeAndSlow)
RCPP_EXPOSED_CLASS_NODECL(OT::RootStrategy)

RCPP_EXPOSED_CLASS_NODECL(OT::SamplingStrategyImplementation)
RCPP_EXPOSED_CLASS_NODECL(OT::OrthogonalDirection)
RCPP_EXPOSED_CLASS_NODECL(OT::RandomDirection)
RCPP_EXPOSED_CLASS_NODECL(OT::SamplingStrategy)

RCPP_EXPOSED_CLASS_NODECL(OT::DirectionalSampling)
RCPP_EXPOSED_CLASS_NODECL(OT::ImportanceSampling)
RCPP_EXPOSED_CLASS_NODECL(OT::LHS)

RCPP_EXPOSED_CLASS_NODECL(OT::SimulationResultImplementation)
RCPP_EXPOSED_CLASS_NODECL(OT::QuasiMonteCarloResult)
RCPP_EXPOSED_CLASS_NODECL(OT::SimulationResult)

RCPP_EXPOSED_CLASS_NODECL(OT::ExperimentImplementation)
RCPP_EXPOSED_CLASS_NODECL(OT::StratifiedExperiment)
RCPP_EXPOSED_CLASS_NODECL(OT::WeightedExperiment)

RCPP_EXPOSED_CLASS_NODECL(OT::AnalyticalResult)
RCPP_EXPOSED_CLASS_NODECL(OT::FORMResult)
RCPP_EXPOSED_CLASS_NODECL(OT::SORMResult)
RCPP_EXPOSED_CLASS_NODECL(OT::Analytical)

RCPP_EXPOSED_CLASS_NODECL(OT::NearestPointAlgorithmImplementation)
RCPP_EXPOSED_CLASS_NODECL(OT::NearestPointAlgorithmImplementationResult)
RCPP_EXPOSED_CLASS_NODECL(OT::AbdoRackwitzSpecificParameters)
RCPP_EXPOSED_CLASS_NODECL(OT::AbdoRackwitz)
RCPP_EXPOSED_CLASS_NODECL(OT::CobylaSpecificParameters)
RCPP_EXPOSED_CLASS_NODECL(OT::Cobyla)
RCPP_EXPOSED_CLASS_NODECL(OT::SQPSpecificParameters)
RCPP_EXPOSED_CLASS_NODECL(OT::SQP)
RCPP_EXPOSED_CLASS_NODECL(OT::NearestPointAlgorithm)

RCPP_EXPOSED_CLASS_NODECL(OT::SolverImplementation)
RCPP_EXPOSED_CLASS_NODECL(OT::Bisection)
RCPP_EXPOSED_CLASS_NODECL(OT::Brent)
RCPP_EXPOSED_CLASS_NODECL(OT::Secant)
RCPP_EXPOSED_CLASS_NODECL(OT::Solver)

RCPP_EXPOSED_CLASS_NODECL(OT::NumericalPointWithDescriptionCollection)
RCPP_EXPOSED_CLASS_NODECL(OT::NumericalPointCollection)
    
RCPP_EXPOSED_CLASS_NODECL(OT::DistributionImplementation)
RCPP_EXPOSED_CLASS_NODECL(OT::ComposedDistribution)
RCPP_EXPOSED_CLASS_NODECL(OT::Mixture)
#ifdef OPENTURNS_CONDITIONALDISTRIBUTION_HXX
RCPP_EXPOSED_CLASS_NODECL(OT::ConditionalDistribution)
#endif
RCPP_EXPOSED_CLASS_NODECL(OT::RandomMixture)
RCPP_EXPOSED_CLASS_NODECL(OT::UsualDistribution)
RCPP_EXPOSED_CLASS_NODECL(OT::ContinuousDistribution)
RCPP_EXPOSED_CLASS_NODECL(OT::CopulaImplementation)
RCPP_EXPOSED_CLASS_NODECL(OT::ComposedCopula)
// RCPP_EXPOSED_CLASS_NODECL(OT::FarlieGumbelMorgensternCopula)
RCPP_EXPOSED_CLASS_NODECL(OT::IndependentCopula)
RCPP_EXPOSED_CLASS_NODECL(OT::MinCopula)
RCPP_EXPOSED_CLASS_NODECL(OT::NormalCopula)
RCPP_EXPOSED_CLASS_NODECL(OT::ArchimedeanCopula)
RCPP_EXPOSED_CLASS_NODECL(OT::DiscreteDistribution)
RCPP_EXPOSED_CLASS_NODECL(OT::SklarCopula)
RCPP_EXPOSED_CLASS_NODECL(OT::Copula)

RCPP_EXPOSED_CLASS_NODECL(OT::Bernoulli)
RCPP_EXPOSED_CLASS_NODECL(OT::Binomial)


RCPP_EXPOSED_CLASS_NODECL(OT::CopulaCollection)

RCPP_EXPOSED_CLASS_NODECL(OT::Distribution)
RCPP_EXPOSED_CLASS_NODECL(OT::DistributionCollection)


#endif

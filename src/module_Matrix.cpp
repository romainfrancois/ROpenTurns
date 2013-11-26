// :folding=explicit:
#include "ROpenTurns.h"
    
    
RCPP_MODULE(Matrix){

    class_<OT::Matrix>( "Matrix" )
        .constructor()
        .constructor<UnsignedLong,UnsignedLong>()
        SHOW(OT::Matrix)
        MATRIX_GET_SET(OT::Matrix)
        METHOD(OT::Matrix,clean)
    ;
    
    class_<CorrelationMatrix>( "CorrelationMatrix" )
        .default_constructor()
        .constructor<UnsignedLong>()
        SHOW(CorrelationMatrix)
        MATRIX_GET_SET(CorrelationMatrix)
        METHOD(CorrelationMatrix, transpose)
    ;
    converter( "CorrelationMatrix", "matrix", &ROpenTurns::as_R_matrix<CorrelationMatrix> ) ;
   
    class_<CovarianceMatrix>( "CovarianceMatrix" )
        .constructor()
        .constructor<UnsignedLong>()
        SHOW(CovarianceMatrix)
        MATRIX_GET_SET(CovarianceMatrix)
        METHOD(CovarianceMatrix, transpose)
    ;
    converter( "CovarianceMatrix", "matrix", &ROpenTurns::as_R_matrix<CovarianceMatrix> ) ;

    class_<SquareMatrix>( "SquareMatrix" )
        .constructor()
        .constructor<UnsignedLong>()
        SHOW(SquareMatrix)
        MATRIX_GET_SET(SquareMatrix)
        METHOD(SquareMatrix, transpose)
    ;
    converter( "SquareMatrix", "matrix", &ROpenTurns::as_R_matrix<SquareMatrix> ) ;

}

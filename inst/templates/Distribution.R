   
generate_distribution_binding <- function( CLASS ){
    
    # TODO: MuSigma
    
    file <- file.path( "~/svn/openturns-0.15/lib/src/Uncertainty/Distribution", sprintf( "%s.hxx", CLASS )  )
    contents <- readLines( file )
    
    setters_rx <- "^.*void set(.*)[(]const NumericalScalar .*[)].*$"
    setters    <- grep( setters_rx, contents, value = TRUE )
    
    txt <- '   
    class_< CLASS >( "CLASS" )
        .default_constructor()'
    
    if( length(res <- grep("Parameters constructor", contents ) ) ){     
        for( i in 1:length(res)){
            ctor <- sub( "[)].*", "", paste( contents[ seq( res[i] + 1, length(contents) ) ], collapse = "" ) )
            ctor <- sub ("^.*[(]", "", ctor )
            ctor <- gsub( "[[:space:]]*const", "", ctor )
            chunks <- strsplit( ctor, "," )[[1]]
            chunks <- gsub( "=.*", "", chunks )
            chunks <- gsub( "^[[:space:]]+", "", chunks )
            chunks <- gsub( "[[:space:]]+.*", "", chunks )
            
            if( chunks[ length( chunks) ] == "ParameterSet" ){
                txt <- sprintf( "%s\n        .constructor<%s>()", txt, paste( head( chunks, -1 ), collapse = "," ) )
                txt <- sprintf( "%s\n        .constructor<%s, %s::ParameterSet>()", txt, paste( head( chunks, -1 ), collapse = "," ), CLASS )
            } else {
                txt <- sprintf( "%s\n        .constructor<%s>()", txt, paste( chunks, collapse = "," ) ) 
            }
        }
    }
    txt <- sprintf( "%s\n%s", txt,     '
        .method( "show", &ROpenTurns::show<CLASS> )                    
        .method( "clone", &CLASS::clone )                              
        .method( "getStandardDeviation", &CLASS::getStandardDeviation )
        .method( "getSkewness", &CLASS::getSkewness )                  
        .method( "getKurtosis", &CLASS::getKurtosis )                  
        // .method( "getStandardMoment", &CLASS::getStandardMoment )
        // .method( "getRealization", &CLASS::getRealization )            
    ' )
    txt <- gsub( "CLASS", CLASS, txt) 
    
    param_upper_case <- gsub( setters_rx, "\\1", setters )
    param_upper_case <- param_upper_case[ ! param_upper_case %in% c("MuSigma", "AB" ) ]
    param <- param_upper_case
    substr( param, 1, 1 ) <- casefold( substr( param, 1, 1) )
    
    
    properties <- gsub( "CLASS", CLASS, sprintf( '        .property( "%s", &CLASS::get%s, &CLASS::set%s ) ', param, param_upper_case, param_upper_case ) ) 
    
    txt <- sprintf( "%s\n%s\n ;", txt, paste( properties, collapse = "\n" ) )
    txt
}

getDistributions <- function(){
    distribs <- readLines( pipe( 'grep  -l ": public.*Distribution" ~/svn/openturns-0.15/lib/src/Uncertainty/Distribution/*.hxx' ) )
    distribs <- sub( ".hxx$", "", basename(distribs) )
    
    # TODO: deal with Factory
    distribs <- grep( "Factory", distribs, value = TRUE, invert = TRUE )
    distribs <- grep( "Histogram", distribs, value = TRUE, invert = TRUE )
    # TODO: deal with TruncatedDistribution
    distribs <- grep( "^TruncatedDistribution$", distribs, value = TRUE, invert = TRUE )
    distribs
}

generateEnum <- function(CLASS){
   file <- file.path( "~/svn/openturns-0.15/lib/src/Uncertainty/Distribution", sprintf( "%s.hxx", CLASS )  )
   contents <- readLines( file )
   
   res <- if( any( grepl( "enum ParameterSet", contents ) ) ){
       sprintf( "namespace Rcpp{ template <> %s::ParameterSet as( SEXP obj ) {return %s::ParameterSet( as<int>( obj ) ) ; } }", CLASS, CLASS )
   } else ""
   
}

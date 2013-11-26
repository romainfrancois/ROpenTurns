
loadModule("Matrix", TRUE)
loadModule("Distribution", TRUE)
loadModule("OpenTurns", TRUE)
loadModule("RandomVector", TRUE)
loadModule("Solver", TRUE)
loadModule("SimulationResult", TRUE)
loadModule("AnalyticalResult", TRUE)
loadModule("NearestPointAlgorithm", TRUE)
loadModule("Analytical", TRUE)
loadModule("HistoryStrategy", TRUE)
loadModule("RootStrategy", TRUE)
loadModule("Simulation", TRUE)
loadModule("SimulationStrategy", TRUE)

evalqOnLoad({
    setMethod( "Compare", signature( e1 = RandomVector, e2 = "numeric" ), 
        function( e1, e2 ){
            Compare___RandomVector___double( e1, e2, .Generic )
        }
    ) 
})

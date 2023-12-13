project(Algorithms)

set(HEADER_FILES
        AddTwoIntegersAlgorithm.h
        Utils.h
        AddThreeIntegersAlgorithm.h
        MultiplyTwoIntegersAlgorithmTest.h
)

add_library(Algorithms_lib INTERFACE ${HEADER_FILES})

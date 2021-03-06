ENABLE_TESTING()

set(Boost_USE_STATIC_LIBS ON)
set(BOOST_COMPONENTS unit_test_framework timer system)
SEARCH_FOR_BOOST()

include_directories("${PROJECT_SOURCE_DIR}/src")
include_directories(${Boost_INCLUDE_DIRS})

set(HEADERS XYZarm.h XYZSarm.h Tree30Dof.h SSSarm.h)

macro(addUnitTest name)
  if(${UNIT_TESTS})
    add_executable(${name} ${name}.cpp ${HEADERS})
    target_link_libraries(${name} ${Boost_LIBRARIES} RBDyn)
    PKG_CONFIG_USE_DEPENDENCY(${name} SpaceVecAlg)
    add_test(${name}Unit ${name})
  endif()
endmacro(addUnitTest)

macro(addBenchmark name)
  if(${BENCHMARKS})
    add_executable(${name} ${name}.cpp ${HEADERS})
    target_link_libraries(${name} ${Boost_LIBRARIES} RBDyn)
    PKG_CONFIG_USE_DEPENDENCY(${name} SpaceVecAlg)
  endif()
endmacro(addBenchmark)

addUnitTest("BodyTest")
addUnitTest("JointTest")
addUnitTest("MultiBodyTest")
addUnitTest("AlgoTest")
addUnitTest("JacobianTest")
addUnitTest("DynamicsTest")
addUnitTest("CoMTest")
addUnitTest("MomentumTest")

addBenchmark("JacobianBench")
addBenchmark("DynamicsBench")

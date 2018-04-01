cmake_minimum_required(VERSION 3.2)

project(homework_02 VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

set(TEST_NAME test_main)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(homework_02 main.cpp)
add_executable(${TEST_NAME} test_main.cpp)

add_library(homework_02_lib
	utils.cpp
	a_plus_b.cpp
	localization_problem.cpp
	olympiad.cpp
	reverse_sqrt.cpp
	sulfide_mass.cpp
)

set_target_properties(homework_02 homework_02_lib ${TEST_NAME} PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

set_target_properties(${TEST_NAME} PROPERTIES
  COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
  INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(homework_02 homework_02_lib
)

target_link_libraries(${TEST_NAME}
  ${Boost_LIBRARIES}
  homework_02_lib
)

install(TARGETS homework_02 RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT evgeniyshb@gmail.com)

include (CPack)

enable_testing()

add_test(a_plus_b_valid ${TEST_NAME})
add_test(reverse_sqrt_valid ${TEST_NAME})
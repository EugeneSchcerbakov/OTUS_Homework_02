cmake_minimum_required(VERSION 3.2)

project(homework_02 VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(homework_02 main.cpp)

add_executable(test_a_plus_b test_a_plus_b.cpp)
add_executable(test_localization_problem test_localization_problem.cpp)
add_executable(test_olympiad test_olympiad.cpp)
add_executable(test_reverse_sqrt test_reverse_sqrt.cpp)
add_executable(test_sulfide_mass test_sulfide_mass.cpp)

add_library(homework_02_lib
	utils.cpp
	a_plus_b.cpp
	localization_problem.cpp
	olympiad.cpp
	reverse_sqrt.cpp
	sulfide_mass.cpp
)

set_target_properties(homework_02 homework_02_lib PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

set_target_properties(
	test_a_plus_b
	test_localization_problem
	test_olympiad
	test_reverse_sqrt
	test_sulfide_mass
	PROPERTIES
	COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
	INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(homework_02 homework_02_lib)

target_link_libraries(test_a_plus_b homework_02_lib)
target_link_libraries(test_localization_problem homework_02_lib)
target_link_libraries(test_olympiad homework_02_lib)
target_link_libraries(test_reverse_sqrt homework_02_lib)
target_link_libraries(test_sulfide_mass homework_02_lib)

install(TARGETS homework_02 RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT evgeniyshb@gmail.com)

include (CPack)

enable_testing()

add_test(test test_a_plus_b)
add_test(test test_localization_problem)
add_test(test test_olympiad)
add_test(test test_reverse_sqrt)
add_test(test test_sulfide_mass)
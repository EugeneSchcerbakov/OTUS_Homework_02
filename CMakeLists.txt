cmake_minimum_required(VERSION 3.2)

project(homework_02 VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(homework_02 main.cpp)
add_executable(test_main_cli test_main.cpp)

add_library(homework_02_utils utils.cpp)
add_library(homework_02_a_plus_b a_plus_b.cpp)
add_library(homework_02_localization_problem localization_problem.cpp)
add_library(homework_02_olympiad olympiad.cpp)
add_library(homework_02_reverse_sqrt reverse_sqrt.cpp)
add_library(homework_02_sulfide_mass sulfide_mass.cpp)

set_target_properties(homework_02 test_main_cli PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

set_target_properties(test_main_cli PROPERTIES
  COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
  INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(homework_02
	homework_02_a_plus_b
	homework_02_localization_problem
	homework_02_olympiad
	homework_02_reverse_sqrt
	homework_02_sulfide_mass
)

target_link_libraries(test_main_cli
  ${Boost_LIBRARIES}
  	homework_02_a_plus_b
	homework_02_localization_problem
	homework_02_olympiad
	homework_02_reverse_sqrt
	homework_02_sulfide_mass
)

install(TARGETS homework_02
 RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT evgeniyshb@gmail.com)

include (CPack)

enable_testing()

add_test(a_plus_b_valid test_main_cli)
add_test(reverse_sqrt_valid test_main_cli)
add_test(number_localization_valid test_main_cli)
add_test(sulfide_mass_valid test_main_cli)
add_test(olympiad_valid test_main_cli)
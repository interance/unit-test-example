cmake_minimum_required(VERSION 3.13.5 FATAL_ERROR)
project(unit-test-example CXX)

# -- includes ------------------------------------------------------------------

include(FetchContent)

# -- opt-in to new behavior ----------------------------------------------------

# See https://cmake.org/cmake/help/latest/policy/CMP0135.html
if(POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)
endif()

# -- options -------------------------------------------------------------------

option(BUILD_SHARED_LIBS "Build shared library targets" OFF)

set(SANITIZERS "" CACHE STRING "Selected sanitizers, e.g., 'address,undefined'")

set(CAF_TAG "94cec61" CACHE STRING "The tag of the CAF version to use")

set(CXX_VERSION "17" CACHE STRING "The C++ version to use")

# -- embed CAF -----------------------------------------------------------------

function(get_caf)
  # Fetch CAF from the official repository.
  FetchContent_Declare(
    caf
    GIT_REPOSITORY https://github.com/actor-framework/actor-framework.git
    GIT_TAG        ${CAF_TAG}
    EXCLUDE_FROM_ALL
  )
  # Select the parts of CAF we need.
  set(CAF_ENABLE_NET_MODULE ON)
  set(CAF_ENABLE_EXAMPLES OFF)
  set(CAF_ENABLE_IO_MODULE OFF)
  set(CAF_ENABLE_TESTING OFF)
  set(CAF_ENABLE_TOOLS OFF)
  # Pass along build options.
  set(CAF_CXX_VERSION ${CXX_VERSION})
  set(CAF_SANITIZERS ${SANITIZERS})
  # Build CAF as a sub-project.
  FetchContent_MakeAvailable(caf)
endfunction()
get_caf()

# -- build the examples --------------------------------------------------------

enable_testing()

add_subdirectory(fixtures)
add_subdirectory(log)
add_subdirectory(multi-suites-explicit)
add_subdirectory(multi-suites-generated)
add_subdirectory(outlines)
add_subdirectory(scenarios)
add_subdirectory(sections)
add_subdirectory(simple)

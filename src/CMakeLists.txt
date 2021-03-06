# add definitions, compiler switches, etc.
ADD_DEFINITIONS(-Wall -Wshadow -funroll-loops -march=native)

# Make it possible to #include generated header files for out-of-source builds
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})

ADD_LIBRARY(transcriptomedeconvolution SHARED aux.cpp counts.cpp
  compression_mode.cpp executioninformation.cpp PartialModel.cpp entropy.cpp
  features.cpp mix.cpp verbosity.cpp hierarchical_kmeans.cpp log.cpp io.cpp
  metropolis_hastings.cpp parameters.cpp priors.cpp sampling.cpp target.cpp
  terminal.cpp timer.cpp pdist.cpp)

# ADD_EXECUTABLE(test-log-beta test-log-beta.cpp pdist.cpp)
# ADD_EXECUTABLE(enrich enrich.cpp cli.cpp)
ADD_EXECUTABLE(std main.cpp cli.cpp)
ADD_EXECUTABLE(test_sampling test_sampling.cpp)

ADD_EXECUTABLE(test_gamma_cdf test_gamma_cdf.cpp)
ADD_EXECUTABLE(test_gamma_convolution test_gamma_convolution.cpp)
ADD_EXECUTABLE(test_negative_binomial_convolution test_negative_binomial_convolution.cpp)

TARGET_LINK_LIBRARIES(transcriptomedeconvolution
  m
  -L${Boost_LIBRARY_DIRS}
  ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_LOG_LIBRARY}
  ${Boost_THREAD_LIBRARY}
  ${Boost_REGEX_LIBRARY}
  ${Boost_IOSTREAMS_LIBRARY}
  ${Boost_PROGRAM_OPTIONS_LIBRARY}
  ${Boost_DATE_TIME_LIBRARY}
  ${ARMADILLO_LIBRARIES}
  )

TARGET_LINK_LIBRARIES(std transcriptomedeconvolution)
# TARGET_LINK_LIBRARIES(test-log-beta transcriptomedeconvolution)
TARGET_LINK_LIBRARIES(test_gamma_cdf transcriptomedeconvolution)
TARGET_LINK_LIBRARIES(test_gamma_convolution transcriptomedeconvolution)
TARGET_LINK_LIBRARIES(test_negative_binomial_convolution transcriptomedeconvolution)
TARGET_LINK_LIBRARIES(test_sampling transcriptomedeconvolution)
# TARGET_LINK_LIBRARIES(enrich transcriptomedeconvolution)

IF(GOOGLEPERFTOOLS_FOUND)
  TARGET_LINK_LIBRARIES(std ${PROFILER_LIBRARY} ${TCMALLOC_LIBRARY})
  #   TARGET_LINK_LIBRARIES(enrich ${PROFILER_LIBRARY} ${TCMALLOC_LIBRARY})
ENDIF()

CONFIGURE_FILE(git_config.hpp.in git_config.hpp)
SET_TARGET_PROPERTIES(std PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

# INSTALL(TARGETS enrich DESTINATION bin)
INSTALL(TARGETS std DESTINATION bin)
INSTALL(TARGETS transcriptomedeconvolution DESTINATION lib)

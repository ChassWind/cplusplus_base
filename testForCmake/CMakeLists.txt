set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

aux_source_directory(./ DIR_SRCS)

add_executable(test ${DIR_SRCS})
# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\task-1-4_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\task-1-4_autogen.dir\\ParseCache.txt"
  "task-1-4_autogen"
  )
endif()

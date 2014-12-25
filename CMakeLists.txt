# shared library for user defined objects
set (geosdb_src
    geosdb.cpp
)

add_library(geosdb SHARED ${geosdb_src})
extractDebugInfo("${GENERAL_OUTPUT_DIRECTORY}/plugins" "libgeosdb${CMAKE_SHARED_LIBRARY_SUFFIX}" geosdb)
set_target_properties(geosdb PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${GENERAL_OUTPUT_DIRECTORY}/plugins)
if (APPLE)
  set_target_properties(geosdb PROPERTIES LINK_FLAGS "-undefined dynamic_lookup")
endif (APPLE)

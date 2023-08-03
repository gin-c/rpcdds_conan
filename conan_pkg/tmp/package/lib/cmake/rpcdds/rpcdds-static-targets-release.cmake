#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "rpcdds" for configuration "Release"
set_property(TARGET rpcdds APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(rpcdds PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX;RC"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/librpcdds-1.1.lib"
  )

list(APPEND _cmake_import_check_targets rpcdds )
list(APPEND _cmake_import_check_files_for_rpcdds "${_IMPORT_PREFIX}/lib/librpcdds-1.1.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)

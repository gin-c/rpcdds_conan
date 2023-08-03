set(rpcdds_VERSION 1.1.1)


####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was Config.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

if(MSVC OR MSVC_IDE)
    set_and_check(rpcdds_BIN_DIR "${PACKAGE_PREFIX_DIR}/bin")
endif()
set_and_check(rpcdds_INCLUDE_DIR "${PACKAGE_PREFIX_DIR}/include")
set_and_check(rpcdds_LIB_DIR "${PACKAGE_PREFIX_DIR}/lib")

if(NOT fastrtps_FOUND)
    find_package(fastcdr REQUIRED)
endif()


if(NOT DEFINED BUILD_SHARED_LIBS OR BUILD_SHARED_LIBS)
    include(${CMAKE_CURRENT_LIST_DIR}/rpcdds-dynamic-targets.cmake OPTIONAL RESULT_VARIABLE DYNAMIC_TARGET_FILE)
    # fallback to static linking if dynamic target is missing
    if( NOT DYNAMIC_TARGET_FILE )
        include(${CMAKE_CURRENT_LIST_DIR}/rpcdds-static-targets.cmake)
    endif()
else()
    include(${CMAKE_CURRENT_LIST_DIR}/rpcdds-static-targets.cmake)
endif()


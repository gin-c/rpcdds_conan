cmake_minimum_required(VERSION 2.8.12)

if(NOT CMAKE_VERSION VERSION_LESS 3.0)
	cmake_policy(SET CMP0048 NEW)
endif()

project("RTPSAIOpenApi")

# Find requirements
if(NOT fastcdr_FOUND)
	find_package(fastcdr REQUIRED)
endif()

if(NOT fastrtps_FOUND)
	find_package(fastdds REQUIRED)
endif()

if(NOT rpcdds_FOUND)
	find_package(rpcdds REQUIRED)
endif()

# Set C++11
include(CheckCXXCompilerFlag)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANG OR
		CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	check_cxx_compiler_flag(--std=c++11 SUPPORTS_CXX11)
	if(SUPPORTS_CXX11)
		add_compile_options(--std=c++11)
	else()
		message(FATAL_ERROR "Compiler doesn't support C++11")
	endif()
endif()

set(RTPSAIOPENAPI_COMMON_SOURCES_CXX AIOpenApiTopicsPlugin.cxx AIOpenApiTopics.cxx AIOpenApiDDSProtocol.cxx AIOpenApiDDSAsyncSupport.cxx)
message(STATUS "Configuring RTPSAIOpenApi libraries...")
set(RTPSAIOPENAPI_SOURCES_CXX AIOpenApi.cxx)
set(RTPSAIOPENAPICLIENT_SOURCES_CXX AIOpenApiProxy.cxx)
set(RTPSAIOPENAPISERVER_SOURCES_CXX AIOpenApiServer.cxx)

add_library(AIOpenApi STATIC ${RTPSAIOPENAPI_COMMON_SOURCES_CXX} ${RTPSAIOPENAPI_SOURCES_CXX})
target_compile_definitions(AIOpenApi PRIVATE BOOST_ALL_DYN_LINK EPROSIMA_ALL_DYN_LINK)
target_include_directories(AIOpenApi PUBLIC ${rpcdds_INCLUDE_DIR} ${Boost_INCLUDE_DIR})
target_link_libraries(AIOpenApi fastcdr fastrtps)

add_library(AIOpenApiClient STATIC ${RTPSAIOPENAPICLIENT_SOURCES_CXX})
target_compile_definitions(AIOpenApiClient PRIVATE BOOST_ALL_DYN_LINK EPROSIMA_ALL_DYN_LINK)
target_include_directories(AIOpenApiClient PUBLIC ${rpcdds_INCLUDE_DIR} ${Boost_INCLUDE_DIR})
target_link_libraries(AIOpenApiClient AIOpenApi rpcdds fastcdr fastrtps  ${Boost_LIBRARIES})

add_library(AIOpenApiServer STATIC ${RTPSAIOPENAPISERVER_SOURCES_CXX})
target_compile_definitions(AIOpenApiServer PRIVATE BOOST_ALL_DYN_LINK EPROSIMA_ALL_DYN_LINK)
target_include_directories(AIOpenApiServer PUBLIC ${rpcdds_INCLUDE_DIR} ${Boost_INCLUDE_DIR})
target_link_libraries(AIOpenApiServer AIOpenApi rpcdds fastcdr fastrtps ${Boost_LIBRARIES})

message(STATUS "Configuring RTPSAIOpenApi Server and Client examples...")
set(RTPSAIOPENAPISERVEREXAMPLE_SOURCES_CXX AIOpenApiServerExample.cxx AIOpenApiServerImplExample.cxx)
set(RTPSAIOPENAPICLIENTEXAMPLE_SOURCES_CXX AIOpenApiClientExample.cxx AIOpenApiProxyImplExample.cxx)

add_executable(AIOpenApiServerExample ${RTPSAIOPENAPISERVEREXAMPLE_SOURCES_CXX})
target_include_directories(AIOpenApiServerExample PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(AIOpenApiServerExample AIOpenApiServer)

install(TARGETS AIOpenApiServerExample AIOpenApiServer
		RUNTIME DESTINATION examples/ai_openapi/${BIN_INSTALL_DIR})

add_executable(AIOpenApiClientExample ${RTPSAIOPENAPICLIENTEXAMPLE_SOURCES_CXX})
target_include_directories(AIOpenApiClientExample PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(AIOpenApiClientExample AIOpenApiClient)

install(TARGETS AIOpenApiClientExample AIOpenApiClient
		RUNTIME DESTINATION examples/ai_openapi/${BIN_INSTALL_DIR})

install(DIRECTORY .
		DESTINATION include/ai_openapi
		COMPONENT sources
		FILES_MATCHING
		PATTERN "*.h"
		PATTERN "*.hpp"
		)
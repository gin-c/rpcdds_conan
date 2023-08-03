cmake_minimum_required(VERSION 2.8.12)

if(NOT CMAKE_VERSION VERSION_LESS 3.0)
	cmake_policy(SET CMP0048 NEW)
endif()

project("RTPSUCar")

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

set(RTPSUCAR_COMMON_SOURCES_CXX UCarTopicsPlugin.cxx UCarTopics.cxx UCarDDSProtocol.cxx UCarDDSAsyncSupport.cxx)
message(STATUS "Configuring RTPSUCar libraries...")
set(RTPSUCAR_SOURCES_CXX UCar.cxx)
set(RTPSUCARCLIENT_SOURCES_CXX UCarProxy.cxx)
set(RTPSUCARSERVER_SOURCES_CXX UCarServer.cxx)

add_library(UCar STATIC ${RTPSUCAR_COMMON_SOURCES_CXX} ${RTPSUCAR_SOURCES_CXX})
target_compile_definitions(UCar PRIVATE BOOST_ALL_DYN_LINK EPROSIMA_ALL_DYN_LINK)
target_include_directories(UCar PUBLIC ${rpcdds_INCLUDE_DIR} ${Boost_INCLUDE_DIR})

add_library(UCarClient STATIC ${RTPSUCARCLIENT_SOURCES_CXX})
target_compile_definitions(UCarClient PRIVATE BOOST_ALL_DYN_LINK EPROSIMA_ALL_DYN_LINK)
target_include_directories(UCarClient PUBLIC ${rpcdds_INCLUDE_DIR} ${Boost_INCLUDE_DIR})

add_library(UCarServer STATIC ${RTPSUCARSERVER_SOURCES_CXX})
target_compile_definitions(UCarServer PRIVATE BOOST_ALL_DYN_LINK EPROSIMA_ALL_DYN_LINK)

message(STATUS "Configuring RTPSUCar Server and Client examples...")
set(RTPSUCARSERVEREXAMPLE_SOURCES_CXX UCarServerExample.cxx UCarServerImplExample.cxx)
set(RTPSUCARCLIENTEXAMPLE_SOURCES_CXX UCarClientExample.cxx UCarProxyImplExample.cxx)

add_executable(UCarServerExample ${RTPSUCARSERVEREXAMPLE_SOURCES_CXX})
target_include_directories(UCarServerExample PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(UCarServerExample UCarServer rpcdds ${CONAN_LIBS})

install(TARGETS UCarServerExample UCarServer
		RUNTIME DESTINATION examples/ucarapi/${BIN_INSTALL_DIR})

add_executable(UCarClientExample ${RTPSUCARCLIENTEXAMPLE_SOURCES_CXX})
target_include_directories(UCarClientExample PRIVATE ${Boost_INCLUDE_DIR})
target_link_libraries(UCarClientExample UCarClient rpcdds ${CONAN_LIBS})

install(TARGETS UCarClientExample UCarClient
		RUNTIME DESTINATION examples/ucarapi/${BIN_INSTALL_DIR})

#install(DIRECTORY .
#		DESTINATION include/ucarapi
#		COMPONENT sources
#		FILES_MATCHING
#		PATTERN "*.h"
#		PATTERN "*.hpp"
#		)
if(RPCPROTO STREQUAL "rpcdds")
    set(rpcdds_FOUND TRUE)
    set(rpcdds_INCLUDE_DIR "${PROJECT_BINARY_DIR}/include")

    #TODO It only copy in configuration time. Change for a command that execute cmake -E copy
    file(COPY ${PROJECT_SOURCE_DIR}/include/ DESTINATION ${PROJECT_BINARY_DIR}/include/rpcdds/)

    if(WITH_FASTRTPS)
#        add_subdirectory(C++/rpcdds/c++11Types/RTPSCalculator)
#        add_subdirectory(C++/rpcdds/c++11Types/RTPSCalculator_)
#        add_subdirectory(C++/rpcdds/c++11Types/RTPSCalculatorAsync)
        add_subdirectory(ucar_api)
#        add_subdirectory(ai_openapi)
    endif()
endif()

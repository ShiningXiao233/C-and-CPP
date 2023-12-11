option(USE_MYFUNC "use my func" ON)

set(THIS_MOD_NAME "myfunc")

add_library(${THIS_MOD_NAME} "./myfunc.cpp")

if(USE_MYFUNC)
    target_compile_definitions(${THIS_MOD_NAME} PRIVATE "USE_MYFUNC")
    add_library("powLib" STATIC "./pow.cpp")
    target_link_libraries("powLib" PUBLIC cp_flag)
    target_link_libraries(${THIS_MOD_NAME} PRIVATE "powLib")
endif()

target_include_directories(${THIS_MOD_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${THIS_MOD_NAME} PUBLIC cp_flag)



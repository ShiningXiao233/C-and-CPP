option(USE_MYFUNC "use my func" ON)

# add_library("myfunc" "myfunc.cpp" "pow.cpp")

add_library("myfunc" "./myfunc.cpp")

if(USE_MYFUNC)
    target_compile_definitions("myfunc" PRIVATE "USE_MYFUNC")
    add_library("powLib" STATIC "./pow.cpp")
    target_link_libraries("myfunc" PRIVATE "powLib")
endif()






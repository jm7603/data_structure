cmake_minimum_required(VERSION 3.27)
project(data_structure C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_subdirectory(llist)
add_subdirectory(lstack)

file(GLOB test_dir_list "${CMAKE_CURRENT_SOURCE_DIR}/test/*")
foreach (dir_path ${test_dir_list})
    if (IS_DIRECTORY ${dir_path})
        string(REGEX REPLACE ".+/(.+)" "\\1" dir_name ${dir_path})
        add_executable(${dir_name}_test ${dir_path}/${dir_name}_test.c)
        target_link_libraries(${dir_name}_test ${dir_name})
    else ()
        continue()
    endif ()
endforeach ()

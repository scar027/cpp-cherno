project(cpp_cherno)

add_library(sample-library Log.cpp Multiply.cpp InitLog.cpp MultiplyandLog.cpp Increment.cpp)

target_include_directories(sample-library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

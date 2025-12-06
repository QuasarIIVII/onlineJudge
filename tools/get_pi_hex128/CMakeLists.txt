cmake_minimum_required(VERSION 3.5)

project(
	A
	LANGUAGES CXX
	)
add_compile_options(--static -O2 -g --std=gnu++23 -Wall -Wl,-stack_size,0x1000000)
link_libraries(
	quadmath
)

add_executable(a a.cpp)
add_executable(r a.cpp)

target_compile_options(r
	PRIVATE
	-DONLINE_JUDGE
)

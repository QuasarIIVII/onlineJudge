cmake_minimum_required(VERSION 3.5)

project(
	A
	LANGUAGES CXX
	)
add_compile_options(--static -O2 -g --std=gnu++23 -Wl,-stack_size,0x1000000)
add_compile_options(-Wall -Wextra -Wconversion -Wsign-conversion -Wno-unused-parameter)
#add_compile_options(-fsanitize=address)
#add_compile_options(-fsanitize=undefined)

add_executable(a a.cpp)
add_executable(r a.cpp)

target_compile_options(r
	PRIVATE
	-DONLINE_JUDGE
)

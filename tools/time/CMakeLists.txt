project(
	A
	LANGUAGES CXX
	)
add_compile_options(--static -O2 -g --std=gnu++17 -Wall)
add_executable(a a.cpp)


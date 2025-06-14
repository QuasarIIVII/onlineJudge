project(
	A
	LANGUAGES CXX
	)
add_compile_options(--static -O2 -g --std=gnu++23 -Wall -Wextra)
add_executable(a a.cpp)


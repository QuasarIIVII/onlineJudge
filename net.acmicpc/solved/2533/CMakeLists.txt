project(
	A
	LANGUAGES CXX
	)
add_compile_options(--static -O2 -g --std=gnu++23 -Wall)
# stack size 512M
# --param=ssp-buffer-size=8
add_compile_options(-Wl,--stack -Wl,0x20000000)

add_executable(a a.cpp)
add_executable(r a.cpp)

target_compile_options(r
	PRIVATE
	-DONLINE_JUDGE
)

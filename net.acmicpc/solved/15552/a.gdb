define r
run
end

define custom_f
p $ymm0.v32_int8
p $ymm1.v32_int8
p $ymm2.v32_int8
p $ymm3.v32_int8
end

define a
ni
#x/20gx $rsp
custom_f
ref
end

define R
source ../a.gdb
end

define A
ni
ni
ni
ni
ni
ni
ni
ni
ni
ni
x/16bx $rsp
custom_f
ref
end

define s
step
ref
end

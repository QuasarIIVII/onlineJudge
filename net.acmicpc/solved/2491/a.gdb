define r
run
end

define custom_f
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

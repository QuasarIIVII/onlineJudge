import sys
import re

def process_line(line, label_map=None):
	line = line.replace('"', '\\"')
	line = line.replace('$', '__dollar__')
	line = line.replace(' qword ', ' QWORD PTR ')
	line = line.replace(' dword ', ' DWORD PTR ')
	line = line.replace(' word ', ' WORD PTR ')
	line = line.replace(' byte ', ' BYTE PTR ')

	if label_map is None:
		label_map = {"count": 0, "map": {}}

	if len(re.findall(r'(\.section)|(\.p2align)|(\.rept)|(\.endr)|(\.ascii)|(\.equ)|(\.byte)|(\.quad)', line)) == 0:
		# find all the local labels using regex (e.g. .L1s:, .L1e:, .L2:, jmp .L1s)
		local_labels = re.findall(r'\B(\.[._0-9A-Za-z]*:?)', line)
		if len(local_labels) > 0:
			is_def = local_labels[0][-1] == ':'
			label = local_labels[0][:-1] if is_def else local_labels[0]

			if label not in label_map["map"]:
				label_map["map"][label] = label_map["count"]
				label_map["count"] += 1
			line = line.replace(label, ".QL" + str(label_map["map"][label]) + (":" if is_def == ':' else ''))
	
	res = ""
	for c in line:
			if c == ';':
					break
			res += c
	
	return res

def main(argc, argv):
	if argc != 2:
			# get input from stdin
			stream = sys.stdin
	else:
			stream = open(argv[1], 'r')

	header = [
			".intel_syntax noprefix",
			".text",
			".globl main",
	]
	tail = [
			".att_syntax prefix",
			"nop",
	]

	print("asm(")

	for l in header:
			print('"' + l, end='\\n\\t"\n')

	for l in open("a.s", 'r'):
			if len(l.strip()) == 0:
					continue
			if 0 < len(l.strip()) and l.strip()[0] == ';':
					continue

			l = process_line(l)

			print('"' + l[:-1], end='\\n\\t"\n')

	for l in stream:
			if l.strip() == "extern sscanf, sprintf":
					break

	label_map = {"count": 0, "map": {}}
	for l in stream:
			if len(l.strip()) == 0:
					continue
			if 0 < len(l.strip()) and l.strip()[0] == ';':
					continue

			if len(re.findall(r'^([_0-9A-Za-z][._0-9A-Za-z]+:)', l.strip())) != 0:
				label_map = {"count": label_map["count"], "map": {}}
			l = process_line(l, label_map)

			print('"\t' + l[:-1], end='\\n\\t"\n')

	for l in tail:
			print('"' + l, end='\\n\\t"\n')

	print(");")
	print('extern "C" int main();')

if __name__ == '__main__':
	main(len(sys.argv), sys.argv)



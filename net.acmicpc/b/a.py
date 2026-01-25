a = [0 for _ in range(128)]

for i in [*range(32), 127]:
	a[i] |= 1

for i in [0x9, 0xa, 0xb, 0xc, 0xd, 0x20]:
	a[i] |= 2

for i in range(0x30, 0x3a):
	a[i] |= 4

for i in range(26):
	a[0x41 + i] |= 8
	a[0x61 + i] |= 16

for i in range(0, 128, 32):
	print("db " + ",".join(map(lambda x:f"{x:>02}", a[i:i+32])))

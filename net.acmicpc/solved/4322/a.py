import sys
import math

def f(digits_str):
    all_digits = int(digits_str)
    n = len(digits_str)
    best_num, best_den = 0, None

    for r in range(1, n + 1):
        prefix = all_digits // 10**r
        num = all_digits - prefix
        den = 10**(n - r) * (10**r - 1)

        g = math.gcd(num, den)
        num //= g
        den //= g

        if best_den is None or den < best_den:
            best_num, best_den = num, den

    return best_num, best_den

def main():
    for line in sys.stdin:
        s = line.strip()
        if s == '0':
            break
        digits_str = s[2:-3]
        num, den = f(digits_str)
        print(f"{num}/{den}")

if __name__ == "__main__":
    main()

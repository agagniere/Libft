N = 76

def digram(n: int) -> str:
    return chr(ord('A') + n // 26) + chr(ord('A') + n % 26)

def digram_range(*args) -> list:
    return ','.join(digram(k) for k in range(*args))

print(f'#define _ARGCNT3({digram_range(N)}, n, ...) n')
print('#define _ARGCNT4', ','.join(map(str, reversed(range(N)))))

print('#define _FOR_1(A, F, ...) F(__VA_ARGS__, A)')
print('#define _FOR_2(A, B, F, ...) F(__VA_ARGS__, A) F(__VA_ARGS__, B)')
for i in range(3, N):
    print(f'#define _FOR_{i}({digram_range(i)}, F, ...) \\')
    if i % 2:
        print(f'\t_FOR_{i-1}({digram_range(i - 1)}, F, __VA_ARGS__) \\')
        print(f'\tF(__VA_ARGS__, {digram(i - 1)})')
    else:
        print(f'\t_FOR_{i//2}({digram_range(i // 2)}, F, __VA_ARGS__) \\')
        print(f'\t_FOR_{i//2}({digram_range(i // 2, i)}, F, __VA_ARGS__)')

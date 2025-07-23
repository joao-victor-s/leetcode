# Metódo de palindromo com metade dos algortimos do número
# analisa casos de borda 9, 99, 999, ... e 10, 100, 1000, ... com base no tamanho da string
# tres valores a serem analisados: o palindromo gerado pela metade, o palindromo pela metade + 1 e o palindromo da metade -1
#   Ex: 12345 -> 12321 # tamanho impar new_prefix += new_prefix[:1][::-1] ultimo + string inversa
#                12221
#                12121
#   Ex: 1234 ->  1221 # tamanho par new_prefix += new_prefix[::-1] apenas string inversa
#                1111
#                1331

# resposta gerado pelo minimo entre a diferenca entre os numeros, discartando o numero original
# (abs(1221 - 1234), 1221) = (13, 1221)
# (abs(1111 - 1234), 1111) = (123, 1111)
# (abs(1331 - 1234), 1331) = (97, 1331)

def nearestPalindromic(n):
    candidates = set()

    candidates = {
        str(10 ** (len(n) - 1) - 1), # caso de borda de 10, 100, 1000 = 9, 99, 999
        str(10 ** len(n) + 1) # caso de borda de 9, 99, 999 = 11, 101, 1001
    }

    half_len = (len(n) + 1) // 2
    prefix = int(n[:half_len])

    for diff in [-1, 0, 1]:
        new_prefix = str(prefix+diff)
        if len(n) % 2 == 0:
            new_prefix += new_prefix[::-1]
        else:
            new_prefix += new_prefix[:-1][::-1]

        candidates.add(new_prefix)


    candidates.discard(n)

    return min(candidates,
        key=lambda x:(abs(int(x) - int(n)), int(x))
    )


print(nearestPalindromic("10")) # 121
print(nearestPalindromic("999")) # 121

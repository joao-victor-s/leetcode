#include <iostream>
#include <vector>
#include <unordered_map>

/*
    Metódo de Resolução:

    Observação: Embora este seja um problema clássico de Two Sum, não faz sentido utilizar a técnica de dois ponteiros,
    pois ela requer a ordenação do vetor — o que alteraria as posições originais dos elementos. Como a resposta exige
    os índices originais, essa abordagem não é válida aqui.

    Uso típico de Hash Table em algoritmos:
        - Verificar se um valor já foi visto (existência).
        - Detectar elementos duplicados.
        - Contar a frequência de elementos ou estados.
        - Agrupar dados por características comuns.

    Hash Tables (como `unordered_map` em C++) fornecem acesso em tempo médio constante **O(1)**, tornando-se uma
    excelente escolha para buscas rápidas.

    Etapa 1 – Construção do Hash Table:
        Utiliza-se um `unordered_map` para armazenar pares (valor, índice). A lógica é:

        - Para cada elemento `nums[i]` do vetor:
            - Calcula-se o complemento necessário para atingir o alvo: `complement = target - nums[i]`.
            - Verifica-se se `complement` já está presente no hash map:
                - Se sim, retornamos os índices: `{map[complement], i}`.
                - Caso contrário, adicionamos o elemento atual ao hash map: `{nums[i], i}`.

    Essa abordagem garante uma solução eficiente com complexidade **O(n)**.
*/

class Solution{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> map;
        std::vector<int> response;

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (map.count(complement))
            {
                response.push_back(i);
                response.push_back(map[complement]);
                break;
            }
            map[nums[i]] = i;
        }
        return response;

    }
};


int main()
{
    Solution sol;
    std::vector<int> nums = {2, 7, 11, 15};
    sol.twoSum(nums, 9);
    return 0;
}

#include <bits/stdc++.h>
#include <vector>
#include <iostream>


/*
    Método de resolução:

    - Etapa 1: Ordenação do vetor (QuickSort – complexidade O(n log n))
        A ordenação é usada para aplicar estratégias mais eficientes de busca e evitar repetições.
        Ela é útil nos seguintes contextos:
            - Dois ponteiros (two pointers): permite percorrer o vetor com dois índices móveis,
              reduzindo a complexidade de busca para pares ou trincas.
            - Remoção de duplicatas: ao ordenar, elementos iguais ficam agrupados, facilitando a filtragem.
            - Busca binária: só pode ser aplicada em estruturas ordenadas.
            - Comparações entre múltiplos arrays: permite fusão, interseção ou diferenças de forma eficiente.
            - Contagem de pares ordenados ou inversões: algoritmos baseados em merge-sort ou varredura com índice.

        - Implementação do QuickSort:
            - swap(int &a, int &b): troca os valores de duas variáveis. Pode ser usada para trocar elementos de um vetor.
            - partition(vector<int>& vec, int low, int high): organiza o vetor em torno de um pivô (último elemento).
              O índice `i` começa em (low - 1) e é incrementado sempre que um valor menor ou igual ao pivô é encontrado.
              Ao final, o pivô é colocado na sua posição correta (entre os menores à esquerda e os maiores à direita).
              A função retorna o índice do pivô.
            - quickSort(vector<int>& vec, int low, int high): aplica recursivamente o particionamento para ordenar o vetor.
                → quickSort(vec, low, pi - 1): ordena a parte esquerda do pivô.
                → quickSort(vec, pi + 1, high): ordena a parte direita do pivô.


    - Etapa 2: Aplicação do Two Pointers para resolver o 3Sum
        - A ideia é fixar um elemento nums[i] e buscar pares nums[left] e nums[right] tais que:
              nums[i] + nums[left] + nums[right] == 0
        - Para cada i:
            - Se nums[i] for igual ao anterior, é ignorado para evitar trincas repetidas.
            - left começa em i+1, right começa no final do vetor.
            - Se a soma for < 0: movemos left++ para aumentar a soma.
            - Se a soma for > 0: movemos right-- para diminuir a soma.
            - Se a soma for == 0: uma trinca válida foi encontrada.
                -> Adiciona-se ao vetor de resultado.
                -> Avança-se os ponteiros pulando valores repetidos:
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                -> Depois, ambos os ponteiros são atualizados: left++, right--

*/
class Solution {
    public:
        void swap(int &a, int &b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        int partiton(std::vector<int> &arr, int low, int high)
        {
            int pivot = arr[high];
            int i = (low - 1);

            for (int j = low; j <= high - 1; j++)
            {
                if (arr[j] <= pivot)
                {
                    i++;
                    swap(arr[i], arr[j]);
                }
            }

            swap(arr[i+1], arr[high]);
            return i + 1;
        }
        void quickSort(std::vector<int> &vec, int low, int high)
        {
            if(low < high)
            {
                int pi = partiton(vec, low, high);

                quickSort(vec, low, pi-1);
                quickSort(vec, pi+1, high);

            }
        }
        std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
            quickSort(nums, 0, nums.size() - 1);
            // std::sort(nums.begin(), nums.end());
            std::vector<std::vector<int>> vec;

            for(int i = 0; i < nums.size(); i++)
            {
                int right = nums.size() - 1;
                if (i > 0 && nums[i] == nums[i-1]) continue;

                int left = i + 1;

                while (left < right)
                {
                    int sum = nums[i] + nums[left] + nums[right];

                    if(sum < 0)
                    {
                        left++;
                    } else if (sum > 0)
                    {
                        right--;
                    }
                    else
                    {
                        vec.push_back({nums[i], nums[left], nums[right]});

                        while(left < right && nums[left] == nums[left+1]) left++;
                        while(left < right && nums [right] == nums[right-1]) right--;

                        left++;
                        right--;
                    }

                }
            }
            return vec;
        }
    };

int main()
{
    Solution sol;
    std::vector<int> nums = {2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10};
    // std::vector<int> nums = {-1,0,1,0};
    std::vector<std::vector<int>> vec = sol.threeSum(nums);
    for (std::vector v : vec)
    {
        std::cout << "[ ";
        for (int i = 0; i < v.size(); i++)
        {
            std::cout << v[i];
            if (i < v.size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}

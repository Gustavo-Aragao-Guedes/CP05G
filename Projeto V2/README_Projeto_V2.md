**Gustavo Aragão Guedes**

**RA: 10376534**

Segunda versão do projeto feita na linguagem C.


## Diferenças dessa versão para a versão 1:

1. **Input Dinâmico do Número de Threads**:
   - Versão 1: Usa uma constante `#define NUM_THREADS 50`.
   - Versão 2: Solicita ao usuário para inserir o número de threads (`scanf("%d", &num_threads)`).

   **Benefício**: Permite ajustar dinamicamente o número de threads para melhor utilizar os recursos disponíveis.

2. **Uso de Memoização para Cálculo de Fatoriais**:
   - Versão 1: Calcula o fatorial repetidamente dentro da função `calcular_e`.
   - Versão 2: Pré-calcula e armazena os fatoriais usando memoização (`calculate_factorials`).

   **Benefício**: Reduz a redundância no cálculo dos fatoriais, aumentando a eficiência.

3. **Configuração da Precisão**:
   - Versão 1: Utiliza `double` para cálculos.
   - Versão 2: Utiliza `long double` para maior precisão (`long double e = 0.0`).

   **Benefício**: Permite cálculos mais precisos, especialmente importantes para séries infinitas como a de Taylor.

4. **Estrutura Paralela e Redução**:
   - Versão 1: Usa uma estrutura `while` dentro de uma região paralela com barreiras e seções críticas.
   - Versão 2: Utiliza um `for` paralelo com redução (`#pragma omp parallel for reduction(+:e)`).

   **Benefício**: Simplifica o código e melhora a eficiência do paralelismo, evitando a necessidade de barreiras e seções críticas.

5. **Critério de Parada**:
   - Versão 1: Usa um critério de parada baseado na diferença entre iterações consecutivas (`epsilon`).
   - Versão 2: Não utiliza um critério de parada dinâmico, mas define um número fixo de termos para a série de Taylor (`int n = 100`).

   **Benefício**: Simplicidade na implementação, embora não seja adaptativo.

6. **Medida de Tempo**:
   - Versão 1: Mede o tempo dentro da região paralela.
   - Versão 2: Mede o tempo de execução total do cálculo de `e`.

   **Benefício**: Proporciona uma medida clara do tempo total necessário para o cálculo.

## Bibliotecas utilizadas:

**1. <stdio.h>**

   - Proporciona funções para operações de entrada e saída.
   
   - Permite interagir com o usuário e exibir resultados no console.
   
   Exemplos no Código:

   - printf: Usado para solicitar o número de threads, exibir mensagens de erro e mostrar os resultados finais.
   
   - scanf: Utilizado para ler o número de threads que o usuário deseja utilizar.

**2. <omp.h>**

   - Habilita a programação paralela utilizando OpenMP.
   
   - Permite a execução de múltiplos threads para aumentar a eficiência e o desempenho do programa.
   
   Exemplos no Código:
   
   - omp_set_num_threads(num_threads): Configura o número de threads a serem usadas na execução paralela.
   
   - #pragma omp parallel for reduction(+:e): Paraleliza o loop que calcula a série de Taylor, usando redução para somar os resultados parciais de cada thread.
   
   - omp_get_wtime(): Utilizado para medir o tempo de execução do cálculo paralelo.

**3. <stdlib.h>**

   - Oferece funções para alocação e gerenciamento dinâmico de memória.
   
   - Permite alocar memória para o cache dos fatoriais e liberar essa memória após o uso.
   
   Exemplos no Código:
   
   - calloc: Aloca memória para o array factorial_cache e inicializa seus elementos com zero.
   
   - free: Libera a memória alocada para o factorial_cache após o cálculo.

## Funcionamento do código:

1. **Importação de Bibliotecas**:
   - Inclui bibliotecas para entrada/saída, programação paralela e alocação de memória.

2. **Função de Cálculo de Fatoriais**:
   - Usa memoização para calcular e armazenar os fatoriais até o valor n, evitando cálculos repetidos.

3. **Solicitação do Número de Threads**:
   - O programa solicita ao usuário o número de threads a serem utilizadas e valida a entrada.

4. **Alocação de Memória**:
   - Aloca um array para armazenar os valores fatoriais, verificando se a alocação foi bem-sucedida.

5. **Cálculo de Fatoriais**:
   - Calcula os fatoriais antes da execução paralela para otimizar o tempo de execução.

6. **Contagem do Tempo de Execução**:
   - Mede o tempo total de execução do cálculo de 'e'.

7. **Configuração de Threads**:
   - Configura o número de threads baseado na entrada do usuário.

8. **Paralelização do Cálculo de 'e'**:
   - Paraleliza o loop de cálculo de 'e' usando OpenMP, com uma cláusula de redução para somar os resultados parciais.

9. **Impressão dos Resultados**:
   - Imprime o valor calculado de 'e' e o tempo total de execução.

10. **Liberação de Memória**:
    - Libera a memória alocada para o array de fatoriais.


## Comando para compilar o código:

gcc -fopenmp -o (nome) (nome).c

./(nome)




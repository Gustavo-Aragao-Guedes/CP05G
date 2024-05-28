**Gustavo Aragão Guedes**

**RA: 10376534**

Segunda versão do projeto foi feita na linguagem c.


## Mudanças da versão 1:

Aumentando a Precisão
Para calcular mais dígitos de 
𝑒
e, aumente o valor de n. Vamos modificar o código para permitir especificar n e calcular a precisão com um valor maior, por exemplo, n = 100.

Memoização do Fatorial:

Um array factorial_cache é usado para armazenar os resultados dos cálculos dos fatoriais.
A função factorial foi modificada para usar esse array. Se o fatorial de um número já foi calculado, ele é reutilizado a partir do cache, evitando recalculações.
Alocação e Liberação de Memória:

A memória para factorial_cache é alocada com calloc antes do início dos cálculos e liberada com free após a conclusão.
Proteção da Seção Crítica:

A diretiva #pragma omp critical é mantida para proteger a atualização da soma e.

Entrada Interativa:

scanf é usado para solicitar ao usuário o número de threads a serem usadas.
O número de threads é configurado com omp_set_num_threads(num_threads).
Configuração de Threads:

O programa permite que o usuário especifique o número de threads, oferecendo flexibilidade para experimentar diferentes configurações de threads sem recompilar o código.

## Explicação do código:

Função factorial: Calcula o fatorial de um número, essencial para calcular cada termo da série de Taylor.
Configuração do OpenMP: omp_set_num_threads(8) configura o uso de 8 threads.
Cálculo da Série: A diretiva #pragma omp parallel for reduction(+:e) paraleliza o loop for para distribuir os cálculos dos termos entre as threads. Cada thread calcula um termo da série e usa a diretiva critical para somar o termo ao valor de e de forma segura.
Medição do Tempo: omp_get_wtime() é usado para medir o tempo de execução do cálculo.
Impressão dos Resultados: Após o cálculo, o valor final de e e o tempo de execução são impressos.


Comando para compilar:

gcc -fopenmp -o (nome) (nome).c

./(nome)




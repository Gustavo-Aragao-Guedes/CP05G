Gustavo Aragão Guedes

RA: 10376534

Laboratório 2 foi feito na linguagem C, e foi executado e trazido para esse repositório através da AWS. 

### Explicação:
O código realiza a multiplicação de uma matriz por um vetor usando threads para paralelizar o cálculo.
No início, otamanho e os valores dentro da matriz e do vetor são predefinidos, assim como o número de threads que serão usadas (Neste caso as quantidades são 3, definidos em #define N 3 #define NUM_THREADS N).

São definidas as variáveis globais: a matriz, o vetor e o resultado.

Depois é definida a função que faz a multiplicação da matriz pelo vetor. As threads são aplicadas nessa função, onde o argumento genéricos delas é convertido para um inteiro, e esse número inteiro é atribuido ao id da thread e cada uma das threads vai calcular uma parte do vetor resultado. No fim da função a thread é encerrada.

No main: 
São declaradas as variáveis locais das threads com o phtread_t e thread_args

A matriz e o vetor são impressos.

A threads são criadas, com pthread_create e pthread_join.

- pthread_create: Cria uma nova thread. Recebe como argumentos um ponteiro para a variável da thread, atributos da thread, a função a ser executada pela thread e um argumento para a função.

- pthread_join: Espera que uma thread termine sua execução antes de continuar. É usado aqui para esperar que todas as threads tenham terminado antes de imprimir o resultado.

E por fim, o programa imprime a matriz e o vetor original e o vetor resultado da multiplicação.

### AWS:

Criação e vi:

![lab02 criação](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/ea02ba05-e4a3-4f72-9d89-82017c332c1e)

Saída no gcc:

![lab02 compilar](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/88815660-8723-4f88-b1f7-40fbebad4058)

Envio para o GitHub:

![lab02 envio git](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/20f6d938-fc3d-4714-9b99-cfa68cb01ed9)





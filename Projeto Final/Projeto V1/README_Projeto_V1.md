**Gustavo Aragão Guedes**

**RA: 10376534**

Laboratório V1 foi feito na linguagem c, com o uso da AWS para testes e Livegap Charts (https://charts.livegap.com/) para a criação dos gráficos.

Inclusão da API OpenMP.

Nesta versão, utilizei a cláusula reduction(+:tempo) para garantir que a variável tempo seja atualizada de forma correta em ambientes de paralelização. Além disso, a variável e_anterior é privada a cada thread para evitar condições de corrida.

O loop for principal foi transformado em uma região paralela usando a diretiva #pragma omp parallel for. A cláusula schedule(static) distribui uniformemente as iterações do loop entre as threads.


### Testes

**1 processador (AWS):**

![Configuração 1CPU](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/1ac61e5f-eba8-493f-938c-798cfa8fce66)

* Serial:  segundos

![image](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/8c1466af-0b6d-4e0a-b86c-17bacc97b2db)





* Paralelo:  segundos



**2 processadores:  Intel(R) Xeon(R) CPU E5-2670 v3 @ 2.30GHz**

* Serial:  segundos

* Paralelo:  segundos

**4 processadores:  Intel(R) Xeon(R) i7-3612QM CPU @ 2.10GHz**

IMAGEM

* Serial:  segundos

* Paralelo:  segundos

**6 processadores: Intel(R) Xeon(R) CPU E-2236 @ 3.40GHz**

* Serial:  segundos

* Paralelo:  segundos

**8 processadores: Intel(R) Xeon(R) CPU E5-2670 v3 @ 2.30GHz**

* Serial:  segundos
  
* Paralelo:  segundos

## Tempo de execução:

IMAGEM GRAFICO

## Speedup

* 1P =  /  = 

* 2P =  /  = 

* 4P =  /  = 

* 6P =  /  = 

* 8P =  /  = 

IMAGEM GRÁFICO

## Diretiva critical

EXPLICAÇÃO

IMAGEM

Sem critical:  segundos

Com critical:  segundos

* 1P =  segundos

* 2P =  segundos

* 4P =  segundos

* 6P =  segundos

* 8P =  segundos

## Novo Speedup

* 1P =  /  = 

* 2P =  /  = 

* 4P =  /  = 

* 6P =  /  = 

* 8P =  /  = 

IMAGEM










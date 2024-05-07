**Gustavo Aragão Guedes**

**RA: 10376534**

Laboratório V1 foi feito na linguagem c, com o uso da AWS para testes e Livegap Charts (https://charts.livegap.com/) para a criação dos gráficos.

Inclusão da API OpenMP.

Para os testes, foram calculados 50 números depois da vírgula.

Alguns dos valores de tempo e speedups foram arredondados para ficarem com apenas 3 casas decimais depois da vírgula.


### Testes

**1 processador (AWS):**

![Configuração 1CPU](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/1ac61e5f-eba8-493f-938c-798cfa8fce66)

* Serial: 1 segundo

![image](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/8c1466af-0b6d-4e0a-b86c-17bacc97b2db)

* Paralelo: 2 segundos

![image](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/a05500f2-9280-48e0-868d-c3caf1ff2f5b)


**2 processadores:  Intel(R) Xeon(R) CPU E5-2670 v3 @ 2.30GHz**

* Serial: 1 segundo

* Paralelo: 1 segundo

**4 processadores:  Intel(R) Xeon(R) i7-3612QM CPU @ 2.10GHz**

![312434718-f59d2790-14d1-4f47-93b3-95a59d3130a9](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/91ab9e16-1096-41b4-a9fd-c00fff71262f)

* Serial: 1 segundo

* Paralelo: 0,5 segundos

**6 processadores: Intel(R) Xeon(R) CPU E-2236 @ 3.40GHz**

* Serial: 1 segundo

* Paralelo: 0,33 segundos

**8 processadores: Intel(R) Xeon(R) CPU E5-2670 v3 @ 2.30GHz**

* Serial: 1 segundo
  
* Paralelo: 0,25 segundos

## Tempo de execução:

![Problema da Tartaruga Tempo](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/f62ec320-91b3-4fd4-9cdb-8ec80f5f4fa9)

## Speedup

* 1P = 1 / 2 = 0,5

* 2P = 1 / 1 = 1

* 4P = 1 / 0,5 = 2

* 6P = 1 / 0,33 = 3,03

* 8P = 1 / 0,25 = 4

![Problema da Tartaruga speedup](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/9925e0f5-b6b1-4639-88c2-81da11093e3c)

## Diretiva critical

A seção crítica #pragma omp critical garante que apenas uma thread por vez execute a atualização das variáveis globais n, e_atual e tempo. Isso evita problemas de corrida que podem ocorrer quando várias threads tentam acessar e modificar as mesmas variáveis simultaneamente.

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


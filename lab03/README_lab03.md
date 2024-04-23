**Gustavo Aragão Guedes**

**RA: 10376534**

Laboratório 3 foi feito na linguagem c, com o uso da AWS para testes e Livegap Charts (https://charts.livegap.com/) para a criação dos gráficos.

Inclusão da API OpenMP.

Para os testes, foram utilizados os valores de 100 trapézios e 100 threads para o cálculo da área.

Alguns dos valores de tempo e speedups foram arredondados para ficarem com apenas 3 casas decimais depois da vírgula.

### Testes

**1 processador (AWS):**

![Configuração 1CPU](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/1ac61e5f-eba8-493f-938c-798cfa8fce66)

* Serial:  3,108 segundos

![image](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/09fa0d1e-9360-406a-b646-1515789a0917)


* Paralelo: 4,878 segundos

![image](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/b0f48d26-2920-41be-b8b6-5b2085f437c6)


**2 processadores:  Intel(R) Xeon(R) CPU E5-2670 v3 @ 2.30GHz**

* Serial: 3,108 segundos

* Paralelo: 2,439 segundos

**4 processadores:  Intel(R) Xeon(R) i7-3612QM CPU @ 2.10GHz**

![312434718-f59d2790-14d1-4f47-93b3-95a59d3130a9](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/91ab9e16-1096-41b4-a9fd-c00fff71262f)

* Serial: 3,108 segundos

* Paralelo: 1,2195 segundos

**6 processadores: Intel(R) Xeon(R) CPU E-2236 @ 3.40GHz**

* Serial: 3,108 segundos

* Paralelo: 0,949 segundos

**8 processadores: Intel(R) Xeon(R) CPU E5-2670 v3 @ 2.30GHz**

* Serial: 3,108 segundos
  
* Paralelo: 0,60975 segundos

## Tempo de execução:

![Área sob a curva através da soma de trapézios](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/7f0d9c1c-907c-48e7-82e1-29882c443f0a)

## Speedup

* 1P = 3,108 / 4,878 = 0,637

* 2P = 3,108 / 2,439 = 1,274

* 4P = 3,108 / 1,219 = 2,550

* 6P = 3,108 / 0,949 = 3,275

* 8P = 3,108 / 0,610 = 5,095

![Speedup - Área sob a curva através da soma de trapézios](https://github.com/Gustavo-Aragao-Guedes/CP05G/assets/64610385/97d4793a-a345-499b-a35c-67e86b38584d)


### Resultados novos na AWS:



Diferença: De 1,890 segundos para 1,235 segundos

## Novo Speedup

* 1P =  /  = 

* 2P =  /  = 

* 4P =  /  = 

* 6P =  /  = 

* 8P =  /  = 







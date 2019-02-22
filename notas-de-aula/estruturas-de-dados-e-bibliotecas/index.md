---
layout: page
title: 'Estruturas de Dados e Bibliotecas'
---

Estruturas de dados proveem meios de organizar e manipular informações de maneira eficiente. Para resolver problemas de uma maneira rápida, fazemos o uso de estruturas de dados adequadas. É papel de um bom programados saber selecionar as melhores estruturas que se encaixam nas soluções propostas. A seguir apresentaremos uma visão sucinta de cada uma delas.


## Vetores

### Vetores Estáticos
	
Vetores estáticos correspondem a uma sequência de dados de mesmo tipo. O tamanho deles geralmente é definido na declaração. É possível declarar vetores de uma, duas, três ou até quatro dimensões com facilidade. Quando se sabe de antemão o tamanho máximo de uma entrada, é uma estrutura que pode ser atualizada sem problemas.


### Vetores Dinâmicos 	

É possível projetar vetores que se adequam ao tamanho dos dados. Quando chegam novos dados, o vetor aumenta e quando dados são retirados ele diminui. Felizmente, a maiora das linguagens de alto-nível fornecem estas estruturas em suas bibliotecas padrão. Podemos citar: `vector<>` (C++) e `ArrayList` (Java).

Uma série de operações são normalmente disponibilizadas pela API padrão do  C++ e podem ser visualizadas neste [link]( http://www.cplusplus.com/reference/vector/vector/).

Através do cabeçalho `<vector>` é possível utilizar esta estrutura de dados e seus métodos mais notáveis são:

- `size()`: retorna o número de elementos do vetor.
- `front()`: retorna o primeiro elemento do vetor.
- `back()`: retorna o último elemento do vetor.
- `push_back(x)`: insere o elemento `x` no vetor.
- `pop_back()`: remove o último elemento do vetor.

{% highlight cpp %}
{% include_relative src/vector-operations.cpp %}
{% endhighlight %}

Note que é possível utilizar a notação padrão de colchetes nesta estrutura.

## Pilhas

Pilhas são estruturas de dados que seguem a ordem LIFO (Last-in-first-out), ou seja, os últimos elementos que entram, são os primeiros a serem retirados.

Esta estrutura está disponível através do cabeçalho `<stack> e seus métodos mais notáveis são:

- `top()`: retorna o elemento que ocupa o topo da pilha.
- `push()`: insere um elemento na pilha.
- `pop()`: retira um elemento da pilha.
- `empty()`: verifica se a pilha está vazia.
- `size()`: retorna o tamanho da pilha.
  
O exemplo a seguir utiliza uma pilha para ler uma série de nomes e imprimí-los em sua ordem inversa.

{% highlight cpp %}
{% include_relative src/stack-operations.cpp %}
{% endhighlight %}

## Filas 

Ao contrário das Pilhas, Filas são estruturas de dados que seguem a ordem FIFO (first-in-first-out), ou seja, o primeiro elemento que é inserido, deve ser o primeiro a retirado. 

{% highlight cpp %}
{% include_relative src/queue-operations.cpp %}
{% endhighlight %}

## Filas de Prioridade 

Filas de prioridade não seguem a ordem FIFO. Elas procuram estabelecer uma prioridade entre os elementos de forma que, independentemente de quando foi inserido, o elemento de maior prioridade deve ser retirado.

Internamente, esta estrutura de dados geralmente é implementada através de uma **Heap**.


## Deques

## Estruturas de Dados Não-Lineares


### Hashing 

TODO: 

## Ordenação 

## Busca


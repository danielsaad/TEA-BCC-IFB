---
layout: page
title: 'Estruturas de Dados e Bibliotecas'
---

{% include mathjax.html %}

{:toc}

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

## Heap

Uma Heap é uma estrutura de dados em forma de árvore binária completa que possui a seguinte propriedade: 
- A raiz tem precedência sobre os seus dois filhos.
- A árvore com raiz no filho da esquerda é uma heap.
- A árvore com raiz no filho da direita é uma heap.

A figura a seguir ilustra uma Heap.

![Heap](figures/heap-1.png)

Como se trata de uma árvore binária completa, é possível representar uma Heap através de um vetor. A navegação desta árvore virtual através de uma aritmética simples. Se um nó ocupa o índice `i`do vetor, temos:

- O pai ocupa a posição `\((i-1)/2\)`.
- O filho da esquerda ocupa a posição $((i+1)*2\)$.
- O filho da direita ocupa a posição \((i+2)*2\).

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

Internamente, esta estrutura de dados geralmente é implementada através de uma **Heap** e está disponível através do cabeçalho `<queue>`. Podemos citar como exemplos os métodos:

- `empty()`: verifica se a fila de prioridade está vazia;
- `size()`: retorna o tamanho da fila de prioridade;
- `top()`: retorna o elemento de maior prioridade;
- `push()`: insere um elemento na fila de prioridade;
- `pop()`: remove o elemento de maior prioridade.

O código abaixo mostra uma situação hipotética em que várias pessoas são inseridas em uma fila de prioridade. Neste caso, definimos através do operador `<` uma relação de ordem entre as pessoas para que duas pessoas possam ser comparadas e avaliadas de acordo com a sua prioridade. No caso, pessoas mais velhas tem mais prioridade do que pessoas mais novas e que, quando as pessoas tem a mesma idade, a com menor renda mensal tem prioridade.

{% highlight cpp %}
{% include_relative src/pqueue-operations.cpp %}
{% endhighlight %}

Considere a seguinte entrada:

| Nome    | Idade | Renda Mensal |
|---------|-------|--------------|
| Daniel  |   30  |    1000.0    |
| Daniela |   30  |     400.0    |
| José    |   50  |    2000.0    |
| Pablo   |   80  |    6000.0    |
| Carlos  |   30  |     500.0    |

O programa selecionaria as seguintes pessoas de acordo com a prioridade pré-definida:

{% highlight plain %}Pablo
80
6000

Jose
50
2000

Daniela
30
400

Carlos
30
500

Daniel
20
1000

{% endhighlight %}


## Deques

## Estruturas de Dados Não-Lineares


### Hashing 

TODO: 

## Ordenação 

## Busca


---
layout: page
title: 'Estruturas de Dados e Bibliotecas'
---

* TOC
{:toc}

Estruturas de dados proveem meios de organizar e manipular informações de maneira eficiente. Para resolver problemas de uma maneira rápida, fazemos o uso de estruturas de dados adequadas. É papel de um bom programados saber selecionar as melhores estruturas que se encaixam nas soluções propostas. A seguir apresentaremos uma visão sucinta de cada uma delas.




## Vetores

### Vetores Estáticos
	
Vetores estáticos correspondem a uma sequência de dados de mesmo tipo. O tamanho deles geralmente é definido na declaração. É possível declarar vetores de uma, duas, três ou até quatro dimensões com facilidade. Quando se sabe de antemão o tamanho máximo de uma entrada, é uma estrutura que pode ser atualizada sem problemas.


### Vetores Dinâmicos 	

É possível projetar vetores que se adequam ao tamanho dos dados. Quando chegam novos dados, o vetor aumenta e quando dados são retirados ele diminui. Felizmente, a maiora das linguagens de alto-nível fornecem estas estruturas em suas bibliotecas padrão. Podemos citar: `vector<>` (C++) e `ArrayList` (Java).

Uma série de operações são normalmente disponibilizadas pela API padrão do  C++ e podem ser visualizadas neste [link]( http://www.cplusplus.com/reference/vector/vector/).

Através do cabeçalho `<vector>` é possível utilizar esta estrutura de dados e seus métodos mais notáveis são:

- `size`: retorna o número de elementos do vetor.
- `front`: retorna o primeiro elemento do vetor.
- `back`: retorna o último elemento do vetor.
- operador `[]`: acessa o elemento indexado através da notação de colchetes.
- `push_back`: insere o elemento `x` no vetor.
- `pop_back`: remove o último elemento do vetor.

{% highlight cpp %}
{% include_relative src/vector-operations.cpp %}
{% endhighlight %}

Note que é possível utilizar a notação padrão de colchetes nesta estrutura.

### Complexidade 

|:-----------:|:------------:|
|   Operação  | Complexidade |
| `push_back` |     $O(1)$     |
| `pop_back`  |     $O(1)$     |
| `[]`        |     $O(1)$     |


## Heaps

Uma Heap é uma estrutura de dados em forma de árvore binária completa que possui a seguinte propriedade: 
- A raiz tem precedência sobre os seus dois filhos.
- A árvore com raiz no filho da esquerda é uma heap.
- A árvore com raiz no filho da direita é uma heap.

A figura a seguir ilustra uma Heap.

![Heap](figures/heap-1.png)

Como se trata de uma árvore binária completa, é possível representar uma Heap através de um vetor. A navegação desta árvore virtual através de uma aritmética simples. Se um nó ocupa o índice $i$ do vetor, temos:

- O pai ocupa a posição $(i-1)/2$.
- O filho da esquerda ocupa a posição $(i+1)*2$.
- O filho da direita ocupa a posição $(i+2)*2$.

Usando esta representação, é possível representar a árvore anterior pelo seguinte vetor:

![Heap em vetor](figures/heap-2.png)

A grande vantagem de uma heap é que o elemento de maior precedência encontra-se na raiz da árvore, ou seja, na posição $0$ do vetor.  Assim, dado que um vetor tenha a propiedade de heap, é possível encontrar o elemento de maior precedência em tempo $O(1)$.

Para remover o elemento de maior precedência, troca-se a raiz da árvore com o maior dos seus dois filhos até que uma folha seja atingida, o que possibilita remover o elemento. Isso é exemplificado pelo seguinte código:

{% highlight cpp %}
{% include_relative src/heap-remove.cpp %}
{% endhighlight %}

Para inserir o processo inverso é feito: o novo elemento é adicionado no final do vetor como uma folha e ele é trocado com o pai até que ele atinja a posição $0$ ou até que ele tenha menor precedência que o seu pai, conforme ilustrado pelo código a seguir.


{% highlight cpp %}
{% include_relative src/heap-insert.cpp %}
{% endhighlight %}

É possível utilizar esta estrutura de dados através do cabeçalho `<algorithm>`.
Os métodos mais notáveis são:

- `make_heap`: transforma um vetor em uma Heap.
- `front`: retorna o elemento de maior precedência de uma Heap.
- `pop_heap`: reestrutura a Heap para remover o elemento de maior precedência. Deve ser acompanhado de um `pop_back`
- `push_heap`: reestrutura a Heap após a inserção de um elemento. Deve ser precedido de um `push_back`.

O seguinte código ilustra a operação de uma Heap.

{% highlight cpp %}
{% include_relative src/heap-operations.cpp %}
{% endhighlight %}

### Complexidade

Como virtualmente temos uma árvore completa e cheia, as operações de inserção de um elemento e remoção do elemento de maior precedência levam tempo proporcional a altura da árvore, que é no máximo $O(\lg n)$.

O acesso ao elemento de maior precedência leva tempo constante: basta acessar a posição $0$ do vetor.

|:-----------:|:------------:|
|   Operação  | Complexidade |
| `push_heap` |     $O(\lg n)$     |
| `pop_back`  |     $O(\lg n)$     |
| `front`        |     $O(1)$     |


## Pilhas

Pilhas são estruturas de dados que seguem a ordem LIFO (Last-in-first-out), ou seja, os últimos elementos que entram, são os primeiros a serem retirados.

Esta estrutura está disponível através do cabeçalho `<stack>` e seus métodos mais notáveis são:

- `top`: retorna o elemento que ocupa o topo da pilha.
- `push`: insere um elemento na pilha.
- `pop`: retira um elemento da pilha.
- `empty`: verifica se a pilha está vazia.
- `size`: retorna o tamanho da pilha.
  
O exemplo a seguir utiliza uma pilha para ler uma série de nomes e imprimí-los em sua ordem inversa.

{% highlight cpp %}
{% include_relative src/stack-operations.cpp %}
{% endhighlight %}

### Complexidade

|:--------:|:------------:|
| Operação | Complexidade |
| `top`    |    $O(1)$    |
| `push`   |    $O(1)$    |
| `pop`    |    $O(1)$    |

## Filas 

Ao contrário das Pilhas, Filas são estruturas de dados que seguem a ordem FIFO (first-in-first-out), ou seja, o primeiro elemento que é inserido, deve ser o primeiro a retirado. 

{% highlight cpp %}
{% include_relative src/queue-operations.cpp %}
{% endhighlight %}

### Complexidade

|:--------:|:------------:|
| Operação | Complexidade |
| `front`  |    $O(1)$    |
| `push`   |    $O(1)$    |
| `pop`    |    $O(1)$    |

## Filas de Prioridade 

Filas de prioridade não seguem a ordem FIFO. Elas procuram estabelecer uma prioridade entre os elementos de forma que, independentemente de quando foi inserido, o elemento de maior prioridade deve ser retirado.

Internamente, esta estrutura de dados geralmente é implementada através de uma **Heap** e está disponível através do cabeçalho `<queue>`. Podemos citar como exemplos os métodos:

- `empty`: verifica se a fila de prioridade está vazia;
- `size`: retorna o tamanho da fila de prioridade;
- `top`: retorna o elemento de maior prioridade;
- `push`: insere um elemento na fila de prioridade;
- `pop`: remove o elemento de maior prioridade.

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


### Complexidade

Como são baseadas em Heaps, as filas de prioridade possuem as seguintes complexidades.

|:--------:|:------------:|
|   `top`  |    $O(1)$    |
| `push`   |  $O(\lg n)$  |
| `pop`    |  $O(\lg n)$  |


## Deques

Deques (Double-ended queues), são estruturas de dados que combinam pilhas e filhas.
É possível inserir e remove elementos das duas extremidades e normalmente utiliza-se uma estrutura híbrida de vetor e listas na implementação.

![Deque](figures/deque.png)

Os deques podem ser utilizados através do cabeçalho `<queue>` e os principais métodos podem ser elencados como:

- `front`: acessa o elemento que está na cabeça do deque.
- `back`: acessa o elemento que está na cauda do deque.
- `push_back`: inserção na cauda do deque.
- `pop_back`: remoção na cauda do deque.
- `push_front`: inserção na cabeça do deque.
- `pop_front`: remoção na cabeça do deque.
- `empty`: verifica se o deque está vazio.
- `size`: retorna o tamanho do deque.
- Operador `[]`: retorna o elemento do deque na posição indicada na notação de colchetes.


TODO: inserir exemplo

## Vetores de Bits

Vetores de bits são estruturas que representam uma sequência de valores $0$ ou $1$. Em comparação com um vetor, essas estruturas são preferidas neste cenário pois conseguem economizar espaço e tempo, uma vez que menos acessos a memória são feitos para recuperar valores.

### Bitset

O C++ oferece através da STL a classe `bitset`, que permite a criação de vetores de bits estáticos. Ou seja, o tamanho da estrutura deve ser definida em tempo de compilação e não pode ser redimensionada.

Esta classe possibilita:

- `set`: atribui ao bit indicado o valor $1$.
- `reset`: atribui ao bit indicado o valor $0$
- `flip`: inverte o bit de uma determinada posição.
- `count`: conta o números de bits com valor $1$.
- operador `[]`: acessa o bit indexado pela notação de colchetes.

O código a seguir exemplifica o uso dessa estrutura.

{% highlight cpp %}
{% include_relative src/bitset.cpp %}
{% endhighlight %}

### Representação através de Vetores Dinâmicos

#### Operações bit-a-bit e máscaras

Podemos representar os vetores de bits através de um vetor de inteiros, basta lembrar que qualquer inteiro é representado por uma sequência de bits.

Por exemplo, o inteiro

```
42 (decimal) = 101010 (binário)
```

Para acessar o valor de um bit em específico, usamos os operadores bit-a-bit em conjunção com as **máscaras de bit**.

Estes operadores aplicam uma operação lógica em um inteiro, no caso de um operador unário, ou entre dois inteiros, no caso de um operador binário.

- Operador unário: `~` (NOT).
- Operadores binários: `&` (AND), `|` (OR), `^` (XOR), `<<` (Shift left) `>>` (Shift right).  

Considerando o inteiro de 8 bits `x = 42 (decimal) = 00101010 (binário)`, ao aplicar o operador `~` sobre ele, teríamos:

```
~x = 11010101 = 213 (decimal sem sinal) = -43 (decimal com sinal)
```

Ou seja, este operador _flipa_ todos os bits de um inteiro.

Tomando agora como exemplo os inteiros de 8 bits `x = 42 (decimal) = 00101010 (binário)` e `y = 195 (decimal) = 11000011` obteríamos o seguinte ao aplicar os operadores `&`, `|` e `^` entre eles:

```plain
  00101010       00101010       00101010
  11000011       11000011       11000011
& --------     | --------     ^ --------
  00000010       11101011       11101001
```

Ou seja, respectivamente as operações de AND, OR e XOR bit-a-bit.

Através desses operadores, podemos ligar, desligar, inverter  e checar o valor de um bit em específico utilizando as máscaras de bit.

Para ligar o i-ésimo bit (base $0$) de um inteiro `x`, usamos o operador `|` aplicado com a máscara `1 << i`. Por exemplo, se `x=42 (decimal) = 00101010` e desejamos ligar o bit `7`, basta operar `00101010` com `1 << 7 = 10000000`. 

```plain
  00101010
  10000000
| --------
  10101010
```

Para resetar o i-ésimo bit, fazemos uma operação análoga, mas dessa vez utilizando a máscara `~(1<<i)`, que deixa todos os bits ligados, com exceção do i-ésimo, em conjunção com o operador `&`.

Caso quiséssemos desligar o bit $1$ do número `x=00101010`, teríamos:

```plain
  00101010
  11111101
& --------
  00101000 
```

Para alternar o valor do i-ésimo bit, utilizamos a máscara `(1<<i)` aplicada com o operador `^`. Considerando o inteiro `x = 00101010 (binário)` e o bit $2$, teríamos:

``` plain
  00101010
  00000100
^ --------
  00101110 
```

Para checar o valor do i-ésimo bit, basta utilizar a máscara ``(1<<i)`` em conjunção com o operador `&`. Se o resultado for diferente de $0$, então o i-ésimo bit está ligado, caso contrário, desligado. Considerando o inteiro `x = 00101010 (binário)` e o bit $3$, temos:

``` plain
  00101010
  00001000
& --------
  00001000 
```

Como `00001000 = 8 (decimal)` é diferente de zero, sabemos que o bit $3$ está ligado.

Repetindo a mesma consulta para o bit $4$, teríamos: 

``` plain
  00101010
  00010000
& --------
  00000000 
```

Portanto, conseguimos concluir que o bit $4$ está desligado.

Os operadores de `>>` e `<<` servem para deslocar os bits posições à esquerda ou a direita.

Por exemplo: `  00101010 >> 1 = 00010101 (binário) = 21 (decimal)` e  `  00101010 << 2 = 10101000 (binário) = 168 (decimal)`.

Efetivamente, deslocar $i$ posições à esquerda significa realizar a divisão inteira por $2^i$. Ao deslocar $i$ posições à direita,  o resultado equivale a uma multiplicação por $2^i$.


#### Utilizando Vetores Dinâmicos

 Vimos como manipular bits utilizando inteiros, no entanto, utilizando apenas um inteiro, só conseguimos manipular uma quantidade de bits comportada por este inteiro. Para representar uma sequência maior de bits, podemos utilizar um vetor de inteiros.

 Considerando um vetor de inteiros de $64$-bits `v`, temos que `v[0]` armazena os bits $0$ a $63$, `v[1]`  os bits $64$
a $127$ e `v[i]` os bits `i*64` a `(i+1)*64 - 1`.

Assim, caso seja desejado manipular o $k$-ésimo bit desta sequência precisamos responder duas questões:
- Em que inteiro esse bit se encontra?
- Dentro deste inteiro, qual o índice deste bit?

Como se trata de um vetor de inteiros de $64$-bits, a primeira questão pode ser respondida através da divisão inteira por $64$. Assim, sabemos que o bit que desejamos manipular está na posição `v[k/64]` ou equivalentemente `v[k>>6]`, se desejamos evitar uma divisão.

Agora que sabemos que o bit desejado se encontra no inteiro `v[k>>6]`, como localizar o índice deste bit neste inteiro? Simples, pegando o resto da divisão de $k$ por $64$. Logo o índice do bit desejado no inteiro é `k % 64` ou `k & (63)`.

Conhecendo o inteiro que contém o bit e o índice deste bit no inteiro, podemos manipular o bit conforme apresentado anteriormente.

Sumarizando o discutido, o código a seguir exemplifica como manipular os bits dentro de um vetor de inteiros.


{% highlight cpp %}
{% include_relative src/bitvector-operations.cpp %}
{% endhighlight %}

#### Complexidade

Todas as operações em vetores de bits levam tempo $O(1)$, uma vez que qualquer operação exige um número fixo de expressões aritméticas e atribuições.



## Estruturas de Dados Não-Lineares

## Conjuntos

## Mapeamentos


## Hashing 

TODO: 

## Ordenação 

## Busca

## Leituras Recomendadas

- [Referência C++](http://www.cplusplus.com/reference/)
- [Implementação de um Deque](https://stackoverflow.com/questions/6292332/what-really-is-a-deque-in-stl) 
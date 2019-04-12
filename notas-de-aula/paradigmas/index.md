---
layout: page
title: 'Paradigmas de Resolução de Problemas'
---



* TOC
{:toc}

Várias soluções compartilham uma mesma linha de raciocínio, um mesmo **paradigma** de projeto. Veremos agora os principais paradigmas de projeto de algoritmos e como podemos utilizá-los para resolver problemas eficientemente.

## Busca Completa 

Como o nome indica, a busca completa é responsável por exaurir todo (ou quase todo) o espaço de busca do problema em busca de uma solução. 

Uma solução baseada em Busca Completa nunca deveria estar errada, uma vez que todas as possibilidades de solução são checadas.

Para ilustrar o conceito, tome o seguinte problema ([UVA 725](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=666)): dado dois inteiros $A=abcde$ e $B=ghijk$ de $5$ dígitos cada de modo que todos os dígitos de $0$ a $9$ sejam utilizados coletivamente pelos dois e um inteiro $N$, encontrar (quando possível) todos os valores de par $(A,B)$ tal que : 

$$
  \frac{abcde}{ghijk} = N
$$

Obviamente, o menor valor para $A$ e $B$ é $01234$, já o maior consiste em $98765$, assim, todos os possíveis valores de $A$ e $B$ estão no intervalo $[01234,98765]$, o que configura um espaço com tamanho $\approx10^5$. Como a divisão deve ser igual a $N$, podemos assumir que o espaço de busca é menor ainda, principalmente quando $N$ cresce. Dada essa discussão, o seguinte trecho de código é capaz de explorar todo o espaço de busca e resolver o problema: 


{% highlight cpp %}
{% include_relative src/uva725.cpp %}
{% endhighlight %}


Considerando agora o seguinte problema ([UVA 441](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=382)): Dado um conjunto de $k$ ($6\leq k < 13$) inteiros em ordem crescente, imprimir todos os subconjuntos de tamanho $6$ em ordem lexicográfica. O número máximo de subconjuntos pode ser expresso como: 

$$ \binom{12}{6} = 924$$

Ou seja, no máximo existe apenas $924$ possibilidades de acordo com as restrições do problema, o que é um espaço de busca bastante reduzido. Assim, para resolver o problema supracitado, basta utilizar uma estrutura com $6$ laços de repetição aninhados.

{% highlight cpp %}
{% include_relative src/uva441.cpp %}
{% endhighlight %}

Uma estratégia parecida pode ser adotada no problema [(UVA 11565)](https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2612), que consiste em, dados três inteiros $A$, $B$ e $C$ ($1\leq A,B,C \leq 10^5$), encontrar valores distintos $x$,$y$ e $z$ que satisfaçam simultâneamente as três equações abaixo:

$$\begin{eqnarray}
x + y + z & = &  A\\
x * y * z & = &  B\\
x^2 + y^2 + z^2 & = & C
\end{eqnarray}$$

No caso de haver múltiplas valorações que satisfaçam as equações simultêamente, a solução deverá escolher aquela com menor valor para $x$ possível.

De acordo com a última equação, é fácil ver que os valores de $x$, $y$ e $z$ obrigatoriamente devem estar no intervalo $[-100,100]$ de acordo com as restrições do tamanho de $A$, $B$ e $C$. Assim, ao todo temos $201 \cdot 201 \cdot 201 = 8.12 \cdot 10^6$ possibilidades, o que não é muito. Considerando esta observação, temos o seguinte código como solução.

{% highlight cpp %}
{% include_relative src/uva11565.cpp %}
{% endhighlight %}


Mais otimizações poderiam ser realizadas. Levando em consideração a equação $x * y * z = B$ e tomando o caso em que $x = y = z$, temos que $x *x * x < B$ e portanto, $x<\sqrt[3]{10^5}$. Logo, o intervalo considerado para $x$ poderia ser de $[-22,22]$, reduzindo ainda mais o espaço de busca.


Considere agora o problema [UVA 11742](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2842), que consiste em: dado um número $N$ ($1\leq N \leq 8$) de pessoas que querem ver um filme e um número $M$ ($1\leq M \leq 20$) de restrições, calcular o total de possibilidades possíveis segundo as restrições. Uma restrição consiste em duas pessoas e o número máximo (ou mínimo) de assentos nos quais estas pessoas devem estar afastadas.

Gerar todas as permutações possíveis de pessoas leva tempo $O(N!)$ e checar se uma permutação está consistente com as restrições, leva tempo $O(M+N)$ com uma a implementação for cuidadosa, desta forma, o custo total do algoritmo seria $O((M+N)\cdot N!)$, o que é factível pelas dimensões do problema. Felizmente, para gerar todas as permutações, é possível utilizar a biblioteca `<algorithm>` juntamente com o método `next_permutation`, que dada uma permutação, gera a próxima.

O problema em questão, poderia ser resolvido segundo o esboço abaixo.

{% highlight cpp %}
{% include_relative src/uva11742.cpp %}
{% endhighlight %}



No problema [UVa 12455](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3886), dado um conjunto de inteiros $S$, ($1\leq \lvert S\lvert \leq 20$) e um inteiro $X$, deseja-se saber se existe algum subconjunto de $S$ cuja soma é $X$. Tal problema é conhecido como *Subset Sum* e pode ser resolvido via **Programação Dinâmica**, entretanto, devido às restrições do tamanho de $S$, ele é passível de ser resolvido por busca completa, gerando no máximo $O(2^n)$ subconjuntos. Traduzindo para o tamanho da entrada, são feitas na ordem de $2^{20} \\approx 10^6$ operações.

Utilizando operações bit-a-bit, é possível gerar todos os subonjuntos de um conjunto $S$ de uma forma iterativa, basta lembrar que, utilizando $n$ bits, é possível representar $2^n$ valores. Desta forma, todos os inteiros no intervalo $[0,2^n]$ representariam cada um subconjunto de $n$ elementos de forma que, se o $i$-ésimo bit do inteiro está ligado, significa que o $i$-ésimo elemento do conjunto  original pertence ao subconjunto. Caso o $i$-ésimo bit estivesse desligado, o oposto valeria, isto é, que o $i$-ésimo elemento de $S$ não pertence ao subconjunto associado ao inteiro. Isso dá margem para a seguinte solução.


{% highlight cpp %}
{% include_relative src/uva12455.cpp %}
{% endhighlight %}






### Backtracking 

Um método bem conhecido que utiliza da busca completa é o **backtracking**. Durante a busca no backtraking, é possível realizar algumas "podas" e deixar de explorar algumas regiões do espaço de busca, desde que demonstradas que elas não contribuam para a solução final.


Vamos pegar como exemplo o problema clássico das **8 rainhas** ([UVA 750](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=691)). Neste problema o objetivo é posicionar $8$ rainhas em um tabuleiro de xadrez, que possui dimensões $8\times 8$ sem que uma rainha esteja em posição de atacar a outra. A figura abaixo ilustra um exemplo de solução deste problema.

![Possível solução do problema das $8$ rainhas](figures/8-queen-solution.png)

O número possível de configurações das $8$-rainhas é de $\binom{64}{8} = 4426165368  \approx 4\cdot 10^{10}$, o que representa um imenso espaço de busca.

Uma solução do jogo não pode admitir duas rainhas na mesma coluna, pois se fosse o caso, elas estariam em posição de ataque uma com a outra. Com esta observação, o espaço de busca é reduzido para $8^8 = 16777216 \approx 10^ 8$.

Utilizando o mesmo argumento acima, mas para as diagonais e linhas, o espaço de busca é reduzido substancialmente, ou seja, a posição de uma rainha é válida somente se ela não encontra-se na mesma coluna, diagonal ou linha de outra rainha.


A solução pode ser colocada como o seguinte código.

{% highlight cpp %}
{% include_relative src/uva750.cpp %}
{% endhighlight %}

### Dicas para Soluções Baseadas em Busca Completa

O principal problema de uma solução baseada em busca completa é justamente o tamanho do espaço de busca. No entanto, existem algumas dicas que podem ajudar no projeto de uma solução deste tipo.

1. (Geradores vs Filtros) Programas podem ser baseados em gerar todas as soluções e selecionar aquelas válidas, como no caso  do exemplo das 8-rainhas, ou gerar uma solução válida incrementalmente, partindo de subsoluções, ao mesmo tempo que poda soluções inválidas. A primeira situação é mais simples de construir, mas a segunda geralmente tem uma eficiência maior.
2. (Poda de soluções inválidas ou piores) Pode soluções inválidas o mais cedo possível, isso acarretará em um espaço de busca menor e consequentemente, menos processamento será utilizado. Outra estratégia é, se dada uma subsolução, o possível valor da solução formada a partir desta for pior que o valor de uma solução já encontrada, a poda pode ser efetuada sem problemas.
3. (Explore a Simetria) algumas soluções podem ser obtidas de outras soluções considerando uma rotação ou um espelhamento, dispensando efetuar o processamento para encontrá-las. Sempre que necessário, explore essa propriedade.
4. (Pré-processamento) Dependendo do problema, é vantajoso perder um tempo construindo alguma estrutura de dados que agilize algum tipo de consulta, isto é conhecido como **pré-processamento**.
5. (Otimize seu código) Procure otimizar sempre que possível, métodos de leitura, acesso a memória, uso da memória *cache*. Um bom entendimento da arquitetura de computador pode ajudar a agilizar uma solução baseada em busca completa. Exemplos:
- Acessar matrizes linha por linha é mais eficiente do que coluna por coluna;
- Utilizar vetores de bits é mais eficiente do que utilizar um vetor de booleanos ou de inteiros. Menos acessos à memória são necessários.
- Utilize estruturas fixas com tamanho suficiente para a maior entrada do problema. Isto pode ser preferível do que utilizar estruturas dinâmicas como `<vector>` se o objetivo é otimizar o máximo de tempo possível.
- Com base no exemplo anterior, declare o máximo dessas variáveis em escopo global (não use isso em qualquer coisa que não seja programação competitiva).
- Utilizar vetores para `char` normalmente é mais eficiente do que usar o tipo `string` do C++.
6. (Estruturas de Dados) Utilize melhores estruturas de dados e algoritmos. Às vezes a busca completa pode não ser a melhor solução.

## Divisão e Conquista

[Slides](assets/Busca Binária.pdf)

## Algoritmos Gulosos


Um algoritmo é dito **guloso** se ele faz uma escolha local ótima a cada passo esperando chegar na solução ótima global. Em alguns casos, os algoritmos gulosos funcionam bem: a solução é curta e eficiente. Em muitos outros casos, a solução gulosa não funciona.

Para um algoritmo guloso funcionar, ele deve:

1. Possui subestrutura ótima:
   - A solução ótima do problema pode ser decomposta em soluções ótimas de subproblemas.
2. Ele tem que ter a propriedade gulosa:
   - Se ao realizar uma escolha gulosa e proceder a resolver o problema que restou, chegamos na solução ótima, então existe a propriedade gulosa.

Vamos tomar alguns exemplos para ilustrar esse problema.

### Problema do Troco

Seja uma quantia $V$ e uma lista de $n$ moedas, cada moeda possui um valor $value[i]$ em que $i\in [0,n-1]$.

A estratégia gulosa é: utilize a moeda com maior valor possível que é menor do que a quantia $V$ e continue com o subproblema $V-x$ em que $x$ é o valor da moeda utilizada.

Por exemplo, se $value={25,10,5,1}$ e $V=42$, então a estratégia faria:

- $V = 42$: utilize uma moeda de $25$, resta $17$.
- $V=17$: utilize uma moeda de $10$, resta $7$.
- $V=7$: utilize uma moeda de $5$, resta $2$.
- $V=2$: utilize uma moeda de $1$, resta $1$.
- $V=1$: utilize uma moeda de $1$, fim.

Essa estratégia, para este sistema de moedas, leva a uma solução ótima, com um total de $5$ moedas.

Analisando melhor o problema, temos que:

1. Ele tem subestrutura ótima:
  - Para resolver o problema com $V=42$ utilizamos a solução de quando $V=17$, uma vez que as moedas $10+5+1+1$ foram utilizadas.
2. Ele tem a propriedade gulosa: para cada quantidade $V$, podemos escolher a maior moeda que é menor ou igual a $V$ que nos levará a solução ótima global.

A estratégia gulosa nos fornece um sistema muito simples, mas ela só funciona no caso de um sistema canônico de moedas, que é o caso da maioria dos sistemas financeiros. Caso as moedas disponíveis fossem $value = {4,3,1}$ e o valor a ser pago fosse $V=6$, a estratégia gulosa nos daria $3$ moedas enquanto a solução ótima consiste de duas moedas de $3$.

Para resolver o problema geral do troco, em que o sistema de moedas não necessáriamente é canônico, pode-se utilizar a abordagem de **Programação Dinâmica**.


### UVa 410 -  Station Balance

Tome o problema [UVa 410](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=351). Existem $1\leq C \leq 5$ câmaras que podem armazenar $0$,$1$ ou $2$ espécimes, $1 \leq S \leq 2C$ espécimes e uma lista $M$ da massa de cada uma das $S$ espécimes. 
O problema consiste em determinar qual câmara deve armazenar cada espécime para minimizar o desequilíbrio. 

Este é um problema conhecido como **balanceamento de carga**, muito utilizado no contexto de Máquinas Virtuais e Computação em Nuvem. Basicamente, seja: $A$ a média da massa considerando as $C$ câmaras:

$$ A = \sum_{j=1}^{S} \frac{M_j}{C} $$

O objetivo é minimizar 

$$\sum_{i=1}^{C} |X_i -A|$$

Em que $X_i$ é a massa total presente na $i$-ésima câmara.

Isto é, minimiza a soma das diferenças da massa total em cada câmara em relação a média $A$.


A estratégia gulosa que resolve esse problema é a seguinte:

1. Se $S<2C$, adicione $2C-S$ espécimes com massa $0$.
2. Ordene as espécimes pela massa.
3. Para cada câmara $i$: pareie as espécimes de massa $M_i$ e $M_{2C-i+1}$ na câmara.


Uma dica que funciona neste caso, e em muitos outros, é que em alguns casos, ordenar a entrada pode ajudar.

### UVa 10382

Tome agora o problema [UVa 10382](https://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1323). Suponha uma faixa retangular de grama com dimensões de comprimento e largura $l\times w$ e uma quantidade de $n$ irrigadores. Cada irrigador possui uma abrangência circular com raio $R$ e está posicionado no centro da faixa de grama e com o centro posicionado a uma distância horizontal do início da faixa, conforme figura abaixo:

![Irrigadores](figures/sprinklers.png)

Como o número de irrigadores é no máximo $10000$, uma solução via busca completa é inviável, levaria $2^{10000}$ possibilidades, uma vez que esse número representa a quantidade de subconjuntos de irrigadores possíveis.

Fazendo uma análise trigonométrica, é possível ver que, cada irrigador cobre no máximo uma distância horizontal $d_x$ do seu centro, conforme figura abaixo:

![Irrigadores](figures/sprinklers2.png)

Como temos um triângulo retângulo, o valor de $d_x = \sqrt{(R^2 - \frac{W}{2}^2 )}$. Logo, cada círculo com centro em $(x,y)$, cobre todo o intervalo da faixa $[x-dx,x+dx]$.

Reduzimos este problema para o problema de interseção de intervalos que possui uma solução gulosa!

1. Ordene todos os círculos de acordo com o término $x+dx$. 
2. Para cada círculo: 
   1. Se o diâmetro do círculo  não é suficiente para cubrir verticalmente a faixa de grama, ignore-o.
   2. Caso contrário, chqeue se o circulo está em conflito (interseção) com último círculo escolhido para compor a solução, se não está: insira o círculo na solução.
3. Cheque a solução e verifique se ela não tem "buracos". Em caso afirmativo, você conseguiu encontrar a menor quantidade de irrigadores que resolve o problema.

### UVa 11292 

No problema [UVa 11292](https://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2267) são dados $n$ cabeças de dragão e $m$ cavaleiros. Cada cabeça de dragão tem um diâmetro $D$ e cada cavaleiro tem uma altura $H$. O cavaleiro pode cortar a cabeça do dragão somente se a sua altura $H\geq D$.

Dado uma lista de diâmetros de cabeça e outra de alturas de cavaleiros, o problema consiste em determinar 
1. Se é possível cortar todas as cabeças de dragão
2. Em caso afirmativo, qual o total mínimo da soma das alturas dos cavaleiros que compõem uma solução.


Neste problema, mas uma vez ordenar faz sentido. Ordena-se a lista de alturas e diâmetros de cabeça e utiliza-se a seguinte inspeção linear:


{% highlight cpp %}
{% include_relative src/uva11292.cpp %}
{% endhighlight %}

### Dicas para Algoritmos Gulosos

- Provar a correção da solução gulosa leva tempo.
- Se o tamanho da entrada for suficientemente pequeno para acomodar uma solução de Programação Dinâmica ou Busca Completa, utilize ela em vez da solução gulosa, uma vez que esta não é certa de funcionar em qualquer problema.
- Ordenar a entrada pode ajudar a pensar na escolha gulosa.
- Algoritmos gulosos geralmente são eficientes em contrapartida aos elaborados usando outras abordagens.
## Programação Dinâmica

## Leituras Recomendadas

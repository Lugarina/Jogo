# Jogo
Início
Menu
1 -Registar jogador
	Receber o nome do jogador
	Verificar se este jogador já está registado
		(Caso não esteja)Guardar registo
		(Caso esteja)Indicar existência de Jogador
2 - Iniciar jogo
	jogo PvP
		registar jogador A e jogador B
	jogo PvCPU
		selecionar modo de dificuldade
			Modo Normal
			Modo Avançado
		registar jogador
3 - Listar jogadores
	Aceder ao ficeiro com os registos guardados
		Listar nomes; jogos; vitórias; empates; derrotas;
			Procurar pelo nome de jogador
			Ordenar por categoria

JOGO MANCALA PvP
tabuleiro inicial com as posições de 1 a 6 com 4 sementes e as casas de ambos os jogadores a 0
(Aspeto do tabuleiro inicial)
                         ___________
                        | TABULEIRO |
 __________________________________________________________________
|[JOGADOR B]                                                       |
| 0      4       4       4       4       4       4                 |
|        4       4       4       4       4       4       0         |
|Posicao:(1)    (2)     (3)     (4)     (5)     (6)     [JOGADOR A]|
|__________________________________________________________________|

Jogador A inicia o jogo introduzindo uma posição
(testar se a posição é válida; se não for pedir uma nova posição ao jogador)
guardar o numero de peças dentro a posição e altera o número de peças da posição escolhida para 0
nas x (sendo x o número de peças q estavam originalmente na posição escolhida) posições seguintes adiciona mais uma peça às peças q lá se encontram
	caso o número de peças seja maior que o número de posições seguintes (incluíndo a casa do jogador A), adiciona uma peças a cada uma das posições do lado do jogador B por ordem decrescente de posições, até acabar as peças (x) todas
		caso chegue à posição 1 do lado do jogador B, volta pra o lado do Jogador A por ordem crescente de posições
	caso a última peça a ser colocada calhe numa posição vazia do jogador A e na mesma posição do lado do Jogador B houver peças, essas peças do lado do oponente são retiradas dessa posição e são adicionadas à casa do jogador A mais a peça final da jogada feita
	caso a última peça a ser colocada calhe na casa do jogador, este pode jogar novamente e repete-se este processo
Assim que a vez do jogador A acabar, é feito um teste no tabuleiro para verificar se algum dos campos dos jogadores se encontra completamente vazio sem peças em nenhuma das posições com excepção das casas de ambos os jogadores
Jogador B introduz aposição que pretende jogar
(testar se a posição é válida; se não for pedir uma nova posição ao jogador)
guardar o numero de peças dentro a posição e altera o número de peças da posição escolhida para 0
nas x (sendo x o número de peças q estavam originalmente na posição escolhida) posições anteriores adiciona mais uma peça às peças q lá se encontram
	caso o número de peças seja maior que o número de posições anteriores (incluíndo a casa do jogador B), adiciona uma peças a cada uma das posições do lado do jogador A por ordem crescente de posições, até acabar as peças (x) todas
		caso chegue à posição 6 do lado do jogador A, volta pra o lado do Jogador B por ordem decrescente de posições
	caso a última peça a ser colocada calhe numa posição vazia do jogador B e na mesma posição do lado do Jogador A houver peças, essas peças do lado do oponente são retiradas dessa posição e são adicionadas à casa do jogador B mais a peça final da jogada feita
	caso a última peça a ser colocada calhe na casa do jogador, este pode jogar novamente e repete-se este processo
Assim que a vez do jogador B acabar, é feito um teste no tabuleiro para verificar se algum dos campos dos jogadores se encontra completamente vazio sem peças em nenhuma das posições com excepção das casas de ambos os jogadores
Volta para a vez do jogador A e este processo repete-se até o teste no tabuleiro indique que um dos campos dos jogadores se encontra vazio
Quando a indicação de campo vazio do teste de tabuleiro der positivo, é adicionado as restantes peças de cada campo à casa correspondente
O jogador com mais peças na sua casa é o vencedor
É registado a realização de um jogo e a quem a vitória pertence ou registado o empate para ambos os jogadores dependendo dos resultados

JOGO MANCALA PvCPU Normal
tabuleiro inicial com as posições de 1 a 6 com 4 sementes e as casas de ambos os lados a 0
(Aspeto do tabuleiro inicial)
                         ___________
                        | TABULEIRO |
 __________________________________________________________________
|[CPU]                                                    	   |
| 0      4       4       4       4       4       4                 |
|        4       4       4       4       4       4       0         |
|Posicao:(1)    (2)     (3)     (4)     (5)     (6)     [JOGADOR A]|
|__________________________________________________________________|

Jogador A inicia o jogo introduzindo uma posição
(testar se a posição é válida; se não for pedir uma nova posição ao jogador)
guardar o numero de peças dentro a posição e altera o número de peças da posição escolhida para 0
nas x (sendo x o número de peças q estavam originalmente na posição escolhida) posições seguintes adiciona mais uma peça às peças q lá se encontram
	caso o número de peças seja maior que o número de posições seguintes (incluíndo a casa do jogador A), adiciona uma peças a cada uma das posições do lado do CPU por ordem decrescente de posições, até acabar as peças (x) todas
		caso chegue à posição 1 do lado do CPU, volta pra o lado do Jogador A por ordem crescente de posições
	caso a última peça a ser colocada calhe numa posição vazia do jogador A e na mesma posição do lado do CPU houver peças, essas peças do lado do oponente são retiradas dessa posição e são adicionadas à casa do jogador A mais a peça final da jogada feita
	caso a última peça a ser colocada calhe na casa do jogador, este pode jogar novamente e repete-se este processo
Assim que a vez do jogador A acabar, é feito um teste no tabuleiro para verificar se algum dos campos se encontra completamente vazio sem peças em nenhuma das posições com excepção das casas de ambos os lados
CPU escolhe a posição com peças que estiver mais à esquerda 
guardar o numero de peças dentro a posição e altera o número de peças da posição escolhida para 0
nas x (sendo x o número de peças q estavam originalmente na posição escolhida) posições anteriores adiciona mais uma peça às peças q lá se encontram
	caso o número de peças seja maior que o número de posições anteriores (incluíndo a casa do CPU), adiciona uma peças a cada uma das posições do lado do jogador A por ordem crescente de posições, até acabar as peças (x) todas
		caso chegue à posição 6 do lado do jogador A, volta pra o lado do PC por ordem decrescente de posições
	caso a última peça a ser colocada calhe numa posição vazia do CPU e na mesma posição do lado do Jogador A houver peças, essas peças do lado do oponente são retiradas dessa posição e são adicionadas à casa do CPU mais a peça final da jogada feita
	caso a última peça a ser colocada calhe na casa do CPU, este pode jogar novamente e repete-se este processo
Assim que a vez do CPU acabar, é feito um teste no tabuleiro para verificar se algum dos campos se encontra completamente vazio sem peças em nenhuma das posições com excepção das casas de ambos os lados
Volta para a vez do jogador A e este processo repete-se até o teste no tabuleiro indique que um dos campos dos jogadores se encontra vazio
Quando a indicação de campo vazio do teste de tabuleiro der positivo, é adicionado as restantes peças de cada campo à casa correspondente
O lado com mais peças na sua casa é o vencedor
É registado a realizão de um jogo e se o jogador A ganhou ou empatou (caso tenha perdido não é registado)


JOGO MANCALA PvCPU Avançado
tabuleiro inicial com as posições de 1 a 6 com 4 sementes e as casas de ambos os lados a 0
(Aspeto do tabuleiro inicial)
                         ___________
                        | TABULEIRO |
 __________________________________________________________________
|[CPU]                                                    	   |
| 0      4       4       4       4       4       4                 |
|        4       4       4       4       4       4       0         |
|Posicao:(1)    (2)     (3)     (4)     (5)     (6)     [JOGADOR A]|
|__________________________________________________________________|

Jogador A inicia o jogo introduzindo uma posição
(testar se a posição é válida; se não for pedir uma nova posição ao jogador)
guardar o numero de peças dentro a posição e altera o número de peças da posição escolhida para 0
nas x (sendo x o número de peças q estavam originalmente na posição escolhida) posições seguintes adiciona mais uma peça às peças q lá se encontram
	caso o número de peças seja maior que o número de posições seguintes (incluíndo a casa do jogador A), adiciona uma peças a cada uma das posições do lado do PC por ordem decrescente de posições, até acabar as peças (x) todas
		caso chegue à posição 1 do lado do PC, volta pra o lado do Jogador A por ordem crescente de posições
	caso a última peça a ser colocada calhe numa posição vazia do jogador A e na mesma posição do lado do PC houver peças, essas peças do lado do oponente são retiradas dessa posição e são adicionadas à casa do jogador A mais a peça final da jogada feita
	caso a última peça a ser colocada calhe na casa do jogador, este pode jogar novamente e repete-se este processo
Assim que a vez do jogador A acabar, é feito um teste no tabuleiro para verificar se algum dos campos se encontra completamente vazio sem peças em nenhuma das posições com excepção das casas de ambos os lados
PC escolhe a posição que lhe permita terminar numa casa vazia do seu lado
Se não for possível o anterior, escolhe a posição que lhe permita terminar na sua casa (caso haja várias nesta situação, escolhe a posição mais à esquerda nesta condição)
Se não for possível, escolhe a posição mais á direita possível
guardar o numero de peças dentro a posição e altera o número de peças da posição escolhida para 0
nas x (sendo x o número de peças q estavam originalmente na posição escolhida) posições anteriores adiciona mais uma peça às peças q lá se encontram
	caso o número de peças seja maior que o número de posições anteriores (incluíndo a casa do CPU), adiciona uma peças a cada uma das posições do lado do jogador A por ordem crescente de posições, até acabar as peças (x) todas
		caso chegue à posição 6 do lado do jogador A, volta pra o lado do CPU por ordem decrescente de posições
	caso a última peça a ser colocada calhe numa posição vazia do PC e na mesma posição do lado do Jogador A houver peças, essas peças do lado do oponente são retiradas dessa posição e são adicionadas à casa do CPU mais a peça final da jogada feita
	caso a última peça a ser colocada calhe na casa do CPU, este pode jogar novamente e repete-se este processo
Assim que a vez do CPU acabar, é feito um teste no tabuleiro para verificar se algum dos campos se encontra completamente vazio sem peças em nenhuma das posições com excepção das casas de ambos os lados
Volta para a vez do jogador A e este processo repete-se até o teste no tabuleiro indique que um dos campos dos jogadores se encontra vazio
Quando a indicação de campo vazio do teste de tabuleiro der positivo, é adicionado as restantes peças de cada campo à casa correspondente
O lado com mais peças na sua casa é o vencedor
É registado a realização de um jogo e se o jogador A ganhou ou empatou (caso tenha perdido não é registado)



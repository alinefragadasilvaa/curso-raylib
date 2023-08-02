# Curso Raylib

-- Tutorial instalação da biblioteca no codeblocks:
https://ufrgscpd-my.sharepoint.com/:b:/g/personal/00579723_ufrgs_br/EXKSflE3FitPm2zd2mZxEUEBx1PVr0hLhuAz566xm_MLDw?e=OBKMV9

## Aula 1
O arquivo referente a essa aula é **aula1.c**

-- Especificação completa da biblioteca:
https://www.raylib.com/cheatsheet/cheatsheet.html

-- Comentários:
* O funcionamento da janela consiste em um while que exibe x frames por segundo
* Com isso é possível fazer alterações em variáveis a cada iteração, "movimentando" elementos na janela

-- Funções importantes:
* MeasureText(string, tamanho_fonte) // devolve a largura da string, pode ser usada para centralizar o texto na janela
* DrawText(string, posicao_horizontal, posicao_vertical, tamanho_fonte) // desneha um texto na janela
* sprintf(variavel_destino, "teste %d" , variavel_origem) // atribui uma variável em uma string

## Aula 2

-- Funções importantes:
* IsMouseButtonPressed(constante_botao) // devolve true se o mouse for pressionado uma vez
* IsMouseButtonDown(constante_botao) // devolve true enquanto o mouse estiver pressionado
* IsMouseButtonReleased(constante_botao)
* IsMouseButtonUp(constante_botao)
* GetMouseX() // devolve cordenada x do mouse
* GetMouseY() // devolve cordenada y do mouse

-- Constantes importantes: 
* MOUSE_BUTTON_LEFT // botões do mouse
* MOUSE_BUTTON_RIGHT
* MOUSE_BUTTON_MIDDLE

## Aula 3

-- Comentários
* A biblioteca vem com tipos pré-definidos (structs), como vetores e cores

-- Tipos Pré-definidos:
* Vector2 // possui cordenada x e y
  * Ex: struct Vector2 meu_vetor = {x,y};
* Rectangle // possui cordenadas x e y largura e altura
  * Ex: Rectangle meu_retangulo = {x, y, width, height};
* Color // possui intensidade das cores primárias
  * r -> red
  * g -> green
  * b -> blue
  * a -> transparência
  * Ex: Color minha_cor = {r, g, b, a};

-- Funções importantes:
* CheckCollisionPointRec(vetor, retangulo) // devolve true se tiver colisão entre um vetor tipo 2 e um retângulo que são tipos pré-definidos pela biblioteca
* DrawRectangleRec(retângulo, cor) // desenha um retângulo recebendo como parâmetro variáveis dos tipos pré-definidos retângulo e cor

## Aula 4

## Aula 5

## Aula 6

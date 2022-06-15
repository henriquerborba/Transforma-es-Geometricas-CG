# Requisitos implementados:
- Desenho da bicicleta e personagem (partes do desenho devem ser estruturadas em classes
específicas).
-Animação de pedalar com posicionamento correto das pernas e pedais, e correta rotação
das rodas.
-Uso de matrizes de rotação e translação para posicionar os elementos de desenho na tela.
-Controle de FPS

# Extras:
- Ligação matematicamente correta entre o pedal e a perna. Estou enviando junto um pequeno video feito no geogebra. que facilita o entendimento dos calculos feitos no método getAngle, na classe Utils, para determinar o angulo entre o primeiro segmento da perna e o segundo e entre os dois segmentos e a cena. É uma relação de triângulos simples. porém um pouco difícil de enxergar.

- Utilizar curvas Bezier ou B-Spline para desenho do quadro da bicicleta ou algum outro
objeto. (Os braços do boneco foram feitos com curvasde bezier)

- Utilizar concatenação de matrizes de transformação. (Isso foi feito em quase todos os desenhos, foi feita uma classe matrix com todas as operações básicas de matrizes )

- Além disso fiz uma tentativa de implementação de grafo de cena, que no fim não funcionou bem, mas tem algumas partes do desenho como as pernas do boneco e o quadro da bike que foram feitos com a primeira peça em relação a cena e as demais em relação a peça anterior na lista, para isso fiz uma pilha de transformações e fui concatenando transformações conforme desenhava os elementos da pilha, portanto tem alguns objetos com relação a cena e outros com relação a outros.


OBS: Tentei deixar o código mais organizado o possível e os nomes dos métodos e variáveis são auto-indicativos, portanto nem todo o código está comentado.

Att, Henrique Rodrigues de Borba
Engenharia de Computação

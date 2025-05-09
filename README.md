# Integrantes
- Ana Luiza Lamonier
- Matheus Pelegrini Bucater
- Thiago Freitas
# 1. Modelagem
## 1.1. Diagrama

![Diagrama do aeropêndulo](https://github.com/matheusbucater/aeropendulo/blob/main/imagens/diagrama_aeropendulo.png)

## 1.2. Equacionamento
$$
\begin{align}
	\sum{T_{ext}}=J\cdot\alpha  \\
	-L_1\cdot{P}\cdot\sin\theta+L_2\cdot{u}-b\cdot\omega=J\cdot\alpha \\
	-mg\cdot{L_1}\cdot\sin\theta+L_2\cdot{u}-b\cdot\omega=J\cdot\alpha \\
	-mg\cdot{L_1}\cdot\sin\theta+L_2\cdot{u}-b\cdot\dot\theta=J\cdot\ddot\theta \\
\end{align}
$$
Isolando $\ddot\theta$ , temos a Equação $(I)$:
$$
\tag{1}
\ddot\theta=\frac{1}{J}\left(-mg\cdot{L_1}\cdot\sin\theta-b\cdot\dot\theta+L_2\cdot{u}\right)
$$
## 1.3. Linearização
Representação no estado de espaços

Fazendo $x_1\rightarrow\theta$ e $\dot{x_2}\rightarrow\dot\theta$ na equação $(I)$

$\dot{x_2}=\frac{1}{J}\cdot\left(-mg\cdot{L_1}\cdot\sin{x_1}-b\cdot{x_2}+L_2\cdot{u}\right)$

Se 

$$
X=\left[\begin{matrix}
    x_1
    \\
    x_2
\end{matrix}\right]
\Rightarrow
\dot{X}=\left[\begin{matrix}
    \dot{x_1}
    \\
    \dot{x_2}
\end{matrix}\right]
=\left[\begin{matrix}
    x_2
    \\
    -\frac{mg}{J}\cdot{L_1}\cdot\sin{x_1}-\frac{b}{J}\cdot{x_2}+\frac{L_2}{J}\cdot{u}
\end{matrix}\right]
$$

Assim para o sistema não linear

$$
\begin{matrix}
    \left[\begin{matrix}
        \dot{x_1}
        \\
        \dot{x_2}
    \end{matrix}\right]
    =\left[\begin{matrix}
        x_2\\
        -\frac{mg}{J}\cdot{L_1}\cdot\sin{x_1}-\frac{b}{J}\cdot{x_2}+\frac{L_2}{J}\cdot{u}
    \end{matrix}\right]
    =\left[\begin{matrix}
        f_1(x,u)
        \\
        f_2(x,u)
    \end{matrix}\right]
    \\
    =f(x,u)
\end{matrix}
$$

Podemos calcular as matrizes do sistema linear aproximado:

$$
\begin{matrix}
A &=& \frac{\partial{f(x,u)}}{\partial{x}} &= &J_x\left[f\left(x,u\right)\right] =&
\left[\begin{matrix}
0 & 1
\\
-\frac{mg}{J}\cdot{L_1}\cdot\cos{x_1} & -\frac{b}{J}
\end{matrix}\right]
\\
B &=& \frac{\partial{f(x,u)}}{\partial{u}} &=& J_u\left[f\left(x,u\right)\right]
=&
\left[\begin{matrix}
    0
    \\
    \frac{L_2}{J}
\end{matrix}\right]
\end{matrix}
$$

com $\dot{X}=A\ X+B\ u$ .
Assim, o sistema linearizado é dado por:

$$
\begin{matrix}
\left[\begin{matrix}
    \dot{x_1}
    \\
    \dot{x_2}
\end{matrix}\right]
&=
\left[\begin{matrix}
    0 & 1
    \\
    -\frac{mg}{J}\cdot{L_1}\cdot\cos{\bar{x_1}} & -\frac{b}{J}
\end{matrix}\right]
\left[\begin{matrix}
    x_1
    \\
    x_2
\end{matrix}\right]
+\left[\begin{matrix}
    0
    \\
    \frac{L_2}{J}
\end{matrix}\right]
u
&=
\\
&=
\left[\begin{matrix}
	0\cdot{x_1}+1\cdot{x_2}+0\cdot{u}
	\\
	-\frac{mg}{J}\cdot{L_1}\cdot\cos{\bar{x_1}}\cdot{x_1} -\frac{b}{J}\cdot{x_2}+\frac{L_2}{J}\cdot{u}
\end{matrix}\right]
&=
\\
&=
\left[\begin{matrix}
	x_2
	\\
	-\frac{mg}{J}\cdot{L_1}\cdot\cos{\bar{x_1}}\cdot{x_1} -\frac{b}{J}\cdot{x_2}+\frac{L_2}{J}\cdot{u}
\end{matrix}\right]
\end{matrix}
$$

Ou seja,
$\dot{x_2}=-\frac{mg}{J}\cdot{L_1}\cdot\cos{\bar{x_1}}\cdot{x_1} -\frac{b}{J}\cdot{x_2}+\frac{L_2}{J}\cdot{u}$

## 1.4. Função de Transferência
Temos que:

$$
\begin{matrix}
    x_1&=&&&\theta
    \\
    x_2&=&\omega&=&\dot\theta
    \\
    \dot{x_2}&=&\dot\omega&=&\ddot\theta
\end{matrix}
$$

E seja o ângulo de equilíbrio $\bar\theta=\bar{x_1}$ . Então

$$
\ddot\theta=-\frac{mg}{J}\cdot{L_1}\cdot\cos{\bar\theta}\cdot\theta -\frac{b}{J}\cdot\dot\theta+\frac{L_2}{J}\cdot{u}
$$

Fazendo a Transformada de Laplace:

$$
\begin{matrix}
    \mathcal{L}  \ddot\theta=-\frac{mg}{J}\cdot{L_1}\cdot\cos{\bar\theta}\cdot\theta -\frac{b}{J}\cdot\dot\theta+\frac{L_2}{J}\cdot{u} 
    \\
    s^2\ \Theta(s)=-\frac{mg}{J}\cdot{L_1}\cdot\cos{\bar\theta}\cdot\Theta(s) -\frac{b}{J}\cdot{s}\ \Theta(s)+\frac{L_2}{J}\cdot{U(s)}
\end{matrix}
$$

Ademais, é possível relacionar a tensão aplicada ao motor à força do mesmo,

$$
U(s)=K_m\cdot{V(s)}
$$

Podemos também denotar a função de transferência em função do PWM (duty cycle), já que $V_{out}=V_{max}\cdot{\mbox{PWM}}$ , Então:

$$
U(s)=K_m\cdot{V(s)}=K_m\cdot{V_{max}}\cdot\mbox{PWM}(s)
$$

Portanto a função de transferência $G(s)$ é dada por

$$
G(s)=\frac{\Theta(s)}{\mbox{PWM}(s)}=\frac{K_m\cdot{V_{max}}\cdot\frac{L_2}{J}}{s^2+\frac{b}{J}s+\frac{mg}{J}\cdot{L_1}\cdot\cos{\bar\theta}}
\tag{2}
$$
# 2. Montagem
- Microcontrolador Arduino UNO
- Haste Fixa
- Haste Rotacional
- Potenciômetro 10k$\ohm$ 
- Motor DC e Hélice
- Ponte H L298N
- Bateria 9V
- Jumpers, resistores, chaves etc.

| Visão frontral                       | Visão lateral                        | Visão posterior                      |
| ------------------------------------ | ------------------------------------ | ------------------------------------ |
| ![Visão frontal do aeropêndulo](https://github.com/matheusbucater/aeropendulo/blob/main/imagens/aeropendulo_visao_frontal.png) | ![Visão lateraal do aropêndulo](https://github.com/matheusbucater/aeropendulo/blob/main/imagens/aeropendulo_visao_lateral.png) | ![Visão posterior do aeropêndulo](https://github.com/matheusbucater/aeropendulo/blob/main/imagens/aeropendulo_visao_posterior.png) |

## 2.1. Massa do conjunto haste-motor-hélices

![Massa do aeropêndulo](https://github.com/matheusbucater/aeropendulo/blob/main/imagens/massa_aeropendulo.png)

```
M = 23g = 0,023kg
```

## 2.1. Cálculo do centro de massa e tamanho da haste

![Centro de massa do aeropêndulo](https://github.com/matheusbucater/aeropendulo/blob/main/imagens/centro_de_massa_aeropendulo.png)

Para encontrar o centro de massa, o conjunto haste-motor-hélice foi equilibrado através de uma corda, encontrando o valor de $L_1$.

```
L1 = 10cm = 0.10m
L2 = 12cm = 0.12m
```
# 3. Coleta de Dados
## 3.1. Programação
- Utilização de RTOS no arduino através da biblioteca [FreeRTOS](https://docs.arduino.cc/libraries/freertos/)
- Fazer o mapeamento do valor lido no potenciômetro para o ângulo da haste.
- Fazer várias leituras do angulo e salvar esses dados.
	- Cálculo do $b$ e $J$: soltar a haste de uma determinada altura e coletar a evolução do $\theta$ no tempo.
	- Cálculo do $K_m$: variar o PWM ao longo do tempo e acompanhar a evolução do $\theta$ 

Para o mapeamento da leitura do potenciômetro para ângulo, foi utilizada a fórmula

$\theta=\frac{(V-V_{\theta=0})}{4}$

Em que, $\theta$ é o ângulo encontrado, $V$ é o valor lido no potenciômetro e $V_{\theta=0}$ é o valor lido potenciômetro quando $\theta=0$.

## 3.2. Cálculo do momento de Inércia ($J$) e do coeficiente de atrito ($b$)
Vamos rodar o programa [`read_angles.ino`](https://github.com/matheusbucater/aeropendulo/blob/main/codigos/read_angles.ino) no arduino juntamente do programa [`read_from_arduino.py`](https://github.com/matheusbucater/aeropendulo/blob/main/codigos/read_from_arduino.py) no computador para coleta de ângulos ao longo do tempo. E então vamos soltar o pendulo de uma posição inicial e observar a evolução do $\theta$ ao longo tempo.

No nosso caso o angulo inicial foi de 95º. A evolução do $\theta$ no tempo foi organizada na planilha [`pendulum.csv`](https://github.com/matheusbucater/aeropendulo/blob/main/dados/pendulum.csv) e antes de importa-lá no matlab, os tempos encontrados foram transformados para segundos e os angulos, de grau para radiano.

Isolando $b$ e fazendo $u=0$ na Equação $(1)$, temos:
$\ddot\theta=\frac{1}{J}\left(-mg\cdot{L_1}\cdot\sin\theta-b\cdot\dot\theta\right)$

Fazendo o diagrama de blocos para a fórmula encontrada, temos:

![Diagrama de blocos do sistema não linear](https://github.com/matheusbucater/aeropendulo/blob/main/imagens/simulink_sistema_nao_linear.png)

Agora basta rodar o App _Parameter Estimation_ do Simulink, que compara a curva do experimento com a curva do modelo simulado, com os dados coletados e encontrar os parametros $b$ e $J$. 

![Execução da ferramenta Parameter Estimation para encontrar os valores de J e b](https://github.com/matheusbucater/aeropendulo/blob/main/imagens/parameter_estimation_J_b.png)

Assim, encontramos
```
Estimation result(s):
	J = 0.00040934
	b = 0.0026904
```

## 3.3. Cálculo do constante de proporcionalidade ($K_m$)

Vamos rodar o programa [`malha_aberta.ino`](https://github.com/matheusbucater/aeropendulo/blob/main/codigos/malha_aberta.ino) no arduino juntamente do programa [`read_from_arduino.py`](https://github.com/matheusbucater/aeropendulo/blob/main/codigos/read_from_arduino.py) no computador para coleta de ângulos ao longo do tempo associado às variações de $\mbox{PWM}$.

A evolução do $\theta$ e do $\mbox{PWM}$ no tempo foi organizada na planilha [`aeropendulum.csv`](https://github.com/matheusbucater/aeropendulo/blob/main/dados/aeropendulum.csv) e antes de importa-lá no matlab, os tempos foram transformados para segundos, os angulos de grau para radiano e o PWM foi normaizado.

Fazendo o diagrama de blocos para a fórmula da equação $(1)$ com $u=K_m\cdot{V_{\mbox{max}}}\cdot\mbox{PWM}$, temos:

![Diagrama de blocos do sistema não linear com entrada](https://github.com/matheusbucater/aeropendulo/blob/main/imagens/simulink_sistema_com_entrada.png)

Agora basta rodar o App _Parameter Estimation_ do Simulink, que compara a curva do experimento com a curva do modelo simulado, com os dados coletados e encontrar o parametro $K_m$. 

![Execução da ferramenta Parameter Estimation para encontrar o valor de Km](https://github.com/matheusbucater/aeropendulo/blob/main/imagens/parameter_estimation_Km.png)

```
Estimation result(s):
	Km = 0.0391
```


# 4. Validação
Para validar a modelagem e as constantes encontradas foram comparadas as respostas ao degrau unitário aplicado ao modelo real e simulado.

Os dados do programa [`malha_aberta_step.ino`](https://github.com/matheusbucater/aeropendulo/blob/main/codigos/malha_aberta_step.ino) foram coletados rodando o programa [`read_from_arduino.py`](https://github.com/matheusbucater/aeropendulo/blob/main/codigos/read_from_arduino.py).

A evolução do $\theta$ no tempo foi organizada na planilha [`aeropendulum_step.csv`](https://github.com/matheusbucater/aeropendulo/blob/main/dados/aeropendulum_step.csv) e antes de importa-lá no matlab, os tempos encontrados foram transformados para segundos e os angulos, de grau para radiano.

E então esses dados foram plotados e comparados com a simulação de um step aplicado no diagrama do sistema não linear

![Diagrama de blocos do sistema não linear com degrau unitário na entrada](https://github.com/matheusbucater/aeropendulo/blob/main/imagens/simulink_degrau_unitario.png)

Dessa forma foi possível verificar que o resultado obtido é satisfatório.

![Gráfico das respostas ao degrau unitário](https://github.com/matheusbucater/aeropendulo/blob/main/imagens/resposta_degrau_unitario.png)

Podendo então continuar para o cálculo do PID.

# 5. Projeto do PID
## 5.1. Sistema no Simulink
Montar o diagrama de blocos da função de transferência da equação $(2)$ no Simulink, utilizando todos os valores das constantes encontradas ($m,\ g,\ J,\ L_1,\ L_2,\ b$)

![Diagrama de blocos da função de transferência do sistema linearizado](https://github.com/matheusbucater/aeropendulo/blob/main/imagens/simulink_funcao_de_transferencia.png)

## 4.2. PID
Encontrar os valores de $K_P$, $K_I$ e $K_D$.

![Diagrama de blocos do controlador PID](https://github.com/matheusbucater/aeropendulo/blob/main/imagens/simulink_controlador_PID.png)
```
K_P = 0.05
K_I = 0.1
K_D = 0.5
```

# 5. Programação do Microcontrolador
Usando as Tasks do FreeRTOS
- Ler o sensor
- Converter a leitura para angulo
- Calcular o Erro
- Aplicar o PID
- Plotar a evolução do ângulo e o valor de referência

Código do controlador em [`controlador_PID.ino`](https://github.com/matheusbucater/aeropendulo/blob/main/codigos/controlador_PID.ino)

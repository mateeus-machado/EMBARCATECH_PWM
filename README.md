# EMBARCATECH_PWM

## Descrição do Projeto
Este projeto tem como objetivo controlar um servomotor utilizando o microcontrolador **Raspberry Pi Pico W** com a ferramenta **Pico SDK**. O controle do servo é realizado por meio do módulo **PWM (Pulse Width Modulation)**, permitindo ajustes precisos no seu ângulo de posicionamento.

A simulação foi realizada no **Wokwi**, um ambiente de simulação online para dispositivos embarcados, sem a necessidade de um circuito físico.

## Requisitos do Projeto
1. Configurar a GPIO 22 para gerar um sinal **PWM** com frequência aproximada de **50Hz**.
2. Definir o ciclo ativo do **PWM** para os seguintes valores:
   - **2.400µs** (~180 graus) e aguardar **5 segundos**.
   - **1.470µs** (~90 graus) e aguardar **5 segundos**.
   - **500µs** (~0 graus) e aguardar **5 segundos**.
3. Implementar uma rotina de movimentação suave entre **0 e 180 graus**, com incremento de **5µs** e atraso de **10ms** por passo.
4. Realizar um experimento utilizando a ferramenta **BitDogLab** para analisar o comportamento do **LED RGB na GPIO 12** ao executar o código.

## Como Executar o Projeto
### 1. Configurar o Ambiente
Certifique-se de ter o **Pico SDK** configurado corretamente e o **VS Code** instalado. Utilize o **CMake** para compilar o projeto.

### 2. Compilar e Rodar no Simulador Wokwi
1. Clone este repositório:
   ```sh
   git clone https://github.com/mateeus-machado/EMBARCATECH_PWM.git
   cd EMBARCATECH_PWM
   ```
2. Compile o projeto:
   ```sh
   mkdir build && cd build
   cmake ..
   make
   ```
3. Execute no Wokwi:
   - Abra o arquivo `wokwi.toml` para configurar a simulação.
   - Utilize o comando:
     ```sh
     wokwi-server --chip rp2040
     ```

### 3. Testes com BitDogLab
1. Execute o código no ambiente **BitDogLab**.
2. Observe o comportamento do LED RGB na GPIO 12 durante a execução.

## Estrutura do Projeto
```
EMBARCATECH_PWM/
├── build/                # Diretório de compilação
├── CMakeLists.txt        # Arquivo de configuração do CMake
├── diagram.json          # Configuração do Wokwi
├── EMBARCATECH_PWM.c     # Código principal do projeto
├── pico_sdk_import.cmake # Importação do SDK do Pico
├── README.md             # Este arquivo
├── wokwi.toml            # Configuração do simulador Wokwi
```

## Resultados
O projeto demonstrou com sucesso a movimentação do servomotor entre os ângulos de **0, 90 e 180 graus**, bem como a movimentação suave entre eles. Os testes com o LED RGB na GPIO 12 permitiram verificar o impacto do PWM na iluminação do LED.

## Link para o Vídeo
O vídeo demonstrativo do funcionamento do projeto pode ser acessado pelo seguinte link:
[Vídeo da Simulação](https://youtu.be/e7x-uKSSxso)

## Autor
**Matheus Machado**


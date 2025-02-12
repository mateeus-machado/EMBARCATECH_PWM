#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

#define PWM_GPIO 12  // Pino do PWM para o servomotor
const float PWM_DIVISER = 64.0; // Divisor do clock para ajustar a frequência
const uint16_t WRAP_PERIOD = 39062; // Valor máximo do contador para 50 Hz --> 125000000/(50*64)

// Definição dos duty cycles calculados
const uint16_t DUTY_CYCLE_180 = 4687; // 2400 µs --> 180°
const uint16_t DUTY_CYCLE_90  = 2872; // 1470 µs --> 90°
const uint16_t DUTY_CYCLE_0   = 976;  //  500 µs --> 0°
const uint16_t STEP_US = 5;  // Incremento do ciclo ativo em µs
const uint16_t DELAY_MS = 10; // Atraso de 10 ms entre os passos

void pwm_setup() {
    gpio_set_function(PWM_GPIO, GPIO_FUNC_PWM); // Habilita o pino GPIO como PWM
    uint slice = pwm_gpio_to_slice_num(PWM_GPIO); // Obtém o canal PWM da GPIO
    pwm_set_clkdiv(slice, PWM_DIVISER); // Define o divisor de clock
    pwm_set_wrap(slice, WRAP_PERIOD);  // Define o valor de wrap (período)
    pwm_set_enabled(slice, true); // Habilita o PWM no slice correspondente
}

void seta_duty_cycle(uint16_t duty_cycle) {
    pwm_set_gpio_level(PWM_GPIO, duty_cycle); // Ajusta o duty cycle dinamicamente
}

// Função para movimentação suave dentro do while
void movimenta_suave(uint16_t inicio, uint16_t fim) {
    int passo = (inicio < fim) ? STEP_US : -STEP_US;
    uint16_t nivel_atual = inicio;

    while ((passo > 0 && nivel_atual < fim) || (passo < 0 && nivel_atual > fim)) {
        seta_duty_cycle(nivel_atual);
        sleep_ms(DELAY_MS);
        nivel_atual += passo;
    }
    seta_duty_cycle(fim); // Garante a posição final
}

int main() {
    stdio_init_all();
    pwm_setup();

    printf("Configurando PWM para 180 graus (2400 µs)...\n");
    seta_duty_cycle(DUTY_CYCLE_180);
    sleep_ms(5000);

    printf("Configurando PWM para 90 graus (1470 µs)...\n");
    seta_duty_cycle(DUTY_CYCLE_90);
    sleep_ms(5000);

    printf("Configurando PWM para 0 graus (500 µs)...\n");
    seta_duty_cycle(DUTY_CYCLE_0);
    sleep_ms(5000);

    while (1) {
        printf("Movendo suavemente para 180 graus...\n");
        movimenta_suave(DUTY_CYCLE_0, DUTY_CYCLE_180);
        sleep_ms(100);

        printf("Movendo suavemente para 0 graus...\n");
        movimenta_suave(DUTY_CYCLE_180, DUTY_CYCLE_0);
        sleep_ms(100);
    }
}

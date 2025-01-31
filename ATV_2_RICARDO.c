// Inclusão de bibliotecas padrão para funcionamento do código
#include "stdio.h"
#include "hardware/timer.h"
#include "pico/stdlib.h"

// Definição dos pinos dos LEDs RGB
#define LED_PIN_RED 13
#define LED_PIN_GREEN 11
#define LED_PIN_BLUE 12
// Definição do pino do botão
#define BUTTON_PIN 5

// Variáveis para controle do estado do LED
int estado_led = 0;
bool led_on = false;

// Função de callback para o timer
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    
    // Verifica o estado do LED e desliga o LED correspondente
    switch (estado_led)
    {
    // Desliga o LED vermelho
    case 0:
        gpio_put(LED_PIN_RED, 0);
        printf("RED OFF \n");
        estado_led = 1;
        add_alarm_in_ms(2000, turn_off_callback, NULL, false);
        break;
    // Desliga o LED verde
    case 1:
        gpio_put(LED_PIN_GREEN, 0);
        printf("GREEN OFF \n");
        estado_led = 2;
        add_alarm_in_ms(2000, turn_off_callback, NULL, false);
        break;
    // Desliga o LED azul
    case 2:
        gpio_put(LED_PIN_BLUE, 0);
        printf("BLUE OFF \n");
        led_on = false; // Todos os LEDs foram desligados
        estado_led = 0; // Reinicia o estado do LED
        break;
    
    }
    
return 0;
   
}

// Função principal
int main() {
    // Inicialização serial
    stdio_init_all();

    // Inicialização dos pinos dos LEDs
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);

    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);

    gpio_init(LED_PIN_BLUE);
    gpio_set_dir(LED_PIN_BLUE, GPIO_OUT);
     
    // Inicialização do botão
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);
 
    
    
    // Loop infinito
    while (true)
    {
        // Verifica se o botão foi pressionado
        if(gpio_get(BUTTON_PIN) == 0 && !led_on){
            sleep_ms(50); // Debounce de 50ms

            // Verifica se o botão foi pressionado após debounce
            if (gpio_get(BUTTON_PIN) == 0)
            {   
                // Acende os LEDs caso for verdadeiro
                gpio_put(LED_PIN_RED, 1);
                gpio_put(LED_PIN_GREEN, 1);
                gpio_put(LED_PIN_BLUE, 1);

                // Atualiza o estado do LED
                led_on = true;

                // Começa pelo LED vermelho
                estado_led = 0;

                // Agenda o primeiro callback para desligar os LEDS apos 3 segundos
                add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            }
            
        }

        // Evitar sobrecarga na CPU
        sleep_ms(10);
    }

    return 0;
    
}
# Lista de materiales

Componentes del circuito simulado en Wokwi.

| Cantidad | Componente | Función |
| ---: | --- | --- |
| 1 | ESP32 DevKitC V4 | Lee el PIR y controla el servo y el LED. |
| 1 | Sensor de movimiento PIR | Activa su salida digital al detectar movimiento. |
| 1 | Microservo posicional | Representa la compuerta del depósito. Cierra a 40° y abre a 140°. |
| 1 | LED verde | Indica que se está sirviendo alimento. |
| 1 | Resistencia de 220 Ω | Limita la corriente del LED. Se conecta en serie con el ánodo. |
| 9 | Conexiones virtuales entre componentes | Unen las señales, la alimentación y la tierra del circuito. |

Wokwi también conecta TX y RX al monitor serial virtual. La alimentación a 3V3 indicada en el [esquema](../docs/esquema.png) corresponde al simulador. Para un montaje físico se debe dimensionar la fuente según la tensión y la corriente que requiera el servo elegido.

# Lógica del comedero

El PIR simula el movimiento del gato frente al plato. El ESP32 lee la señal por GPIO 2. La variable booleana `dispensado` guarda si ya se sirvió comida durante esa activación.

| Momento | Qué hace el programa |
| --- | --- |
| Encendido | Coloca el servo en 40°, apaga el LED y deja `dispensado` en `false`. |
| Primera lectura en `HIGH` | Si `dispensado` está en `false`, mueve el servo a 140° y enciende el LED de GPIO 5. |
| Tras 1,5 s de apertura | Vuelve a 40°, apaga el LED, cambia `dispensado` a `true` y espera 10 s. Durante esa espera el programa no lee el PIR. |
| El PIR continúa en `HIGH` | El programa conserva `dispensado` en `true`. La compuerta permanece cerrada. |
| Primera lectura en `LOW` después de servir | Cambia `dispensado` a `false` y anuncia que está listo para la siguiente comida. |

## Comprobación en Wokwi

El monitor serial funciona a **115200 baudios**. El circuito configura el PIR con una salida activa de **20 s** y un tiempo de inhibición de **1,2 s** al desactivarse. Mide los intervalos con el reloj del simulador.

1. Inicia el proyecto y espera a que el servo se coloque en la posición de cierre.
2. Pulsa el PIR y luego **Simulate motion** una sola vez. Durante la apertura deben coincidir el giro del servo, la luz del LED y el mensaje de detección.
3. Deja pasar los 10 s de espera posteriores al cierre. Como el PIR sigue activo, la compuerta debe permanecer cerrada y el mensaje de detección debe aparecer una sola vez.
4. Cuando la salida del PIR baje, el monitor anunciará el reinicio. Deja pasar los 1,2 s de inhibición y activa el PIR otra vez. Debe comenzar una nueva dispensación.

El monitor serial permite seguir el ciclo completo. El último mensaje indica que la variable `dispensado` volvió a `false` y puede comenzar otra dispensación.

```text
Comedero Inteligente: Modo EN ESPERA...
>>> Gato detectado! Dispensando alimento...
Dispensacion completada. Servo cerrado.
Sistema reiniciado. Listo para la proxima comida.
```

El PIR responde a movimiento. En este prototipo, «una porción» corresponde a una apertura de la compuerta durante 1,5 s. La cantidad de alimento en gramos tendría que medirse en un montaje físico.

[Abrir la simulación](https://wokwi.com/projects/481363038394430465) · [Consultar el comportamiento del PIR en Wokwi](https://docs.wokwi.com/parts/wokwi-pir-motion-sensor)

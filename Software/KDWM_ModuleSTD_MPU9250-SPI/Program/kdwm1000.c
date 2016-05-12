/*====================================================================================================*/
/*====================================================================================================*/
#include "drivers\stm32f4_system.h"
#include "modules\module_serial.h"
#include "modules\module_mpu9250.h"

#include "kdwm1000.h"
/*====================================================================================================*/
/*====================================================================================================*/
void KDWM_Init( void )
{
  SystemInit();
  HAL_InitTick();

  KDWM_GPIO_Config();
  KDWM_UART_Config(NULL);
  KDWM_MPU9250_Config();
}
/*====================================================================================================*/
/*====================================================================================================*/
void KDWM_Loop( void )
{
  int16_t imu[10] = {0};

  while(1) {
    LED_G_Toggle();
    delay_ms(100);

    MPU9250_getData(imu);
    printf("AX:%5i\tAY:%5i\tAZ:%5i\tGX:%5i\tGY:%5i\tGZ:%5i\tMX:%5i\tMY:%5i\tMZ:%5i\r\n", imu[1], imu[2], imu[3], imu[4], imu[5], imu[6], imu[7], imu[8], imu[9]);
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
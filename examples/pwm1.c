#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

const int BCM12_PWM0 = 12; // 각 하드웨어 pwm 핀을 변수로 선언
const int BCM13_PWM1 = 13;
const int BCM18_PWM0 = 18;

int main()
{
    int intensity;       // 빛의 밝기 조절용 변수
    wiringPiSetupGpio(); // BCM핀 번호를 사용하겠다고 선언

    pwmSetMode(PWM_MODE_MS); // PWM을 마크-스페이스 모드로 사용 선언

    pinMode(BCM12_PWM0, PWM_OUTPUT); // 12번 핀을 하드웨어 PWM 모드로 설정
    pinMode(BCM18_PWM0, PWM_OUTPUT); // 18번 핀을 하드웨어 PWM 모드로 설정
    pinMode(BCM13_PWM1, PWM_OUTPUT); // 13번 핀을 하드웨어 PWM 모드로 설정

    while (1)
    {

        for (intensity = 0; intensity < 1024; ++intensity)
        {  
            pwmWrite(BCM12_PWM0, 500);
            pwmWrite(BCM18_PWM0, intensity);
            pwmWrite(BCM13_PWM1, 1024 - intensity);
            delay(1);
        }

        for (intensity = 1023; intensity >= 0; --intensity)
        {                                          
            pwmWrite(BCM12_PWM0, 500);             
            pwmWrite(BCM18_PWM0, intensity);       
            pwmWrite(BCM13_PWM1, 1024 - intensity);
            delay(1);
        }
        delay(1);
    }

    return 0;
}
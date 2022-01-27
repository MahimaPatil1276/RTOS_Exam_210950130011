#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include <freertos/timers.h>

TaskHandle_t xTask1;
TaskHandle_t xTask2;

TimerHandle_t xTimer;
void timerfunction(TimerHandle_t xTimer)
{
    printf("timer callback function\n");
}

void task_1(void *pv)
{
    while(1)
    {
        printf("TASK 1  RUNNING\n");
        vTaskDelay(pdMS_TO_TICKS(1000));    
    }
}

void task_2(void *pv)
{
    while(1)
    {
        printf("TASK 2  RUNNING\n");
        vTaskDelay(pdMS_TO_TICKS(2000));    
    }
}

void task_3(void *pv)
{
    count++;
    printf("Task 3 \n");
    vTaskDelay(pdMS_TO_TICKS(5000));

    if(count==2)
    {
        
        xTimerStart(Task3,0);

    }
    
}

void app_main()
{
    BaseType_t result;
    
    result=xTaskCreate(task_1,"task_1",2048,NULL,5,&xTask1);

    if(result==pdPASS)
    {
        printf("task_1 created\n");
    }

    result=xTaskCreate(task_2,"task_2",2048,NULL,6,&xTask2);

    if(result==pdPASS)
    {
        printf("task_2 created\n");
    }

    result=xTaskCreate(task_3,"task_3",2048,NULL,7,&xTask3);

    if(result==pdPASS)
    {
        printf("task_3 created\n");
    }
    Timer = xTimerCreate("TimerOFF",pdMS_TO_TICKS(10),pdFALSE,NULL,Taskfunction);
    
    
}

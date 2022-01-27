#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include <freertos/timers.h>

TaskHandle_t xTask1;
TaskHandle_t xTask2;

TimerHandle_t xTask3;

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

void task_3(TimerHandle_t xTimer)
{
    count++;
    printf("Task 3 \n");

    if(count==5)
    {
        printf("Turning off the timer\n");
        xTimerStop(xTimer,0);
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

    Task3 = xTimerCreate("TimerOFF",pdMS_TO_TICKS(10000),pdFALSE,NULL,task_3);
    xTimerStart(Task3,0);

    while(1)
    {
        printf("Main task\n");
        vTaskDelay(pdMS_TO_TICKS(10000));
    }
}

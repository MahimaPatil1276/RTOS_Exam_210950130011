#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include <freertos/queue.h>

TaskHandle_t xTask1;
TaskHandle_t xTask2;
TaskHandle_t xTask3;
QueueHandle_t queue;
TaskHandle_t xTask4;
TaskHandle_t xTask5;

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
    while(1)
    {
        printf("TASK 3  RUNNING\n");
        vTaskDelay(pdMS_TO_TICKS(5000));    
    }
}

void task_4(void *pv)
{
   int task4_data=0;
    while(1)
    {
        task4_data++;
        printf("TASK 4  RUNNING\n");
        xQueueSend(queue, &task4_data,portMAX_Delay);
        vTaskDelay(pdMS_TO_TICKS(1000));    
    }
}

void task_5(void *pv)
{
   int task5_data=0;
    while(1)
    {
        printf("TASK 5  RUNNING\n");
        xQueueReceive(queue, &task5_data,portMAX_Delay);
        printf("RECEIVED DATA %d\n",task5_data);
        vTaskDelay(pdMS_TO_TICKS(1000));    
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

    queue=xQueueCreate(10,sizeof(int));

    result=xTaskCreate(task_4,"task_4",2048,NULL,8,&xTask4);

    if(result==pdPASS)
    {
        printf("task_4 created\n");
    }

    result=xTaskCreate(task_5,"task_5",2048,NULL,9,&xTask5);

    if(result==pdPASS)
    {
        printf("task_5 created\n");
    }
}

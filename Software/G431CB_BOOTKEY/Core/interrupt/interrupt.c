#include "interrupt.h" 

struct keys key[1]={0,0,0};

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance ){
		//printf("tim ok\r\n");
		key[0].key_sta = HAL_GPIO_ReadPin (GPIOB ,GPIO_PIN_8 );
		for(int i=0;i<1;i++)
		{
			switch (key[i].judge_sta )
			{
				case 0:
				{
					if(key[i].judge_sta==0) 
					{
						key[i].key_time =0;
						key[i].judge_sta =1;
					}
				}
				break;
				case 1:
				{
					if(key[i].key_sta ==1)
					{
						key[i].judge_sta =2;
					}
					else key[i].judge_sta =0;
				}
				break;
				case 2:
				{
					if(key[i].key_sta == 0)
					{
						key[i].judge_sta =0;
						if (key[i].key_time <60) key[i].s_flag =1;
						if (key[i].key_time >60) key[i].l_flag =1;
						//printf("keys%d ok\r\n",key[i].s_flag);
						//printf("keyl%d ok\r\n",key[i].l_flag);
					}
					else key[i].key_time ++;
				}
				break;
			}
		}
	}
	
}

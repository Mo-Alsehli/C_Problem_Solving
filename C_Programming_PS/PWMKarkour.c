void MCAL_TIMER_Generate_PWM(TIMER_TypeDef* TIMERx,uint32_t CH,uint32_t duty_cycle,uint32_t freq){

	TIMERx->CR1 &=~(1<<0);//Counter disabled

	GPIO_PinConfig_t  Pin_Cfg ;
	uint32_t clk = 8000000 ;

	char user_flage=1;
	uint32_t user_top=0;
	uint32_t user_pre=1;

	while(user_flage==1){
		user_top = (clk)/(freq * user_pre );
		if(user_top>=32000){
			user_pre+=2;
		}
		else{
			user_flage=0;
		}
	}

	//====================TIM1===================


	if(TIMERx==TIMER1){
		RCC_TIMER1_CLK_EN();//enable timer1 clock
		RCC_GPIOA_CLK_EN();//enable porta clock
		RCC_AFIO_CLK_EN() ;//enable AF io clock

		if(CH == CH_1)
		{
			Pin_Cfg.GPIO_PinNumber = GPIO_PIN_8 ;
			Pin_Cfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP ;
			Pin_Cfg.GPIO_Output_Speed = GPIO_SPEED_50M ;
			MCAL_GPIO_Init(GPIOA, &Pin_Cfg);

			TIMERx->CCMR1 |=(1<<3); //Output compare 1 preload enable
			TIMERx->CCER |=(1<<0); // Capture/Compare 1 output enable
			TIMERx->CCMR1 |=(0b110<<4);//110: PWM mode 1 - In upcounting, channel 1 is active
			TIMERx->CCR1=(user_top*duty_cycle/100);//duty cycle
			TIMERx->BDTR |=(1<<15); // Main output enable
			TIMERx->DIER |=(0b11<<0);//Update interrupt enable Capture/Compare 1 interrupt enable
		}
		else if(CH==CH_2){
			Pin_Cfg.GPIO_PinNumber = GPIO_PIN_9 ;
			Pin_Cfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP ;
			Pin_Cfg.GPIO_Output_Speed = GPIO_SPEED_50M ;
			MCAL_GPIO_Init(GPIOA, &Pin_Cfg);
			TIMERx->CCMR1 |=(1<<11);
			TIMERx->CCER |=(1<<4);
			TIMERx->CCMR1 |=(0b110<<12);
			TIMERx->CCR2=(user_top*duty_cycle/100);//duty cycle
			TIMERx->BDTR |=(1<<15);
			TIMERx->DIER |=(0b101<<0);
		}
		else if(CH==CH_3){
			Pin_Cfg.GPIO_PinNumber = GPIO_PIN_10 ;
			Pin_Cfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP ;
			Pin_Cfg.GPIO_Output_Speed = GPIO_SPEED_50M ;
			MCAL_GPIO_Init(GPIOA, &Pin_Cfg);
			TIMERx->CCMR2 |=(1<<3);
			TIMERx->CCER |=(1<<8);
			TIMERx->CCMR2 |=(0b110<<4);
			TIMERx->CCR3=(user_top*duty_cycle/100);//duty cycle
			TIMERx->BDTR |=(1<<15);
			TIMERx->DIER |=(0b1001<<0);
		}
		else if(CH==CH_4){
			Pin_Cfg.GPIO_PinNumber = GPIO_PIN_11 ;
			Pin_Cfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP ;
			Pin_Cfg.GPIO_Output_Speed = GPIO_SPEED_50M ;
			MCAL_GPIO_Init(GPIOA, &Pin_Cfg);
			TIMERx->CCMR2 |=(1<<11);
			TIMERx->CCER |=(1<<12);
			TIMERx->CCMR2 |=(0b110<<12);
			TIMERx->CCR4=(user_top*duty_cycle/100);//duty cycle
			TIMERx->BDTR |=(1<<15);
			TIMERx->DIER |=(0b10001<<0);
		}
	}

	//====================TIM2===================

	else if (TIMERx==TIMER2){
		RCC_TIMER2_CLK_EN();//enable timer2 clock
		RCC_GPIOA_CLK_EN();//enable porta clock
		RCC_AFIO_CLK_EN();//enable AF io clock

		if(CH==CH_1){
			Pin_Cfg.GPIO_PinNumber = GPIO_PIN_0 ;
			Pin_Cfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP ;
			Pin_Cfg.GPIO_Output_Speed = GPIO_SPEED_50M ;
			MCAL_GPIO_Init(GPIOA, &Pin_Cfg);
			TIMERx->CCMR1 |=(1<<3);
			TIMERx->CCER |=(1<<0);
			TIMERx->CCMR1 |=(0b110<<4);
			TIMERx->CCR1=(user_top*duty_cycle/100);//duty cycle
			TIMERx->DIER |=(0b11<<0);
		}
		else if(CH==CH_2){
			Pin_Cfg.GPIO_PinNumber = GPIO_PIN_1 ;
			Pin_Cfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP ;
			Pin_Cfg.GPIO_Output_Speed = GPIO_SPEED_50M ;
			MCAL_GPIO_Init(GPIOA, &Pin_Cfg);
			TIMERx->CCMR1 |=(1<<11);
			TIMERx->CCER |=(1<<4);
			TIMERx->CCMR1 |=(0b110<<12);
			TIMERx->CCR2=(user_top*duty_cycle/100);//duty cycle
			TIMERx->DIER |=(0b101<<0);
		}
		else if(CH==CH_3){
			Pin_Cfg.GPIO_PinNumber = GPIO_PIN_2 ;
			Pin_Cfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP ;
			Pin_Cfg.GPIO_Output_Speed = GPIO_SPEED_50M ;
			MCAL_GPIO_Init(GPIOA, &Pin_Cfg);
			TIMERx->CCMR2 |=(1<<3);
			TIMERx->CCER |=(1<<8);
			TIMERx->CCMR2 |=(0b110<<4);
			TIMERx->CCR3=(user_top*duty_cycle/100);//duty cycle
			TIMERx->DIER |=(0b1001<<0);
		}
		else if(CH==CH_4){
			Pin_Cfg.GPIO_PinNumber = GPIO_PIN_3 ;
			Pin_Cfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP ;
			Pin_Cfg.GPIO_Output_Speed = GPIO_SPEED_50M ;
			MCAL_GPIO_Init(GPIOA, &Pin_Cfg);
			TIMERx->CCMR2 |=(1<<11);
			TIMERx->CCER |=(1<<12);
			TIMERx->CCMR2 |=(0b110<<12);
			TIMERx->CCR4=(user_top*duty_cycle/100);//duty cycle
			TIMERx->DIER |=(0b10001<<0);
		}
	}
	//====================TIM3===================

	else if (TIMERx==TIMER3){
		RCC_TIMER3_CLK_EN();//enable timer3 clock
		RCC_GPIOA_CLK_EN();//enable porta clock
		RCC_GPIOB_CLK_EN();//enable porta clock
		RCC_AFIO_CLK_EN();//enable AF io clock

		if(CH==CH_1){
			Pin_Cfg.GPIO_PinNumber = GPIO_PIN_6 ;
			Pin_Cfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP ;
			Pin_Cfg.GPIO_Output_Speed = GPIO_SPEED_50M ;
			MCAL_GPIO_Init(GPIOA, &Pin_Cfg);
			TIMERx->CCMR1 |=(1<<3);
			TIMERx->CCER |=(1<<0);
			TIMERx->CCMR1 |=(0b110<<4);
			TIMERx->CCR1=(user_top*duty_cycle/100);//duty cycle
			TIMERx->DIER |=(0b11<<0);
		}
		else if(CH==CH_2){
			Pin_Cfg.GPIO_PinNumber = GPIO_PIN_7 ;
			Pin_Cfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP ;
			Pin_Cfg.GPIO_Output_Speed = GPIO_SPEED_50M ;
			MCAL_GPIO_Init(GPIOA, &Pin_Cfg);
			TIMERx->CCMR1 |=(1<<11);
			TIMERx->CCER |=(1<<4);
			TIMERx->CCMR1 |=(0b110<<12);
			TIMERx->CCR2=(user_top*duty_cycle/100);//duty cycle
			TIMERx->DIER |=(0b101<<0);
		}
		else if(CH==CH_3){
			Pin_Cfg.GPIO_PinNumber = GPIO_PIN_0 ;
			Pin_Cfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP ;
			Pin_Cfg.GPIO_Output_Speed = GPIO_SPEED_50M ;
			MCAL_GPIO_Init(GPIOB, &Pin_Cfg);
			TIMERx->CCMR2 |=(1<<3);
			TIMERx->CCER |=(1<<8);
			TIMERx->CCMR2 |=(0b110<<4);
			TIMERx->CCR3=(user_top*duty_cycle/100);//duty cycle
			TIMERx->DIER |=(0b1001<<0);
		}
		else if(CH==CH_4){
			Pin_Cfg.GPIO_PinNumber = GPIO_PIN_1 ;
			Pin_Cfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP ;
			Pin_Cfg.GPIO_Output_Speed = GPIO_SPEED_50M ;
			MCAL_GPIO_Init(GPIOB, &Pin_Cfg);
			TIMERx->CCMR2 |=(1<<11);
			TIMERx->CCER |=(1<<12);
			TIMERx->CCMR2 |=(0b110<<12);
			TIMERx->CCR4=(user_top*duty_cycle/100);//duty cycle
			TIMERx->DIER |=(0b10001<<0);
		}
	}


	//====================TIM4===================

	else if (TIMERx==TIMER4){
		RCC_TIMER4_CLK_EN();//enable timer3 clock
		RCC_GPIOB_CLK_EN();//enable porta clock
		RCC_AFIO_CLK_EN();//enable AF io clock

		if(CH==CH_1){
			Pin_Cfg.GPIO_PinNumber = GPIO_PIN_6 ;
			Pin_Cfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP ;
			Pin_Cfg.GPIO_Output_Speed = GPIO_SPEED_50M ;
			MCAL_GPIO_Init(GPIOB, &Pin_Cfg);

			TIMERx->CCMR1 |=(1<<3);
			TIMERx->CCER |=(1<<0);
			TIMERx->CCMR1 |=(0b110<<4);
			TIMERx->CCR1=(user_top*duty_cycle/100);//duty cycle
			TIMERx->DIER |=(0b11<<0);
		}
		else if(CH==CH_2){
			Pin_Cfg.GPIO_PinNumber = GPIO_PIN_7 ;
			Pin_Cfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP ;
			Pin_Cfg.GPIO_Output_Speed = GPIO_SPEED_50M ;
			MCAL_GPIO_Init(GPIOB, &Pin_Cfg);
			TIMERx->CCMR1 |=(1<<11);
			TIMERx->CCER |=(1<<4);
			TIMERx->CCMR1 |=(0b110<<12);
			TIMERx->CCR2=(user_top*duty_cycle/100);//duty cycle
			TIMERx->DIER |=(0b101<<0);
		}
		else if(CH==CH_3){
			Pin_Cfg.GPIO_PinNumber = GPIO_PIN_8 ;
			Pin_Cfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP ;
			Pin_Cfg.GPIO_Output_Speed = GPIO_SPEED_50M ;
			MCAL_GPIO_Init(GPIOB, &Pin_Cfg);
			TIMERx->CCMR2 |=(1<<3);
			TIMERx->CCER |=(1<<8);
			TIMERx->CCMR2 |=(0b110<<4);
			TIMERx->CCR3=(user_top*duty_cycle/100);//duty cycle
			TIMERx->DIER |=(0b1001<<0);
		}
		else if(CH==CH_4){
			Pin_Cfg.GPIO_PinNumber = GPIO_PIN_9 ;
			Pin_Cfg.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP ;
			Pin_Cfg.GPIO_Output_Speed = GPIO_SPEED_50M ;
			MCAL_GPIO_Init(GPIOB, &Pin_Cfg);
			TIMERx->CCMR2 |=(1<<11);
			TIMERx->CCER |=(1<<12);
			TIMERx->CCMR2 |=(0b110<<12);
			TIMERx->CCR4=(user_top*duty_cycle/100);//duty cycle
			TIMERx->DIER |=(0b10001<<0);
		}
	}


	//	ARPE: Auto-reload preload enable
	//	0: TIMx_ARR register is not buffered
	//	1: TIMx_ARR register is buffered
	TIMERx->CR1 |=(1<<7);


	//	110: PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1


	TIMERx->ARR=user_top;//frec peak value

	TIMERx->PSC=(user_pre-1);//prescaller

	//	Bit 15 MOE: Main output enable
	//	This bit is cleared asynchronously by hardware as soon as the break input is active. It is set
	//	by software or automatically depending on the AOE bit. It is acting only on the channels
	//	which are configured in output.
	//	0: OC and OCN outputs are disabled or forced to idle state.
	//	1: OC and OCN outputs are enabled if their respective enable bits are set (CCxE, CCxNE in
	//	TIMx_CCER register).
	//	See OC/OCN enable description for more details
	//TIMERx->TIMx_BDTR |=(1<<15);

	//	Bit 2 CC2IE: Capture/Compare 2 interrupt enable
	//	0: CC2 interrupt disabled
	//	1: CC2 interrupt enabled
	//	Bit 1 CC1IE: Capture/Compare 1 interrupt enable
	//	0: CC1 interrupt disabled
	//	1: CC1 interrupt enabled
	//	Bit 0 UIE: Update interrupt enable
	//	0: Update interrupt disabled
	//	1: Update interrupt enabled
	//TIMERx->TIMx_DIER |=(0b101<<0);

	//	UG: Update generation
	//	This bit can be set by software, it is automatically cleared by hardware.
	//	0: No action
	//	1: Reinitialize the counter and generates an update of the registers. Note that the prescaler
	//	counter is cleared too (anyway the prescaler ratio is not affected). The counter is cleared if
	//	the center-aligned mode is selected or if DIR=0 (upcounting), else it takes the auto-reload
	//	value (TIMx_ARR) if DIR=1 (downcounting).
	TIMERx->EGR |=(1<<0);

	TIMERx->CR1 |=(1<<0);//enable the timer

}
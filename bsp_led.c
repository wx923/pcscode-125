void bsp_InitLed(){
    rcu_periph_clock_enable(RCU_AF);
    rcu_periph_clock_enable(RCU_GPIOB);
    gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ,
              GPIO_PIN_3 | GPIO_PIN_4 | GPIO__PIN_5 |
              GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_0 | GPIO_PIN_12);
    //关闭蜂鸣器
    gpio_bit_write(GPIOB,GPIO_PIN_0,0);
    //按键初始化
    gpio_init(GPIOC, GPIO_MODE_IPD, GPIO_OSPEED_50MHZ, GPIO_PIN_6);      

}
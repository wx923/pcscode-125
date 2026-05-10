void bsp_InitLed(){
     rcu_periph_clock_enable(RCU_AF);
    rcu_periph_clock_enable(RCU_GPIOB);    // GPIOB 只需要 1 次
    rcu_periph_clock_enable(RCU_GPIOC);    // GPIOC 只需要 1 次
    /* GPIOB 上所有外设一次性初始化：LED + 蜂鸣器 + 继电器 */
    gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ,
              GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 |
              GPIO_PIN_6 | GPIO_PIN_7 | GPIO_PIN_0 | GPIO_PIN_12);
    /* 关闭蜂鸣器（低电平触发，输出 0 = 关闭）*/
    gpio_bit_write(GPIOB, GPIO_PIN_0, 0);
    /* 按键在 GPIOC 上，单独初始化为输入下拉 */
    gpio_init(GPIOC, GPIO_MODE_IPD, GPIO_OSPEED_50MHZ, GPIO_PIN_6);
    g_tModS.iCountRuningUpdate = 100;
}
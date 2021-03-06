#ifndef FUSEE_GPIO_H
#define FUSEE_GPIO_H

#define TEGRA_GPIO_PORTS        4
#define TEGRA_GPIO_BANKS        8
#define GPIO_BANK_SHIFT         5  
#define GPIO_PORT_SHIFT         3
#define GPIO_PORT_MASK          0x03
#define GPIO_PIN_MASK           0x07
    
typedef enum {
    TEGRA_GPIO_PORT_A = 0,
    TEGRA_GPIO_PORT_B = 1,
    TEGRA_GPIO_PORT_C = 2,
    TEGRA_GPIO_PORT_D = 3,
    TEGRA_GPIO_PORT_E = 4,
    TEGRA_GPIO_PORT_F = 5,
    TEGRA_GPIO_PORT_G = 6,
    TEGRA_GPIO_PORT_H = 7,
    TEGRA_GPIO_PORT_I = 8,
    TEGRA_GPIO_PORT_J = 9,
    TEGRA_GPIO_PORT_K = 10,
    TEGRA_GPIO_PORT_L = 11,
    TEGRA_GPIO_PORT_M = 12,
    TEGRA_GPIO_PORT_N = 13,
    TEGRA_GPIO_PORT_O = 14,
    TEGRA_GPIO_PORT_P = 15,
    TEGRA_GPIO_PORT_Q = 16,
    TEGRA_GPIO_PORT_R = 17,
    TEGRA_GPIO_PORT_S = 18,
    TEGRA_GPIO_PORT_T = 19,
    TEGRA_GPIO_PORT_U = 20,
    TEGRA_GPIO_PORT_V = 21,
    TEGRA_GPIO_PORT_W = 22,
    TEGRA_GPIO_PORT_X = 23,
    TEGRA_GPIO_PORT_Y = 24,
    TEGRA_GPIO_PORT_Z = 25,
    TEGRA_GPIO_PORT_AA = 26,
    TEGRA_GPIO_PORT_BB = 27,
    TEGRA_GPIO_PORT_CC = 28,
    TEGRA_GPIO_PORT_DD = 29,
    TEGRA_GPIO_PORT_EE = 30,
    TEGRA_GPIO_PORT_FF = 31,
} tegra_gpio_port;

typedef struct {
    uint32_t config[TEGRA_GPIO_PORTS];
    uint32_t direction[TEGRA_GPIO_PORTS];
    uint32_t out[TEGRA_GPIO_PORTS];
    uint32_t in[TEGRA_GPIO_PORTS];
    uint32_t int_status[TEGRA_GPIO_PORTS];
    uint32_t int_enable[TEGRA_GPIO_PORTS];
    uint32_t int_level[TEGRA_GPIO_PORTS];
    uint32_t int_clear[TEGRA_GPIO_PORTS];
    uint32_t masked_config[TEGRA_GPIO_PORTS];
    uint32_t masked_dir_out[TEGRA_GPIO_PORTS];
    uint32_t masked_out[TEGRA_GPIO_PORTS];
    uint32_t masked_in[TEGRA_GPIO_PORTS];
    uint32_t masked_int_status[TEGRA_GPIO_PORTS];
    uint32_t masked_int_enable[TEGRA_GPIO_PORTS];
    uint32_t masked_int_level[TEGRA_GPIO_PORTS];
    uint32_t masked_int_clear[TEGRA_GPIO_PORTS];
} tegra_gpio_bank_t;

typedef struct {
    tegra_gpio_bank_t bank[TEGRA_GPIO_BANKS];
} tegra_gpio_t;

static inline volatile tegra_gpio_t *gpio_get_regs(void)
{
    return (volatile tegra_gpio_t *)0x6000D000;
}

#define TEGRA_GPIO(port, offset) \
    ((TEGRA_GPIO_PORT_##port * 8) + offset)

/* Mode select */
#define GPIO_MODE_GPIO          0
#define GPIO_MODE_SFIO          1

/* Direction */
#define GPIO_DIRECTION_INPUT    0
#define GPIO_DIRECTION_OUTPUT   1

/* Level */
#define GPIO_LEVEL_LOW          0
#define GPIO_LEVEL_HIGH         1

/* Named GPIOs */
#define GPIO_MICROSD_CARD_DETECT        TEGRA_GPIO(Z, 1)
#define GPIO_MICROSD_WRITE_PROTECT      TEGRA_GPIO(Z, 4)
#define GPIO_MICROSD_SUPPLY_ENABLE      TEGRA_GPIO(E, 4)

void gpio_configure_mode(uint32_t pin, uint32_t mode);
void gpio_configure_direction(uint32_t pin, uint32_t dir);
void gpio_write(uint32_t pin, uint32_t value);
uint32_t gpio_read(uint32_t pin);

#endif

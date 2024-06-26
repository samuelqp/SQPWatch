/*
 * Copyright (c) 2018 Jan Van Winkel <jan.van_winkel@dxplore.eu>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/display.h>
#include <zephyr/drivers/gpio.h>
#include <lvgl.h>
#include <stdio.h>
#include <string.h>
#include <zephyr/kernel.h>

#define LOG_LEVEL CONFIG_LOG_DEFAULT_LEVEL
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(app);

static uint32_t count;

#ifdef CONFIG_GPIO
static struct gpio_dt_spec button_gpio = GPIO_DT_SPEC_GET_OR(DT_ALIAS(sw0), gpios, {0});
static struct gpio_callback button_callback;

static void button_isr_callback(const struct device *port,
				struct gpio_callback *cb,
				uint32_t pins)
{
	ARG_UNUSED(port);
	ARG_UNUSED(cb);
	ARG_UNUSED(pins);
	printk("Button One Pressed\n\r");
	// lv_label_set_text(sqp_label, "PQS");

	count = 0;
}
#endif

int main(void)
{
	int err;
	char count_str[11] = {0};
	const struct device *display_dev;
	lv_obj_t *clock_label;
	lv_obj_t *right_border;
	lv_obj_t *top_border;
	lv_obj_t *bottom_border;
	lv_obj_t *left_border;
	lv_obj_t *center_marker;


	display_dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_display));
	if (!device_is_ready(display_dev)) {
		LOG_ERR("Device not ready, aborting test");
		return 0;
	}

#ifdef CONFIG_GPIO
	if (device_is_ready(button_gpio.port)) {
		err = gpio_pin_configure_dt(&button_gpio, GPIO_INPUT);
		if (err) {
			LOG_ERR("failed to configure button gpio: %d", err);
			return 0;
		}

		gpio_init_callback(&button_callback, button_isr_callback,
				   BIT(button_gpio.pin));

		err = gpio_add_callback(button_gpio.port, &button_callback);
		if (err) {
			LOG_ERR("failed to add button callback: %d", err);
			return 0;
		}

		err = gpio_pin_interrupt_configure_dt(&button_gpio,
						      GPIO_INT_EDGE_TO_ACTIVE);
		if (err) {
			LOG_ERR("failed to enable button callback: %d", err);
			return 0;
		}
	}
#endif

	right_border = lv_label_create(lv_scr_act());
	lv_label_set_text(right_border, "|");
	lv_obj_align(right_border, LV_ALIGN_RIGHT_MID, 0, 0);

	left_border = lv_label_create(lv_scr_act());
	lv_label_set_text(left_border, "|");
	lv_obj_align(left_border, LV_ALIGN_LEFT_MID, 0, 0);

	top_border = lv_label_create(lv_scr_act());
	lv_label_set_text(top_border, "--");
	lv_obj_align(top_border, LV_ALIGN_TOP_MID, 0, 0);

	bottom_border = lv_label_create(lv_scr_act());
	lv_label_set_text(bottom_border, "--");
	lv_obj_align(bottom_border, LV_ALIGN_BOTTOM_MID, 0, 0);

	center_marker = lv_label_create(lv_scr_act());
	lv_obj_align(center_marker, LV_ALIGN_CENTER, 0, 0);

	// clock_label = lv_label_create(lv_scr_act());
	// lv_obj_align(clock_label, LV_ALIGN_CENTER, 4, 0);

	lv_task_handler();
	display_blanking_off(display_dev);

	while (1) {
		if ((count % 100) == 0U) {
			sprintf(count_str, "%d", count/100U);
			lv_label_set_text(center_marker, "+");
			// lv_label_set_text(clock_label, count_str);
		}
		lv_task_handler();
		++count;
		k_sleep(K_MSEC(10));
	}
}
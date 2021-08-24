/*
 * @Author: Ghazi
 * @Date: 2021-07-28 11:20:08
 * @Description: 
 * @FilePath: /log/demo/main.c
 * @LastEditTime: 2021-07-28 18:53:39
 * @LastEditors: Ghazi
 */

#define LOG_TAG    "main"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#include "log.h"

static void test_elog(void);

int main(void) {
    log_init();

    /* dynamic set enable or disable for output logs (true or false) */
    // log_set_output_enabled(false);
    /* dynamic set output logs's level (from ELOG_LVL_ASSERT to ELOG_LVL_VERBOSE) */
    // log_set_filter_lvl(LOG_LVL_WARN);
    // /* dynamic set output logs's filter for tag */
    // log_set_filter_tag("main");
    // /* dynamic set output logs's filter for keyword */
    // log_set_filter_kw("Hello");
    // /* dynamic set output logs's tag filter */
    // log_set_filter_tag_lvl("main", LOG_LVL_WARN);

    test_elog();

    return EXIT_SUCCESS;
}

/**
 * EasyLogger demo
 */
void test_elog(void) {
    uint8_t buf[256]= {0};
    int i = 0;

    for (i = 0; i < sizeof(buf); i++)
    {
        buf[i] = i;
    }
    while(true) {
        /* test log output for all level */
        log_raw("Hello EasyLogger!\n");
        usleep(1000);
        log_a("Hello EasyLogger!");
        usleep(1000);
        log_e("Hello EasyLogger!");
        usleep(1000);
        log_w("Hello EasyLogger!");
        usleep(1000);
        log_i("Hello EasyLogger!");
        usleep(1000);
        log_d("Hello EasyLogger!");
        usleep(1000);
        log_v("Hello EasyLogger!");
        usleep(1000);
        log_hexdump("test", 16, buf, sizeof(buf));
        sleep(5);
    }
}

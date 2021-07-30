/*
 * @Author: Ghazi
 * @Date: 2021-07-28 11:43:34
 * @Description: 
 * @FilePath: /log/log/log.c
 * @LastEditTime: 2021-07-28 19:32:42
 * @LastEditors: Ghazi
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "elog.h"

#define ENV_LOG_LEVEL "LOG_LEVEL"
#define ENV_LOG_TAG "LOG_TAG"
#define ENV_LOG_KEYWORD "LOG_KEYWORD"

int log_init(void)
{
    /* close printf buffer */
    setbuf(stdout, NULL);
    /* initialize EasyLogger */
    elog_init();
    /* set EasyLogger log format */
    elog_set_fmt(ELOG_LVL_ASSERT, ELOG_FMT_ALL & ~ELOG_FMT_P_INFO & ~ELOG_FMT_T_INFO);
    elog_set_fmt(ELOG_LVL_ERROR, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME | ELOG_FMT_DIR);
    elog_set_fmt(ELOG_LVL_WARN, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME | ELOG_FMT_DIR);
    elog_set_fmt(ELOG_LVL_INFO, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_DEBUG, ELOG_FMT_ALL & ~ELOG_FMT_P_INFO & ~ELOG_FMT_T_INFO);
    elog_set_fmt(ELOG_LVL_VERBOSE, ELOG_FMT_ALL);
#ifdef ELOG_COLOR_ENABLE
    elog_set_text_color_enabled(true);
#endif
    /* start EasyLogger */
    elog_start();

    return 0;
}

void log_set_output_enabled(bool enabled)
{
    elog_set_output_enabled(enabled);
}

void log_set_filter_lvl(uint8_t level)
{
    elog_set_filter_lvl(level);
}

void log_set_filter_tag(const char *tag)
{
    elog_set_filter_tag(tag);
}

void log_set_filter_kw(const char *keyword)
{
    elog_set_filter_kw(keyword);
}

void log_set_filter_tag_lvl(const char *tag, uint8_t level)
{
    elog_set_filter_tag_lvl(tag, level);
}

void log_get_env_and_update(void)
{
    char *value = NULL;
    uint8_t level = 0;

    if ((value = getenv(ENV_LOG_LEVEL))) {
        level = atoi(value);
        if (level >= ELOG_LVL_VERBOSE)
            log_set_filter_lvl(ELOG_LVL_VERBOSE);
    }

    if ((value = getenv(ENV_LOG_TAG))) {
        log_set_filter_tag(value);
    }

    if ((value = getenv(ENV_LOG_KEYWORD))) {
        log_set_filter_kw(value);
    }
}

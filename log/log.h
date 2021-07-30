/*
 * @Author: Ghazi
 * @Date: 2021-07-28 11:43:28
 * @Description: 
 * @FilePath: /log/log/log.h
 * @LastEditTime: 2021-07-28 19:35:37
 * @LastEditors: Ghazi
 */
#ifndef __LOG_H__
#define __LOG_H__

#include <stdint.h>
#include <stdbool.h>

/* output log's level */
#define LOG_LVL_ASSERT                      0
#define LOG_LVL_ERROR                       1
#define LOG_LVL_WARN                        2
#define LOG_LVL_INFO                        3
#define LOG_LVL_DEBUG                       4
#define LOG_LVL_VERBOSE                     5

#if !defined(LOG_TAG)
    #define LOG_TAG          "NO_TAG"
#endif

#if !defined(LOG_LVL)
    #define LOG_LVL          LOG_LVL_VERBOSE
#endif

extern void elog_output(uint8_t level, const char *tag, const char *file, const char *func,
        const long line, const char *format, ...);
extern void elog_hexdump(const char *name, uint8_t width, uint8_t *buf, uint16_t size);
extern void elog_raw(const char *format, ...);

#define log_output(LEVEL, TAG, ...) do {log_get_env_and_update();elog_output(LEVEL, TAG, __FILE__, __FUNCTION__, __LINE__, __VA_ARGS__);} while(0)

#if LOG_LVL >= LOG_LVL_ASSERT
    #define log_a(...)       log_output(LOG_LVL_ASSERT, LOG_TAG, __VA_ARGS__)
#else
    #define log_a(...)       ((void)0);
#endif
#if LOG_LVL >= LOG_LVL_ERROR
    #define log_e(...)       log_output(LOG_LVL_ERROR, LOG_TAG, __VA_ARGS__)
#else
    #define log_e(...)       ((void)0);
#endif
#if LOG_LVL >= LOG_LVL_WARN
    #define log_w(...)       log_output(LOG_LVL_WARN, LOG_TAG, __VA_ARGS__)
#else
    #define log_w(...)       ((void)0);
#endif
#if LOG_LVL >= LOG_LVL_INFO
    #define log_i(...)       log_output(LOG_LVL_INFO, LOG_TAG, __VA_ARGS__)
#else
    #define log_i(...)       ((void)0);
#endif
#if LOG_LVL >= LOG_LVL_DEBUG
    #define log_d(...)       log_output(LOG_LVL_DEBUG, LOG_TAG, __VA_ARGS__)
#else
    #define log_d(...)       ((void)0);
#endif
#if LOG_LVL >= LOG_LVL_VERBOSE
    #define log_v(...)       log_output(LOG_LVL_VERBOSE, LOG_TAG, __VA_ARGS__)
#else
    #define log_v(...)       ((void)0);
#endif

#define log_hexdump elog_hexdump
#define log_raw     elog_raw

int log_init(void);

void log_get_env_and_update(void);

void log_set_output_enabled(bool enabled);

void log_set_filter_lvl(uint8_t level);

void log_set_filter_tag(const char *tag);

void log_set_filter_kw(const char *keyword);

void log_set_filter_tag_lvl(const char *tag, uint8_t level);

#endif /* __LOG_H__ */

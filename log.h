#ifndef LOG_H
#define LOG_H
#include <stdio.h>

#ifdef DEBUG
#define LOG_LEVEL_INFO
#define LOG_LEVEL_WARN
#define LOG_LEVEL_ERR
#endif

#ifdef LOG_LEVEL_INFO
    #define log_info(str) fprintf(stdout, "[%s:%s:%d][INFO] %s\n",\
                __FILE__, __func__, __LINE__, str)
    #define log_info_args(fmt, ...) fprintf(stdout, "[%s:%s:%d][INFO] " fmt "\n",\
                __FILE__, __func__, __LINE__, __VA_ARGS__)
#else
    #define log_info(str)           ((void)0)
    #define log_info_args(fmt, ...) ((void)0)
#endif

#ifdef LOG_LEVEL_WARN
    #define log_warn(str)           fprintf(stderr, "[%s:%s:%d][WARN] %s\n",\
                __FILE__, __func__, __LINE__, str)
    #define log_warn_args(fmt, ...) fprintf(stderr, "[%s:%s:%d][WARN] " fmt "\n",\
                __FILE__, __func__, __LINE__, __VA_ARGS__)
#else
    #define log_warn(str)           ((void)0)
    #define log_warn_args(fmt, ...) ((void)0)
#endif

#ifdef LOG_LEVEL_ERR
    #define log_err(str)           fprintf(stderr, "[%s:%s:%d][ERR]  %s\n",\
                __FILE__, __func__, __LINE__, str)
    #define log_err_args(fmt, ...) fprintf(stderr, "[%s:%s:%d][ERR]  " fmt "\n",\
                __FILE__, __func__, __LINE__, __VA_ARGS__)
#else
    #define log_err(str)           ((void)0)
    #define log_err_args(fmt, ...) ((void)0)
#endif

#endif

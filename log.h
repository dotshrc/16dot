#ifndef LOG_H
#define LOG_H
#include <stdio.h>

#define STAMP

#ifdef DEBUG
#define LOG_LEVEL_INFO
#define LOG_LEVEL_WARN
#define LOG_LEVEL_ERR
#endif

#ifdef STAMP
#define log_stamp() fprintf(stdout, "[%s:%s:%d]\n", __FILE__, __func__, __LINE__)
#else
#define log_stamp() ((void)0)
#endif

#ifdef LOG_LEVEL_INFO
    #define log_info(str)          fprintf(stdout, "[INFO] %s\n", str)
    #define log_info_args(fmt, ...) fprintf(stdout, "[INFO] " fmt "\n", __VA_ARGS__)
#else
    #define log_info(str)          ((void)0)
    #define log_info_args(fmt, ...) ((void)0)
#endif
#ifdef LOG_LEVEL_WARN
    #define log_warn(str)          fprintf(stderr, "[WARN] %s\n", str)
    #define log_warn_args(fmt, ...) fprintf(stderr, "[WARN] " fmt "\n", __VA_ARGS__)
#else
    #define log_warn(str)          ((void)0)
    #define log_warn_args(fmt, ...) ((void)0)
#endif
#ifdef LOG_LEVEL_ERR
    #define log_err(str)          fprintf(stderr, "[ERR]  %s\n", str)
    #define log_err_args(fmt, ...) fprintf(stderr, "[ERR]  " fmt "\n", __VA_ARGS__)
#else
    #define log_err(str)          ((void)0)
    #define log_err_args(fmt, ...) ((void)0)
#endif
#endif

/* =============================================================================
#     FileName: log.h
#         Desc: a simple utilize logging module for pure_c
#       Author: liuchu
#        Email: liuchu1.0@gmail.com
#     HomePage: NULL
#      Version: 0.0.1
#   LastChange: 2016-03-05 16:09:07
#      History:
============================================================================= */


#include<stdio.h>
#include<time.h>


#define MESSAGE_LOG(tag, message) lc_log(__FILE__, __LINE__, tag, message)

#define INFO_LOG(fmt, ...)  print_time(); fprintf(stdout, "[%s] %s(%d):"fmt, tag_name[_INFO], __FILE__, __LINE__, __VA_ARGS__)

#ifdef DEBUG
#define DEBUG_LOG(fmt, ...)  print_time(); fprintf(stdout, "[%s] %s(%d):"fmt, tag_name[_DEBUG], __FILE__, __LINE__, __VA_ARGS__)
#else
#define DEBUG_LOG(fmt, ...) // nothing
#endif

#define WARNING_LOG(fmt, ...)  print_time(); fprintf(stdout, "[%s] %s(%d):"fmt, tag_name[_WARNING], __FILE__, __LINE__, __VA_ARGS__)

#define ERROR_LOG(fmt, ...)  print_time(); fprintf(stdout, "[%s] %s(%d):"fmt, tag_name[_ERROR], __FILE__, __LINE__, __VA_ARGS__)

typedef enum {
    _INFO,
    _DEBUG,
    _WARNING,
    _ERROR,
}log_tag;


const char* tag_name[] = {
    "INFO",
    "DEBUG",
    "WARNING",
    "ERROR"
};


void print_time() {
    time_t now = time(NULL);
    struct tm * timeinfo = localtime(&now);
    char time_str[32];

    strftime(time_str, 32, "%D %T", timeinfo);
    fprintf(stdout, "[%s]", time_str);
}


// depecated ...
//void lc_log(const char* filename, int line, log_tag tag, const char* message) {
//    time_t now = time(NULL);
//    struct tm * timeinfo = localtime(&now);
//    char time_str[32];
//
//    strftime(time_str, 32, "%D %T", timeinfo);
//    switch(tag) {
//        case INFO:
//            fprintf(stdout, "[%s][%s] %s(%d):%s\n", time_str, tag_name[tag], filename, line, message);
//            break;
//        case WARNING:
//        case ERROR:
//            fprintf(stderr, "[%s][%s] %s(%d):%s\n", time_str, tag_name[tag], filename, line, message);
//            break;
//        default:
//            // nothing happens
//            break;
//    }
//}



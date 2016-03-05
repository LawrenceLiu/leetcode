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

//#define LOG(tag, message) log(tag, message)
#define LOG(tag, message) lc_log(__FILE__, __LINE__, tag, message)

typedef enum {
    INFO,
    WARNING,
    ERROR,
}log_tag;


const char* tag_name[] = {
    "INFO",
    "WARNING",
    "ERROR"
};

void lc_log(const char* filename, int line, log_tag tag, const char* message) {
    time_t now = time(NULL);
    struct tm * timeinfo = localtime(&now);
    switch(tag) {
        case INFO:
            fprintf(stdout, "[%s][%s]%s(%d):%s\n", asctime(timeinfo), tag_name[tag], filename, line, message);
            break;
        case WARNING:
        case ERROR:
            fprintf(stderr, "[%s][%s]%s(%d):%s\n", asctime(timeinfo), tag_name[tag], filename, line, message);
            break;
        default:
            // nothing happens
            break;
    }
}

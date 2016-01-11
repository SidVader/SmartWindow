/**
 * written by Simon Stallbaum
 * header for write_read.cpp
 */
#define BUF 255

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "stddef.h"

#ifdef XCOMPILE
// when Cross-Compiling
#include "xcompile/headers/mysql.h"
#else
// when compiling locally on RasPi
#include <mysql/mysql.h>
#endif

bool check_error(MYSQL *mysql);
void connect(MYSQL *mysql);
void close_session(MYSQL *mysql);
bool write_in_db(MYSQL *mysql,const char *db, const char *table, const char *value);
bool get_latest_value_bool(MYSQL *mysql, const char *db, const char *table, bool *succeeded);
double get_latest_value_double(MYSQL *mysql, const char *db, const char *table, bool *succeeded);
int get_latest_value_int(MYSQL *mysql, const char *db, const char *table, bool *succeeded);

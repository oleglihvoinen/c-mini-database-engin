#ifndef MINIDB_H
#define MINIDB_H
#include <stdint.h>
#define MINIDB_NAME_SIZE 64
#define MINIDB_ACTIVE 1
#define MINIDB_DELETED 0
typedef struct { int32_t id; uint8_t active; char name[MINIDB_NAME_SIZE]; double value; } DbRecord;
int db_insert(const char *path,const DbRecord *record);
int db_select(const char *path,int32_t id,DbRecord *out);
int db_delete(const char *path,int32_t id);
int db_list(const char *path);
#endif

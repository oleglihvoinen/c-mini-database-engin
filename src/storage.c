#include "minidb.h"
#include <stdio.h>
int db_insert(const char *path,const DbRecord *record){DbRecord existing;if(db_select(path,record->id,&existing)==1)return 2;FILE *f=fopen(path,"ab");if(!f)return -1;int ok=fwrite(record,sizeof(*record),1,f)==1;fclose(f);return ok?0:-1;}
int db_select(const char *path,int32_t id,DbRecord *out){FILE *f=fopen(path,"rb");if(!f)return 0;DbRecord r;while(fread(&r,sizeof(r),1,f)==1)if(r.active==MINIDB_ACTIVE&&r.id==id){*out=r;fclose(f);return 1;}fclose(f);return 0;}
int db_delete(const char *path,int32_t id){FILE *f=fopen(path,"r+b");if(!f)return 0;DbRecord r;while(fread(&r,sizeof(r),1,f)==1)if(r.active==MINIDB_ACTIVE&&r.id==id){r.active=MINIDB_DELETED;fseek(f,-(long)sizeof(r),SEEK_CUR);int ok=fwrite(&r,sizeof(r),1,f)==1;fclose(f);return ok?1:-1;}fclose(f);return 0;}
int db_list(const char *path){FILE *f=fopen(path,"rb");if(!f)return 0;DbRecord r;int count=0;while(fread(&r,sizeof(r),1,f)==1)if(r.active==MINIDB_ACTIVE){printf("%d\t%s\t%.2f\n",r.id,r.name,r.value);count++;}fclose(f);return count;}

#include "minidb.h"
#include <stdio.h>
#include <string.h>
static void usage(void){puts("Commands: INSERT <id> <name> <value> | SELECT <id> | DELETE <id> | LIST | QUIT");}
int main(int argc,char **argv){const char *path=argc>1?argv[1]:"minidb.dat";char cmd[16];usage();while(scanf("%15s",cmd)==1){if(!strcmp(cmd,"INSERT")){DbRecord r={0};r.active=MINIDB_ACTIVE;if(scanf("%d %63s %lf",&r.id,r.name,&r.value)!=3){puts("BAD INPUT");continue;}int rc=db_insert(path,&r);puts(rc==0?"OK":rc==2?"DUPLICATE ID":"ERROR");}else if(!strcmp(cmd,"SELECT")){int id;DbRecord r;if(scanf("%d",&id)!=1)continue;if(db_select(path,id,&r))printf("%d\t%s\t%.2f\n",r.id,r.name,r.value);else puts("NOT FOUND");}else if(!strcmp(cmd,"DELETE")){int id;if(scanf("%d",&id)!=1)continue;puts(db_delete(path,id)==1?"OK":"NOT FOUND");}else if(!strcmp(cmd,"LIST"))db_list(path);else if(!strcmp(cmd,"QUIT"))break;else usage();}return 0;}

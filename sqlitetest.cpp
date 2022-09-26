
#include "stdio.h"


#include "sqlite3.h"

static int sqlCALLBACK(void *Notused,int argc, char ** argv, char ** azColName)
{
  for (int i= 0;i <argc;i++)
  {
    printf( "%s = %s  \n", azColName[i],argv[i] ? argv[i]:"NULL");
  }
  return 0;
}

void sqlitetest()
{
  char *errorMsg = NULL;
  sqlite3 *pdb = NULL;
  int b =  sqlite3_open("d:\\1.db", &pdb);
  if(b)
  {
    sqlite3_close_v2(pdb);
    return;
  }
  else
  {
    int rc = sqlite3_exec(pdb,
                          "create table t1 ( c1 integer, c2 integer,c3 integer);",
                          sqlCALLBACK, 
                          0,
                          &errorMsg);

    rc = sqlite3_exec(pdb,
                          "insert into t1 values(1,2,3);",
                          sqlCALLBACK,
                          0,
                          &errorMsg);

    rc = sqlite3_exec(pdb,
                          "insert into t1 values(4,5,6);",
                          sqlCALLBACK,
                          0,
                          &errorMsg);

    rc = sqlite3_exec(pdb,
                      "insert into t1 values(7,8,9);",
                      sqlCALLBACK,
                      0,
                      &errorMsg);

    rc = sqlite3_exec(pdb,
                      "select * from t1;",
                      sqlCALLBACK,
                      0,
                      &errorMsg);

    if(rc != SQLITE_OK)
    {
      printf("%s\n",errorMsg);
      sqlite3_free(errorMsg);
    }
  }

  sqlite3_close_v2(pdb);

  return;
}
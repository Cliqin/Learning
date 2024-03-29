#include "print.h"
#include "init.h"
#include "thread.h"
#include "interrupt.h"
#include "console.h"
#include "process.h"
#include "syscall-init.h"
#include "syscall.h"
#include "stdio.h"
#include "memory.h"
#include "dir.h"
#include "fs.h"

void k_thread_a(void *);
void k_thread_b(void *);
void u_prog_a(void);
void u_prog_b(void);

int main(void)
{
   put_str("I am kernel\n");
   init_all();
   /********  测试代码  ********/
   printf("/myDir content before delete /myDir/subDir:\n");
   struct dir *dir = sys_opendir("/myDir/");
   char *type = NULL;
   struct dir_entry *dir_e = NULL;
   while ((dir_e = sys_readdir(dir)))
   {
      if (dir_e->f_type == FT_REGULAR)
      {
         type = "regular";
      }
      else
      {
         type = "directory";
      }
      printf("HEJIANHUI       %s   %s\n", type, dir_e->filename);
   }
   printf("try to delete nonempty directory /myDir/subDir\n");
   if (sys_rmdir("/myDir/subDir") == -1)
   {
      printf("HEJIANHUI sys_rmdir: /myDir/subDir delete fail!\n");
   }

   printf("HEJIANHUI try to delete /myDir/subDir/file2\n");
   if (sys_rmdir("/myDir/subDir/file2") == -1)
   {
      printf("HEJIANHUI sys_rmdir: /myDir/subDir/file2 delete fail!\n");
   }
   if (sys_unlink("/myDir/subDir/file2") == 0)
   {
      printf("HEJIANHUI sys_unlink: /myDir/subDir/file2 delete done\n");
   }

   printf("try to delete directory /myDir/subDir again\n");
   if (sys_rmdir("/myDir/subDir") == 0)
   {
      printf("HEJIANHUI /myDir/subDir delete done!\n");
   }

   printf("HEJIANHUI /myDir content after delete /myDir/subDir:\n");
   sys_rewinddir(dir);
   while ((dir_e = sys_readdir(dir)))
   {
      if (dir_e->f_type == FT_REGULAR)
      {
         type = "regular";
      }
      else
      {
         type = "directory";
      }
      printf("      %s   %s\n", type, dir_e->filename);
   }

   /********  测试代码  ********/
   while (1)
      ;
   return 0;
}

/* 在线程中运行的函数 */
void k_thread_a(void *arg)
{
   void *addr1 = sys_malloc(256);
   void *addr2 = sys_malloc(255);
   void *addr3 = sys_malloc(254);
   console_put_str(" thread_a malloc addr:0x");
   console_put_int((int)addr1);
   console_put_char(',');
   console_put_int((int)addr2);
   console_put_char(',');
   console_put_int((int)addr3);
   console_put_char('\n');

   int cpu_delay = 100000;
   while (cpu_delay-- > 0)
      ;
   sys_free(addr1);
   sys_free(addr2);
   sys_free(addr3);
   while (1)
      ;
}

/* 在线程中运行的函数 */
void k_thread_b(void *arg)
{
   void *addr1 = sys_malloc(256);
   void *addr2 = sys_malloc(255);
   void *addr3 = sys_malloc(254);
   console_put_str(" thread_b malloc addr:0x");
   console_put_int((int)addr1);
   console_put_char(',');
   console_put_int((int)addr2);
   console_put_char(',');
   console_put_int((int)addr3);
   console_put_char('\n');

   int cpu_delay = 100000;
   while (cpu_delay-- > 0)
      ;
   sys_free(addr1);
   sys_free(addr2);
   sys_free(addr3);
   while (1)
      ;
}

/* 测试用户进程 */
void u_prog_a(void)
{
   void *addr1 = malloc(256);
   void *addr2 = malloc(255);
   void *addr3 = malloc(254);
   printf(" prog_a malloc addr:0x%x,0x%x,0x%x\n", (int)addr1, (int)addr2, (int)addr3);

   int cpu_delay = 100000;
   while (cpu_delay-- > 0)
      ;
   free(addr1);
   free(addr2);
   free(addr3);
   while (1)
      ;
}

/* 测试用户进程 */
void u_prog_b(void)
{
   void *addr1 = malloc(256);
   void *addr2 = malloc(255);
   void *addr3 = malloc(254);
   printf(" prog_b malloc addr:0x%x,0x%x,0x%x\n", (int)addr1, (int)addr2, (int)addr3);

   int cpu_delay = 100000;
   while (cpu_delay-- > 0)
      ;
   free(addr1);
   free(addr2);
   free(addr3);
   while (1)
      ;
}

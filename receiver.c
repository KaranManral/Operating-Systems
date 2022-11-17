#include "shared_mem.h"
int main()
{
/* name of the shared memory object */
const char *name = "OS";
/* shared memory file descriptor */
int shmfd;
/* pointer to shared memory obect */
void *ptr;
/* open the shared memory object */
shmfd = shmopen(name, O_RDONLY, 0666);
/* memory map the shared memory object */
ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shmfd, 0);
/* read from the shared memory object */
printf("%s",(char *)ptr);
/* remove the shared memory object */
shm_unlink(name);
return 0;
}
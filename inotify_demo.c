#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <unistd.h>

#define EVENT_SIZE (sizeof(struct inotify_event))
#define BUF_LEN (1024 * (EVENT_SIZE + 16))

int
main(int argc, char *argv[])
{
	int length, i = 0;
	int fd, wd;
	char buffer[BUF_LEN];
	
	fd = inotify_init();

	if (fd < 0)
		perror("inotify_init");
	
	wd = inotify_add_watch(fd, "./", IN_MODIFY | IN_CREATE | IN_DELETE);
	length = read(fd, buffer, BUF_LEN);

	if (length < 0)
		perror("read");

	while (i < length)
	{
		struct inotify_event *event = (struct inotify_event *) & buffer[i];
		if(event->mask & IN_CREATE)
			printf("The file %s was created\n", event->name);
		if(event->mask & IN_MODIFY)
			printf("The file %s was modify\n", event->name);
		if(event->mask & IN_DELETE)
			printf("The file %s was delete\n", event->name);

		i+=EVENT_SIZE + event->len;
	}
		// I don't know why we need to declare void at the begin.
		(void) inotify_rm_watch(fd, wd);
		(void)close(fd);
		
	return 0;
}


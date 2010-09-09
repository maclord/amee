#include <stdio.h>
#include <time.h>
#include <sys/times.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <assert.h>

struct input_event {
    struct timeval time;
    uint16_t type;
    uint16_t code;
    int32_t value;
};

int read_all(int fd, char *buf, int count)
{
    int n_read = 0;
    while (n_read != count) {
        int result = read(fd, buf + n_read, count - n_read);
        if (result < 0)
            return result;
        else if (result == 0)
            return n_read;
        n_read += result;
    }
    return n_read;
}

void print_bar(int l)
{
	char buf[l+1];
	int i;
	for(i = 0; i < l; i++)
	{
		buf[i] = '#';
		printf("#");
	}
	buf[l] = '\0';
//	printf("%s\n",buf);
	printf("\n");
}

int main(int argc, char *argv[])
{
    int fd;
    struct input_event ev;

    assert(16 == sizeof(struct input_event));

    if (argc != 2) {
        fprintf(stderr, "missing /dev/input/XXX\n");
        return 1;
    }

int x, y, z;

        if ((fd = open(argv[1], O_RDONLY)) == -1) {
            perror("open");
            return 1;
        }

    while (1) {
        int ret = read_all(fd, (char *) &ev, sizeof(struct input_event));
        if (ret != sizeof(struct input_event)) {
            fprintf(stderr, "ret == %d\n", ret);
            perror("read");
            return 1;
        }
//        printf("type:%u code:%u value:%d\n", ev.type, ev.code, ev.value);

	int x, y, z;
	if(ev.type == 3)
	{
		if(ev.code == 0)
	        {
			x = ev.value;
        	} else if(ev.code == 1)
                {
                        y = ev.value;
                } else if(ev.code == 2)
                {
                        z = ev.value;
                }
	} else if(ev.type == 0 && ev.code == 0)
	{
		printf("%d, %d, %d\n", x, y, z);
	}
//	print_bar(ev.value);
        usleep(50000);  /* 2 reads per second, you might want to read more */
    }
        close(fd);

    return 0;
}

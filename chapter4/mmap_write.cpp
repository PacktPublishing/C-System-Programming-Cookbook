#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>

#define FILEPATH "mmapped.txt"
#define NUM_OF_ITEMS_IN_FILE  (1000)
#define FILESIZE (NUM_OF_ITEMS_IN_FILE * sizeof(int))

int main(int argc, char *argv[])
{
    int fd = open(FILEPATH, O_RDWR | O_CREAT | O_TRUNC, (mode_t)0600);
    if (fd == -1) 
    {
	std::cout << "Error opening file " << FILEPATH << std::endl;
	return 1;
    }

    int result = lseek(fd, FILESIZE-1, SEEK_SET);
    if (result == -1) 
    {
	close(fd);
	std::cout << "Error calling lseek " << std::endl;
	return 2;
    }

    result = write(fd, "", 1);
    if (result != 1) 
    {
	close(fd);
	std::cout << "Error writing into the file  " << std::endl;
	return 3;
    }

    int* map = (int*) mmap(0, FILESIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) 
    {
	close(fd);
	std::cout << "Error mapping the file " << std::endl;
	return 4;
    }

    for (int i = 1; i <=NUM_OF_ITEMS_IN_FILE; ++i) 
	map[i] = 2 * i; 

    if (munmap(map, FILESIZE) == -1)
	std::cout << "Error un-mapping" << std::endl;

    close(fd);
    return 0;
}


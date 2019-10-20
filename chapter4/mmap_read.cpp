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
    int fd = open(FILEPATH, O_RDONLY);
    if (fd == -1) 
    {
	std::cout << "Error opening file " << FILEPATH << std::endl;
	return 1;
    }

    int* map = (int*) mmap(0, FILESIZE, PROT_READ, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) 
    {
	close(fd);
	std::cout << "Error mapping the file " << std::endl;
	return 4;
    }

    for (int i = 1; i <= NUM_OF_ITEMS_IN_FILE; ++i)
    	std::cout << "i = " << map[i] << std::endl; 

    if (munmap(map, FILESIZE) == -1) {
	std::cout << "Error un-mapping" << std::endl;
    }

    close(fd);
    return 0;
}


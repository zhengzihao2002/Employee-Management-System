# tell them that run and clean are not file names
.PHONY: run clean

# compiler
CC=g++

# the output
TARGET = runner

# the input
SOURCES=runner.cpp System.cpp useful.cpp employee.cpp boss.cpp manager.cpp

# flags
CFLAGS = -std=c++11




#sample: sample.cpp
#	g++ -o ems ems.cpp workerManager.cpp
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)


# ./sample
run: $(TARGET)
	./$(TARGET)

# removes the exe file
clean:
	rm -f $(TARGET)

# "make all" is the command to run this file
all: $(TARGET) run clean






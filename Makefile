#Bee Bencze
#bencze@pdx.edu
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g  

SRC = main.cpp BST.cpp contestants.cpp
HDR = BST.h contestants.h
OBJ = $(SRC:.cpp=.o)

EXEC = output

ZIP_NAME = bencze_cs302_005_program3.zip

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.d: %.cpp
	$(CXX) -M $(CXXFLAGS) $< > $@

-include $(OBJ:.o=.d)

zip: $(EXEC)
	zip -r $(ZIP_NAME) $(SRC) $(HDR) $(EXEC) README.md Makefile

clean:
	rm -f $(OBJ) $(OBJ:.o=.d) $(EXEC) $(ZIP_NAME)

.PHONY: clean zip
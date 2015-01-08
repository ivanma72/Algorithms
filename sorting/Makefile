#Default Flags
FLAGS = -std=c++11 -Wall -Werror -g

all: insertion selection heap quick merge

insertion: insertion_sort.cpp
	g++ $(FLAGS) insertion_sort.cpp -o insertion

selection: selection_sort.cpp
	g++ $(FLAGS) selection_sort.cpp -o selection

heap: heap_sort.h heap_sort.cpp main.cpp
	g++ $(FLAGS) heap_sort.cpp main.cpp -o heap

quick: quick_sort.cpp
	g++ $(FLAGS) quick_sort.cpp -o quick

merge: merge_sort.cpp
	g++ $(FLAGS) merge_sort.cpp -o merge

clean:
	rm -f *.o insertion selection heap quick merge

findtopk: findtopk.c
	gcc -o findtopk findtopk.c

clean:
	rm -f findtopk

run: findtopk
	./findtopk 5 3 file1.txt file2.txt file3.txt output.txt

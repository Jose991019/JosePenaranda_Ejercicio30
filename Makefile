Resultado.gif: graficador.py datos.txt
	python graficador.py
    
datos.txt: a.out
	./a.out

a.out: AdvecLax.cpp
	g++ AdvecLax.cpp

clean:
	rm -rf *.out *.txt Resultado.gif
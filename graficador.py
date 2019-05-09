import matplotlib.pyplot as plt
import numpy as np
import imageio

Tiempo = np.array(range(201))*2/200
X = np.array(range(101))/100
Z = np.loadtxt('datos.txt')

filenames =[]
for tiempo in range(201):
    plt.figure(figsize = (3,3))
    plt.plot(X, Z[tiempo,:],)
    plt.xlabel('Posicion [metros]')
    plt.ylabel('U')
    plt.title('Tiempo: {0:.2f} segundos'.format(Tiempo[tiempo]))
    plt.grid()
    plt.xlim(0, 1)
    plt.ylim(-0.05, 0.05)
    plt.savefig('tiempo'+str(tiempo)+'.png',bbox_inches = "tight")
    filenames.append('tiempo'+str(tiempo)+'.png')
    plt.close()

images = []
for filename in filenames:
    images.append(imageio.imread(filename))
imageio.mimsave('Resultado.gif', images)
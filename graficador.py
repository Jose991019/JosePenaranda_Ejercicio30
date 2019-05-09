import matplotlib
import matplotlib.pyplot as plt
import numpy as np
import imageio

Tiempo = np.array(range(201))*2/200
X = np.array(range(101))/100
Z = np.loadtxt('datos.txt')

def plot_for_offset(tiempo):

    fig, ax = plt.subplots(figsize=(3,3))
    ax.plot(X, Z[tiempo,:])
    ax.grid()
    ax.set(xlabel='Posicion [metros]', ylabel='U',
           title='Tiempo: {} segundos'.format(Tiempo[tiempo]))
    ax.set_xlim(0, 1)

    fig.canvas.draw()
    image = np.frombuffer(fig.canvas.tostring_rgb(), dtype='uint8')
    image  = image.reshape(fig.canvas.get_width_height()[::-1] + (3,))

    return image

kwargs_write = {'fps':1.0, 'quantizer':'nq'}
imageio.mimsave('Resultado.gif', [plot_for_offset(i) for i in range(201)], fps=10)
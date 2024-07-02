# Fract-ol

![exemplary image](/img/mandelbrot.png)

## how to build it

1. <ins>Install glfw</ins>

   on OS: if you have homebrew, run **`brew install glfw`**

   on Linux: run **`sudo apt install glfw`**

   and remember the path you install it to!
   
2. <ins>clone this repository</ins> to someplace you like
   
3. <ins>set the right path in the Makefile to glfw</ins>: MLX = ... -lglfw -L "/opt/homebrew/Cellar/glfw/3.4/lib"

  --> here you replace the path in the embedded quotes. It leads to /lib in /glfw directory
  
  (find out the path by going into your glfw directory, cd into /lib and type **`pwd`**. What appears is the right path to use)
  
3. run **`make`**
4. run **`./fractol`**
5. then choose an option e.g. **`./fractol Mandelbrot`**

## how it works

 - zoom in with your mouse indefinitely
 - leftklick to the point you want to have in your center
 - change the colors back and forth by pressing 1 / 2

## thats it, thanks for checking out <3

![exemplary image](/img/julia.png)

### build

you need a mac with an intel chip for this project

1. Install glfw
2. set the right path to glfw in the Makefile at: MLX = MLX42/libmlx42.a -I include -lglfw -L "/opt/homebrew/Cellar/glfw/3.4/lib/"

  --> here you replace the path in the embedded quotes
  
  (find out the path by going into your glfw directory, cd into /lib and type **`pwd`**. What appears is the right path to use)
  
3. run **`make`**
4. run **`./fractol`**
   

# Fractal
Environment : MacOS - Yosemite

A fractal is an object or quantity that displays self-similarity on all scales. The object need not exhibit exactly the same structure at all scales, but the same "type" of structures. 
This project aims to represent the most famouses ones : Mandelbrot and Julia.
Julia is a variation of Mandelbrot.

In theory, a fractal repeats the same structures to the infinite, it is a never-ending pattern.
Unfortunately, using only C with no libraries there is no (easy) way to make a real never-ending fractal due to float limitations.
There is a degree of precision that you can only reach with a math library.

Mandelbrot is self-similar at magnified scales, but small scale details are not identical to the whole. In fact, the Mandelbrot set is infinitely complex.
Yet the process of generating it is based on an extremely simple equation involving complex numbers.

The test is based on the equation Z = Z2 +  C.
C represents a constant number, meaning that it does not change during the testing process; at least, on Mandelbrot. On Julia, C changes depending on the mouse position on the screen.
As we iterate our equation, Z changes and the magnitude of Z also changes. 
The magnitude of Z will do one of two things. 
It will either stay equal to or below 2 forever, or it will eventually surpass two. 
Once the magnitude of Z surpasses 2, it will increase forever. 
In the first case, where the magnitude of Z stays small, the number we are testing is part of the Mandelbrot set.
If the magnitude of Z eventually surpasses 2, the number is not part of the Mandelbrot set.
The colors are added to the points that are not inside the set, according to how many iterations were required before the magnitude of Z surpassed two. 
Not only do colors enhance the image aesthetically, they help to highlight parts of the Mandelbrot set that are too small to show up in the graph.
The higher the number of max iterations is, the faster we can render an image, but we lose precision and deepness.

Well, that was the secret of making a fractal. At least Mandelbrot and Julia.

Technologies used :
- C
- MinilibX
- Complex numbers

Keys :
'}' next panel.
'{' previous panel.
'-' less iterations.
'+' more iterations.

There are 7 fractal panel.
- Mandelbrot
- Julia
- Tree
  This one is a funny one i wanted to try. In fact in real life, a tree is kind of a fractal.
  On this one each branch has two branche, the left one and the right one.
  You can change branches angles, number of branches N (as there's always two branches, modifying N means 2^N branches) and zoom.
- Triforce, which is a variation of Mandelbrot.
- Mandelbrot ^3
- Burning Ship, i advise you to magnify the little ship on the left.
- Full mandelbrot set in which you can change the equation exponent. (Takes some times to calculate as this one really use C complex numbers when others use usual integers.)
  Use < and > to modify exponent.

[![Fractal](http://img.youtube.com/vi/nKS6YQt9B0U/1.jpg)](https://youtu.be/nKS6YQt9B0U "Fractal")

PS : It takes some time to load highly magnified fractals as calculs need more precision. 

(Won't work on Linux, this version of MinilibX -the unofficial graphical library that i used- is only for MacOS)

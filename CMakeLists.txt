cmake_minimum_required(VERSION 3.23)
project(Fractal_Images)

set(CMAKE_CXX_STANDARD 20)

add_executable(Fractal_Images main.cpp BitmapFileHeader.h BitmapInfoHeader.h Bitmap.cpp Bitmap.h Mandelbrot.cpp Mandelbrot.h ZoomInfo.h ZoomInfoList.cpp ZoomInfoList.h FractalService.cpp FractalService.h)

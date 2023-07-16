clang++ src/*.c -Iheaders \
    -Ithird_party/include\
    -Lthird_party/libs -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi -lm\
    -G -o bin/app

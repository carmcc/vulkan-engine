CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
GLSLC = /usr/bin/glslc

a.out: *.cpp *.hpp
	g++ $(CFLAGS) -o vulkan-engine *.cpp $(LDFLAGS)

.PHONY: test clean

test: vulkan-engine
	./vulkan-engine

clean:
	rm -f vulkan-engine
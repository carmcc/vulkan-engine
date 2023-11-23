CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
GLSLC = /usr/bin/glslc

vulkan-engine: *.cpp *.hpp
	g++ $(CFLAGS) -o vulkan-engine *.cpp $(LDFLAGS)

# create list of all spv files and set as dependency
vertSources = $(shell find ./shaders -type f -name "*.vert")
vertObjFiles = $(patsubst %.vert, %.vert.spv, $(vertSources))
fragSources = $(shell find ./shaders -type f -name "*.frag")
fragObjFiles = $(patsubst %.frag, %.frag.spv, $(fragSources))

TARGET = vulkan-engine
$(TARGET): $(vertObjFiles) $(fragObjFiles)
$(TARGET): *.cpp *.hpp
	g++ $(CFLAGS) -o $(TARGET) *.cpp $(LDFLAGS)

# make shader targets
%.spv: %
	${GLSLC} $< -o $@
.PHONY: test clean

test: vulkan-engine
	./vulkan-engine

clean:
	rm -f vulkan-engine
	rm -f *.spv
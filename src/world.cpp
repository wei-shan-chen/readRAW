#include "world.h"

struct World world = {};

void create_world() {
    world.cube = {
        //       position                  normal
        Vertex{  { 0.0f,  0.0f,  0.0f, } , { 0.0f,  0.0f, -1.0f} },
        Vertex{  { 1.0f,  0.0f,  0.0f, } , { 0.0f,  0.0f, -1.0f} },
        Vertex{  { 1.0f,  1.0f,  0.0f, } , { 0.0f,  0.0f, -1.0f} },
        Vertex{  { 1.0f,  1.0f,  0.0f, } , { 0.0f,  0.0f, -1.0f} },
        Vertex{  { 0.0f,  1.0f,  0.0f, } , { 0.0f,  0.0f, -1.0f} },
        Vertex{  { 0.0f,  0.0f,  0.0f, } , { 0.0f,  0.0f, -1.0f} },

        Vertex{  { 0.0f,  0.0f,  1.0f, } , { 0.0f,  0.0f,  1.0f} },
        Vertex{  { 1.0f,  0.0f,  1.0f, } , { 0.0f,  0.0f,  1.0f} },
        Vertex{  { 1.0f,  1.0f,  1.0f, } , { 0.0f,  0.0f,  1.0f} },
        Vertex{  { 1.0f,  1.0f,  1.0f, } , { 0.0f,  0.0f,  1.0f} },
        Vertex{  { 0.0f,  1.0f,  1.0f, } , { 0.0f,  0.0f,  1.0f} },
        Vertex{  { 0.0f,  0.0f,  1.0f, } , { 0.0f,  0.0f,  1.0f} },

        Vertex{  { 0.0f,  1.0f,  1.0f, } , {-1.0f,  0.0f,  0.0f} },
        Vertex{  { 0.0f,  1.0f,  0.0f, } , {-1.0f,  0.0f,  0.0f} },
        Vertex{  { 0.0f,  0.0f,  0.0f, } , {-1.0f,  0.0f,  0.0f} },
        Vertex{  { 0.0f,  0.0f,  0.0f, } , {-1.0f,  0.0f,  0.0f} },
        Vertex{  { 0.0f,  0.0f,  1.0f, } , {-1.0f,  0.0f,  0.0f} },
        Vertex{  { 0.0f,  1.0f,  1.0f, } , {-1.0f,  0.0f,  0.0f} },

        Vertex{  { 1.0f,  1.0f,  1.0f, } , { 1.0f,  0.0f,  0.0f} },
        Vertex{  { 1.0f,  1.0f,  0.0f, } , { 1.0f,  0.0f,  0.0f} },
        Vertex{  { 1.0f,  0.0f,  0.0f, } , { 1.0f,  0.0f,  0.0f} },
        Vertex{  { 1.0f,  0.0f,  0.0f, } , { 1.0f,  0.0f,  0.0f} },
        Vertex{  { 1.0f,  0.0f,  1.0f, } , { 1.0f,  0.0f,  0.0f} },
        Vertex{  { 1.0f,  1.0f,  1.0f, } , { 1.0f,  0.0f,  0.0f} },

        Vertex{  { 0.0f,  0.0f,  0.0f, } , { 0.0f, -1.0f,  0.0f} },
        Vertex{  { 1.0f,  0.0f,  0.0f, } , { 0.0f, -1.0f,  0.0f} },
        Vertex{  { 1.0f,  0.0f,  1.0f, } , { 0.0f, -1.0f,  0.0f} },
        Vertex{  { 1.0f,  0.0f,  1.0f, } , { 0.0f, -1.0f,  0.0f} },
        Vertex{  { 0.0f,  0.0f,  1.0f, } , { 0.0f, -1.0f,  0.0f} },
        Vertex{  { 0.0f,  0.0f,  0.0f, } , { 0.0f, -1.0f,  0.0f} },

        Vertex{  { 0.0f,  1.0f,  0.0f, } , { 0.0f,  1.0f,  0.0f} },
        Vertex{  { 1.0f,  1.0f,  0.0f, } , { 0.0f,  1.0f,  0.0f} },
        Vertex{  { 1.0f,  1.0f,  1.0f, } , { 0.0f,  1.0f,  0.0f} },
        Vertex{  { 1.0f,  1.0f,  1.0f, } , { 0.0f,  1.0f,  0.0f} },
        Vertex{  { 0.0f,  1.0f,  1.0f, } , { 0.0f,  1.0f,  0.0f} },
        Vertex{  { 0.0f,  1.0f,  0.0f, } , { 0.0f,  1.0f,  0.0f} },
    };



    world.square = {
            Vertex{ { 0.0f, 0.0f, 0.0f}},
            Vertex{ { 1.0f, 0.0f, 0.0f}},
            Vertex{ { 1.0f, 1.0f, 0.0f}},
            Vertex{ { 0.0f, 1.0f, 0.0f}},
    };
    world.line = {
            Vertex{ { 0.0f, 0.0f, 0.0}},
            Vertex{ { 0.1f, 0.0f, 0.0f}},
            Vertex{ { 0.1f, 0.005f, 0.0f}},
            Vertex{ { 0.0f, 0.005f, 0.0f}},
    };
    world.squ_indices = {
        0, 1, 2, // first triangle
        0, 2, 3  // second triangle
    };
    world.tri= {
		Vertex{ { 0.5f, -0.5f, 0.0f}},
        Vertex{ {-0.5f, -0.5f, 0.0f}},
        Vertex{ { 0.0f,  0.5f, 0.0f}}
	};

}

void destroy_world() {

    world.square.clear();
    world.line.clear();
    world.squ_indices.clear();
    world.tri.clear();
    world.cube.clear();
}
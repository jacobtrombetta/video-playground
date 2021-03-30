#include <stdio.h>
#include <GLFW/glfw3.h>

int main( int argv, const char** argc){
    GLFWwindow* window;

    if ( !glfwInit() ){
        printf( "Couldn't init GLFW\n" );
        return 1;
    }
    
    window = glfwCreateWindow( 640, 480, "Hello world", nullptr, nullptr );
    if ( !window ){
        printf( "Couldn't init GLFW\n" );
        return 1;
    }
    
    unsigned char* data = new unsigned char[ 100 * 100 * 3 ];
    for ( int row = 0; row < 100; row++ )
    {
        for ( int col = 0; col < 100; col++ )
        {
            data[ row * 100 * 3 + col * 3     ] = 0xff;
            data[ row * 100 * 3 + col * 3 + 1 ] = 0x00;
            data[ row * 100 * 3 + col * 3 + 2 ] = 0x00;
        }
    }
            
    
    glfwMakeContextCurrent( window );
    while ( !glfwWindowShouldClose( window ) ){
        
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        glDrawPixels( 100, 100, GL_RGB, GL_UNSIGNED_BYTE, data );
        glfwSwapBuffers( window );
        
        glfwWaitEvents();
    }
        

    return 0;
}

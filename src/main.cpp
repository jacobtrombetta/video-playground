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
    
    for ( int row = 25; row < 75; row++ )
    {
        for ( int col = 25; col < 75; col++ )
        {
            data[ row * 100 * 3 + col * 3     ] = 0x00;
            data[ row * 100 * 3 + col * 3 + 1 ] = 0x00;
            data[ row * 100 * 3 + col * 3 + 2 ] = 0xff;
        }
    }
    
    glfwMakeContextCurrent( window );
    
    GLuint tex_handle;
    glGenTextures( 1, &tex_handle );
    glBindTexture( GL_TEXTURE_2D, tex_handle );
    glPixelStorei( GL_UNPACK_ALIGNMENT, 1 );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
    glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, 100, 100, 0, GL_RGB, GL_UNSIGNED_BYTE, data );
    
    
    while ( !glfwWindowShouldClose( window ) ){
        
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        
        // Set up orphographic projection.
        int window_width, window_height;
        glfwGetFramebufferSize( window, &window_width, &window_height );
        glMatrixMode( GL_PROJECTION );
        glLoadIdentity();
        glOrtho( 0, window_width, 0, window_height, -1, 1 );
        glMatrixMode( GL_MODELVIEW );
        
        // Render whatever you want
        glEnable( GL_TEXTURE_2D );
        glBindTexture( GL_TEXTURE_2D, tex_handle );
        glBegin( GL_QUADS );
            glTexCoord2d( 0, 0 ); glVertex2i(   0,   0 );
            glTexCoord2d( 1, 0 ); glVertex2i( 100,   0 );
            glTexCoord2d( 1, 1 ); glVertex2i( 100, 100 );
            glTexCoord2d( 0, 1 ); glVertex2i(   0, 100 );
        glEnd();
        glDisable( GL_TEXTURE_2D );
        
        glfwSwapBuffers( window );
        glfwWaitEvents();
    }
        

    return 0;
}

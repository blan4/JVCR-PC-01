project(JVCR-ECM-01-EXAMPLE C)

add_executable(JVCR-ECM-01-EXAMPLE main.c)

target_link_libraries(JVCR-ECM-01-EXAMPLE ${OPENGL_gl_LIBRARY} glfw m JVCR-ECM-01 ${PNG_LIBRARY})
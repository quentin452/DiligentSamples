"//  ---------------------------------------------------------------------------\n"
"//\n"
"//  @file       TextVS.glsl\n"
"//  @author     Egor Yusov\n"
"//	@brief		Source code of the TextVS OpenGL vertex shader\n"
"//\n"
"//  ---------------------------------------------------------------------------\n"
" \n"
"uniform Constants\n"
"{\n"
"    vec4 g_Offset;\n"
"    vec4 g_CstColor;\n"
"};\n"
"\n"
"// Shaders for text\n"
"\n"
"layout( location = 0 ) in vec4 in_pos;\n"
"layout( location = 1 ) in vec4 in_color;\n"
"layout( location = 2 ) in vec2 in_tex;\n"
"\n"
"#if (GL_ES && __VERSION__ <= 300)\n"
"    // GLES3.0 only supports layout location qualifiers for VS inputs\n"
"    #define OUT_LOCATION(x)\n"
"#else\n"
"    // Compiling glsl to SPIRV with glslang will fail if locations are not specified\n"
"    #define OUT_LOCATION(x) layout(location = x)\n"
"#endif\n"
"\n"
"OUT_LOCATION(0) out vec4 Color;\n"
"OUT_LOCATION(1) out vec2 Tex;\n"
"\n"
"//To use any built-in input or output in the gl_PerVertex and\n"
"//gl_PerFragment blocks in separable program objects, shader code must\n"
"//redeclare those blocks prior to use. \n"
"//\n"
"// Declaring this block causes compilation error on NVidia GLES\n"
"#ifndef GL_ES\n"
"out gl_PerVertex\n"
"{\n"
"	vec4 gl_Position;\n"
"};\n"
"#endif\n"
"\n"
"void main()\n"
"{\n"
"    gl_Position = vec4(in_pos.xy + g_Offset.xy, 0.5, 1.0);\n"
"    Color = in_color; \n"
"    Tex = in_tex; \n"
"}\n"

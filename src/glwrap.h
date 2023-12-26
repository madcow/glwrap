#ifndef MAD_GLWRAP_H
#define MAD_GLWRAP_H

// OpenGL types and function retrieval
// Written by Leon Krieg <info@madcow.dev>
//
// Load the GLES subset of the OpenGL2.0 specification which
// gives us the largest compatibility and allows us to work
// with the modern shader pipeline (vertex/fragment only).
//
// The engine will never run on MacOS so no reason to handle
// anything related to the Apple OpenGL implementation here.

#ifndef __gl_h_
#define __gl_h_
#else
#error gl.h included before glwrap.h
#endif // __gl_h_

// ====================================
// GLWRAP FUNCTIONS
// ====================================

// Call glInit after a context was created
// and made current. This will then load all
// function pointers needed for OpenGL and
// return 0 on success or -1 on error.

int glInit(void);

#ifndef GLAPI
#define GLAPI extern
#endif // GLAPI

#ifndef APIENTRY
#ifndef _WIN32
#define APIENTRY
#else
#define APIENTRY __stdcall
#endif // _WIN32
#endif // APIENTRY

#ifndef APIENTRYP
#define APIENTRYP APIENTRY *
#endif // APIENTRYP

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// ====================================
// OPENGL TYPES
// ====================================

// Khronos Group header needed to ensure
// the correct type sizes for different
// processor architectures and systems.
#include "external/khrplatform.h"

typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef void GLvoid;
typedef khronos_int8_t GLbyte;
typedef khronos_uint8_t GLubyte;
typedef khronos_int16_t GLshort;
typedef khronos_uint16_t GLushort;
typedef int GLint;
typedef unsigned int GLuint;
typedef khronos_int32_t GLclampx;
typedef int GLsizei;
typedef khronos_float_t GLfloat;
typedef khronos_float_t GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void *GLeglClientBufferEXT;
typedef void *GLeglImageOES;
typedef char GLchar;
typedef char GLcharARB;
typedef unsigned int GLhandleARB;
typedef khronos_uint16_t GLhalf;
typedef khronos_uint16_t GLhalfARB;
typedef khronos_int32_t GLfixed;
typedef khronos_intptr_t GLintptr;
typedef khronos_intptr_t GLintptrARB;
typedef khronos_ssize_t GLsizeiptr;
typedef khronos_ssize_t GLsizeiptrARB;
typedef khronos_int64_t GLint64;
typedef khronos_int64_t GLint64EXT;
typedef khronos_uint64_t GLuint64;
typedef khronos_uint64_t GLuint64EXT;
typedef struct __GLsync *GLsync;
struct _cl_context;
struct _cl_event;
typedef void (APIENTRY *GLDEBUGPROC)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef void (APIENTRY *GLDEBUGPROCARB)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef void (APIENTRY *GLDEBUGPROCKHR)(GLenum source,GLenum type,GLuint id,GLenum severity,GLsizei length,const GLchar *message,const void *userParam);
typedef void (APIENTRY *GLDEBUGPROCAMD)(GLuint id,GLenum category,GLenum severity,GLsizei length,const GLchar *message,void *userParam);
typedef unsigned short GLhalfNV;
typedef GLintptr GLvdpauSurfaceNV;
typedef void (APIENTRY *GLVULKANPROCNV)(void);

// ====================================
// OPENGL CONSTANTS
// ====================================

#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_STENCIL_BUFFER_BIT 0x00000400
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_FALSE 0
#define GL_TRUE 1
#define GL_POINTS 0x0000
#define GL_LINES 0x0001
#define GL_LINE_LOOP 0x0002
#define GL_LINE_STRIP 0x0003
#define GL_TRIANGLES 0x0004
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRIANGLE_FAN 0x0006
#define GL_NEVER 0x0200
#define GL_LESS 0x0201
#define GL_EQUAL 0x0202
#define GL_LEQUAL 0x0203
#define GL_GREATER 0x0204
#define GL_NOTEQUAL 0x0205
#define GL_GEQUAL 0x0206
#define GL_ALWAYS 0x0207
#define GL_ZERO 0
#define GL_ONE 1
#define GL_SRC_COLOR 0x0300
#define GL_ONE_MINUS_SRC_COLOR 0x0301
#define GL_SRC_ALPHA 0x0302
#define GL_ONE_MINUS_SRC_ALPHA 0x0303
#define GL_DST_ALPHA 0x0304
#define GL_ONE_MINUS_DST_ALPHA 0x0305
#define GL_DST_COLOR 0x0306
#define GL_ONE_MINUS_DST_COLOR 0x0307
#define GL_SRC_ALPHA_SATURATE 0x0308
#define GL_NONE 0
#define GL_FRONT 0x0404
#define GL_BACK 0x0405
#define GL_FRONT_AND_BACK 0x0408
#define GL_NO_ERROR 0
#define GL_INVALID_ENUM 0x0500
#define GL_INVALID_VALUE 0x0501
#define GL_INVALID_OPERATION 0x0502
#define GL_OUT_OF_MEMORY 0x0505
#define GL_CW 0x0900
#define GL_CCW 0x0901
#define GL_LINE_WIDTH 0x0B21
#define GL_CULL_FACE 0x0B44
#define GL_CULL_FACE_MODE 0x0B45
#define GL_FRONT_FACE 0x0B46
#define GL_DEPTH_RANGE 0x0B70
#define GL_DEPTH_TEST 0x0B71
#define GL_DEPTH_WRITEMASK 0x0B72
#define GL_DEPTH_CLEAR_VALUE 0x0B73
#define GL_DEPTH_FUNC 0x0B74
#define GL_STENCIL_TEST 0x0B90
#define GL_STENCIL_CLEAR_VALUE 0x0B91
#define GL_STENCIL_FUNC 0x0B92
#define GL_STENCIL_VALUE_MASK 0x0B93
#define GL_STENCIL_FAIL 0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL 0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS 0x0B96
#define GL_STENCIL_REF 0x0B97
#define GL_STENCIL_WRITEMASK 0x0B98
#define GL_VIEWPORT 0x0BA2
#define GL_DITHER 0x0BD0
#define GL_BLEND 0x0BE2
#define GL_SCISSOR_BOX 0x0C10
#define GL_SCISSOR_TEST 0x0C11
#define GL_COLOR_CLEAR_VALUE 0x0C22
#define GL_COLOR_WRITEMASK 0x0C23
#define GL_UNPACK_ALIGNMENT 0x0CF5
#define GL_PACK_ALIGNMENT 0x0D05
#define GL_MAX_TEXTURE_SIZE 0x0D33
#define GL_MAX_VIEWPORT_DIMS 0x0D3A
#define GL_SUBPIXEL_BITS 0x0D50
#define GL_TEXTURE_2D 0x0DE1
#define GL_DONT_CARE 0x1100
#define GL_FASTEST 0x1101
#define GL_NICEST 0x1102
#define GL_BYTE 0x1400
#define GL_UNSIGNED_BYTE 0x1401
#define GL_SHORT 0x1402
#define GL_UNSIGNED_SHORT 0x1403
#define GL_INT 0x1404
#define GL_UNSIGNED_INT 0x1405
#define GL_FLOAT 0x1406
#define GL_INVERT 0x150A
#define GL_TEXTURE 0x1702
#define GL_DEPTH_COMPONENT 0x1902
#define GL_ALPHA 0x1906
#define GL_RGB 0x1907
#define GL_RGBA 0x1908
#define GL_KEEP 0x1E00
#define GL_REPLACE 0x1E01
#define GL_INCR 0x1E02
#define GL_DECR 0x1E03
#define GL_VENDOR 0x1F00
#define GL_RENDERER 0x1F01
#define GL_VERSION 0x1F02
#define GL_EXTENSIONS 0x1F03
#define GL_NEAREST 0x2600
#define GL_LINEAR 0x2601
#define GL_NEAREST_MIPMAP_NEAREST 0x2700
#define GL_LINEAR_MIPMAP_NEAREST 0x2701
#define GL_NEAREST_MIPMAP_LINEAR 0x2702
#define GL_LINEAR_MIPMAP_LINEAR 0x2703
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_REPEAT 0x2901
#define GL_POLYGON_OFFSET_UNITS 0x2A00
#define GL_POLYGON_OFFSET_FILL 0x8037
#define GL_POLYGON_OFFSET_FACTOR 0x8038
#define GL_TEXTURE_BINDING_2D 0x8069
#define GL_RGBA4 0x8056
#define GL_RGB5_A1 0x8057
#define GL_UNSIGNED_SHORT_4_4_4_4 0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1 0x8034
#define GL_UNSIGNED_SHORT_5_6_5 0x8363
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_ALIASED_LINE_WIDTH_RANGE 0x846E
#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE1 0x84C1
#define GL_TEXTURE2 0x84C2
#define GL_TEXTURE3 0x84C3
#define GL_TEXTURE4 0x84C4
#define GL_TEXTURE5 0x84C5
#define GL_TEXTURE6 0x84C6
#define GL_TEXTURE7 0x84C7
#define GL_TEXTURE8 0x84C8
#define GL_TEXTURE9 0x84C9
#define GL_TEXTURE10 0x84CA
#define GL_TEXTURE11 0x84CB
#define GL_TEXTURE12 0x84CC
#define GL_TEXTURE13 0x84CD
#define GL_TEXTURE14 0x84CE
#define GL_TEXTURE15 0x84CF
#define GL_TEXTURE16 0x84D0
#define GL_TEXTURE17 0x84D1
#define GL_TEXTURE18 0x84D2
#define GL_TEXTURE19 0x84D3
#define GL_TEXTURE20 0x84D4
#define GL_TEXTURE21 0x84D5
#define GL_TEXTURE22 0x84D6
#define GL_TEXTURE23 0x84D7
#define GL_TEXTURE24 0x84D8
#define GL_TEXTURE25 0x84D9
#define GL_TEXTURE26 0x84DA
#define GL_TEXTURE27 0x84DB
#define GL_TEXTURE28 0x84DC
#define GL_TEXTURE29 0x84DD
#define GL_TEXTURE30 0x84DE
#define GL_TEXTURE31 0x84DF
#define GL_ACTIVE_TEXTURE 0x84E0
#define GL_SAMPLE_ALPHA_TO_COVERAGE 0x809E
#define GL_SAMPLE_COVERAGE 0x80A0
#define GL_SAMPLE_BUFFERS 0x80A8
#define GL_SAMPLES 0x80A9
#define GL_SAMPLE_COVERAGE_VALUE 0x80AA
#define GL_SAMPLE_COVERAGE_INVERT 0x80AB
#define GL_TEXTURE_CUBE_MAP 0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP 0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X 0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y 0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y 0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z 0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z 0x851A
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS 0x86A3
#define GL_BLEND_DST_RGB 0x80C8
#define GL_BLEND_SRC_RGB 0x80C9
#define GL_BLEND_DST_ALPHA 0x80CA
#define GL_BLEND_SRC_ALPHA 0x80CB
#define GL_DEPTH_COMPONENT16 0x81A5
#define GL_MIRRORED_REPEAT 0x8370
#define GL_INCR_WRAP 0x8507
#define GL_DECR_WRAP 0x8508
#define GL_BLEND_COLOR 0x8005
#define GL_BLEND_EQUATION 0x8009
#define GL_CONSTANT_COLOR 0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR 0x8002
#define GL_CONSTANT_ALPHA 0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA 0x8004
#define GL_FUNC_ADD 0x8006
#define GL_FUNC_REVERSE_SUBTRACT 0x800B
#define GL_FUNC_SUBTRACT 0x800A
#define GL_BUFFER_SIZE 0x8764
#define GL_BUFFER_USAGE 0x8765
#define GL_ARRAY_BUFFER 0x8892
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_ARRAY_BUFFER_BINDING 0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define GL_STREAM_DRAW 0x88E0
#define GL_STATIC_DRAW 0x88E4
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_BLEND_EQUATION_RGB 0x8009
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#define GL_CURRENT_VERTEX_ATTRIB 0x8626
#define GL_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
#define GL_STENCIL_BACK_FUNC 0x8800
#define GL_STENCIL_BACK_FAIL 0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
#define GL_BLEND_EQUATION_ALPHA 0x883D
#define GL_MAX_VERTEX_ATTRIBS 0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define GL_MAX_TEXTURE_IMAGE_UNITS 0x8872
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_VERTEX_SHADER 0x8B31
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define GL_SHADER_TYPE 0x8B4F
#define GL_FLOAT_VEC2 0x8B50
#define GL_FLOAT_VEC3 0x8B51
#define GL_FLOAT_VEC4 0x8B52
#define GL_INT_VEC2 0x8B53
#define GL_INT_VEC3 0x8B54
#define GL_INT_VEC4 0x8B55
#define GL_BOOL 0x8B56
#define GL_BOOL_VEC2 0x8B57
#define GL_BOOL_VEC3 0x8B58
#define GL_BOOL_VEC4 0x8B59
#define GL_FLOAT_MAT2 0x8B5A
#define GL_FLOAT_MAT3 0x8B5B
#define GL_FLOAT_MAT4 0x8B5C
#define GL_SAMPLER_2D 0x8B5E
#define GL_SAMPLER_CUBE 0x8B60
#define GL_DELETE_STATUS 0x8B80
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_VALIDATE_STATUS 0x8B83
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_ATTACHED_SHADERS 0x8B85
#define GL_ACTIVE_UNIFORMS 0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#define GL_SHADER_SOURCE_LENGTH 0x8B88
#define GL_ACTIVE_ATTRIBUTES 0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#define GL_SHADING_LANGUAGE_VERSION 0x8B8C
#define GL_CURRENT_PROGRAM 0x8B8D
#define GL_STENCIL_BACK_REF 0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK 0x8CA4
#define GL_STENCIL_BACK_WRITEMASK 0x8CA5

// ====================================
// OPENGL FUNCTION POINTER SIGNATURES
// ====================================

typedef const GLubyte * (APIENTRYP PFNGLGETSTRINGPROC)(GLenum name);
typedef GLboolean (APIENTRYP PFNGLISBUFFERPROC)(GLuint buffer);
typedef GLboolean (APIENTRYP PFNGLISENABLEDPROC)(GLenum cap);
typedef GLboolean (APIENTRYP PFNGLISPROGRAMPROC)(GLuint program);
typedef GLboolean (APIENTRYP PFNGLISSHADERPROC)(GLuint shader);
typedef GLboolean (APIENTRYP PFNGLISTEXTUREPROC)(GLuint texture);
typedef GLenum (APIENTRYP PFNGLGETERRORPROC)(void);
typedef GLint (APIENTRYP PFNGLGETATTRIBLOCATIONPROC)(GLuint program, const GLchar *name);
typedef GLint (APIENTRYP PFNGLGETUNIFORMLOCATIONPROC)(GLuint program, const GLchar *name);
typedef GLuint (APIENTRYP PFNGLCREATEPROGRAMPROC)(void);
typedef GLuint (APIENTRYP PFNGLCREATESHADERPROC)(GLenum type);
typedef void (APIENTRYP PFNGLACTIVETEXTUREPROC)(GLenum texture);
typedef void (APIENTRYP PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
typedef void (APIENTRYP PFNGLBINDATTRIBLOCATIONPROC)(GLuint program, GLuint index, const GLchar *name);
typedef void (APIENTRYP PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
typedef void (APIENTRYP PFNGLBINDTEXTUREPROC)(GLenum target, GLuint texture);
typedef void (APIENTRYP PFNGLBLENDCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRYP PFNGLBLENDEQUATIONPROC)(GLenum mode);
typedef void (APIENTRYP PFNGLBLENDEQUATIONSEPARATEPROC)(GLenum modeRGB, GLenum modeAlpha);
typedef void (APIENTRYP PFNGLBLENDFUNCPROC)(GLenum sfactor, GLenum dfactor);
typedef void (APIENTRYP PFNGLBLENDFUNCSEPARATEPROC)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
typedef void (APIENTRYP PFNGLBUFFERDATAPROC)(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
typedef void (APIENTRYP PFNGLBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
typedef void (APIENTRYP PFNGLCLEARCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
typedef void (APIENTRYP PFNGLCLEARPROC)(GLbitfield mask);
typedef void (APIENTRYP PFNGLCLEARSTENCILPROC)(GLint s);
typedef void (APIENTRYP PFNGLCOLORMASKPROC)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
typedef void (APIENTRYP PFNGLCOMPILESHADERPROC)(GLuint shader);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
typedef void (APIENTRYP PFNGLCOPYTEXIMAGE2DPROC)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
typedef void (APIENTRYP PFNGLCOPYTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLCULLFACEPROC)(GLenum mode);
typedef void (APIENTRYP PFNGLDELETEBUFFERSPROC)(GLsizei n, const GLuint *buffers);
typedef void (APIENTRYP PFNGLDELETEPROGRAMPROC)(GLuint program);
typedef void (APIENTRYP PFNGLDELETESHADERPROC)(GLuint shader);
typedef void (APIENTRYP PFNGLDELETETEXTURESPROC)(GLsizei n, const GLuint *textures);
typedef void (APIENTRYP PFNGLDEPTHFUNCPROC)(GLenum func);
typedef void (APIENTRYP PFNGLDEPTHMASKPROC)(GLboolean flag);
typedef void (APIENTRYP PFNGLDETACHSHADERPROC)(GLuint program, GLuint shader);
typedef void (APIENTRYP PFNGLDISABLEPROC)(GLenum cap);
typedef void (APIENTRYP PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint index);
typedef void (APIENTRYP PFNGLDRAWARRAYSPROC)(GLenum mode, GLint first, GLsizei count);
typedef void (APIENTRYP PFNGLDRAWELEMENTSPROC)(GLenum mode, GLsizei count, GLenum type, const void *indices);
typedef void (APIENTRYP PFNGLENABLEPROC)(GLenum cap);
typedef void (APIENTRYP PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint index);
typedef void (APIENTRYP PFNGLFINISHPROC)(void);
typedef void (APIENTRYP PFNGLFLUSHPROC)(void);
typedef void (APIENTRYP PFNGLFRONTFACEPROC)(GLenum mode);
typedef void (APIENTRYP PFNGLGENBUFFERSPROC)(GLsizei n, GLuint *buffers);
typedef void (APIENTRYP PFNGLGENTEXTURESPROC)(GLsizei n, GLuint *textures);
typedef void (APIENTRYP PFNGLGETACTIVEATTRIBPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFNGLGETACTIVEUNIFORMPROC)(GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
typedef void (APIENTRYP PFNGLGETATTACHEDSHADERSPROC)(GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
typedef void (APIENTRYP PFNGLGETBOOLEANVPROC)(GLenum pname, GLboolean *data);
typedef void (APIENTRYP PFNGLGETBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETFLOATVPROC)(GLenum pname, GLfloat *data);
typedef void (APIENTRYP PFNGLGETINTEGERVPROC)(GLenum pname, GLint *data);
typedef void (APIENTRYP PFNGLGETPROGRAMINFOLOGPROC)(GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFNGLGETPROGRAMIVPROC)(GLuint program, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETSHADERINFOLOGPROC)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
typedef void (APIENTRYP PFNGLGETSHADERIVPROC)(GLuint shader, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETSHADERSOURCEPROC)(GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETTEXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETUNIFORMFVPROC)(GLuint program, GLint location, GLfloat *params);
typedef void (APIENTRYP PFNGLGETUNIFORMIVPROC)(GLuint program, GLint location, GLint *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBFVPROC)(GLuint index, GLenum pname, GLfloat *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBIVPROC)(GLuint index, GLenum pname, GLint *params);
typedef void (APIENTRYP PFNGLGETVERTEXATTRIBPOINTERVPROC)(GLuint index, GLenum pname, void **pointer);
typedef void (APIENTRYP PFNGLHINTPROC)(GLenum target, GLenum mode);
typedef void (APIENTRYP PFNGLLINEWIDTHPROC)(GLfloat width);
typedef void (APIENTRYP PFNGLLINKPROGRAMPROC)(GLuint program);
typedef void (APIENTRYP PFNGLPIXELSTOREIPROC)(GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLPOLYGONOFFSETPROC)(GLfloat factor, GLfloat units);
typedef void (APIENTRYP PFNGLREADPIXELSPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
typedef void (APIENTRYP PFNGLSAMPLECOVERAGEPROC)(GLfloat value, GLboolean invert);
typedef void (APIENTRYP PFNGLSCISSORPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
typedef void (APIENTRYP PFNGLSHADERSOURCEPROC)(GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
typedef void (APIENTRYP PFNGLSTENCILFUNCPROC)(GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILFUNCSEPARATEPROC)(GLenum face, GLenum func, GLint ref, GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILMASKPROC)(GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILMASKSEPARATEPROC)(GLenum face, GLuint mask);
typedef void (APIENTRYP PFNGLSTENCILOPPROC)(GLenum fail, GLenum zfail, GLenum zpass);
typedef void (APIENTRYP PFNGLSTENCILOPSEPARATEPROC)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
typedef void (APIENTRYP PFNGLTEXIMAGE2DPROC)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLTEXPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat param);
typedef void (APIENTRYP PFNGLTEXPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat *params);
typedef void (APIENTRYP PFNGLTEXPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
typedef void (APIENTRYP PFNGLTEXPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint *params);
typedef void (APIENTRYP PFNGLTEXSUBIMAGE2DPROC)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
typedef void (APIENTRYP PFNGLUNIFORM1FPROC)(GLint location, GLfloat v0);
typedef void (APIENTRYP PFNGLUNIFORM1FVPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM1IPROC)(GLint location, GLint v0);
typedef void (APIENTRYP PFNGLUNIFORM1IVPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORM2FPROC)(GLint location, GLfloat v0, GLfloat v1);
typedef void (APIENTRYP PFNGLUNIFORM2FVPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM2IPROC)(GLint location, GLint v0, GLint v1);
typedef void (APIENTRYP PFNGLUNIFORM2IVPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORM3FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
typedef void (APIENTRYP PFNGLUNIFORM3FVPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM3IPROC)(GLint location, GLint v0, GLint v1, GLint v2);
typedef void (APIENTRYP PFNGLUNIFORM3IVPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORM4FPROC)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
typedef void (APIENTRYP PFNGLUNIFORM4FVPROC)(GLint location, GLsizei count, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORM4IPROC)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
typedef void (APIENTRYP PFNGLUNIFORM4IVPROC)(GLint location, GLsizei count, const GLint *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX2FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX3FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUNIFORMMATRIX4FVPROC)(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
typedef void (APIENTRYP PFNGLUSEPROGRAMPROC)(GLuint program);
typedef void (APIENTRYP PFNGLVALIDATEPROGRAMPROC)(GLuint program);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FPROC)(GLuint index, GLfloat x);
typedef void (APIENTRYP PFNGLVERTEXATTRIB1FVPROC)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FPROC)(GLuint index, GLfloat x, GLfloat y);
typedef void (APIENTRYP PFNGLVERTEXATTRIB2FVPROC)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z);
typedef void (APIENTRYP PFNGLVERTEXATTRIB3FVPROC)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FPROC)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
typedef void (APIENTRYP PFNGLVERTEXATTRIB4FVPROC)(GLuint index, const GLfloat *v);
typedef void (APIENTRYP PFNGLVERTEXATTRIBPOINTERPROC)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
typedef void (APIENTRYP PFNGLVIEWPORTPROC)(GLint x, GLint y, GLsizei width, GLsizei height);

// ====================================
// OPENGL FUNCTION DECLARATIONS
// ====================================

GLAPI PFNGLACTIVETEXTUREPROC glActiveTexture_ptr;
GLAPI PFNGLATTACHSHADERPROC glAttachShader_ptr;
GLAPI PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation_ptr;
GLAPI PFNGLBINDBUFFERPROC glBindBuffer_ptr;
GLAPI PFNGLBINDTEXTUREPROC glBindTexture_ptr;
GLAPI PFNGLBLENDCOLORPROC glBlendColor_ptr;
GLAPI PFNGLBLENDEQUATIONPROC glBlendEquation_ptr;
GLAPI PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate_ptr;
GLAPI PFNGLBLENDFUNCPROC glBlendFunc_ptr;
GLAPI PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate_ptr;
GLAPI PFNGLBUFFERDATAPROC glBufferData_ptr;
GLAPI PFNGLBUFFERSUBDATAPROC glBufferSubData_ptr;
GLAPI PFNGLCLEARCOLORPROC glClearColor_ptr;
GLAPI PFNGLCLEARPROC glClear_ptr;
GLAPI PFNGLCLEARSTENCILPROC glClearStencil_ptr;
GLAPI PFNGLCOLORMASKPROC glColorMask_ptr;
GLAPI PFNGLCOMPILESHADERPROC glCompileShader_ptr;
GLAPI PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D_ptr;
GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D_ptr;
GLAPI PFNGLCOPYTEXIMAGE2DPROC glCopyTexImage2D_ptr;
GLAPI PFNGLCOPYTEXSUBIMAGE2DPROC glCopyTexSubImage2D_ptr;
GLAPI PFNGLCREATEPROGRAMPROC glCreateProgram_ptr;
GLAPI PFNGLCREATESHADERPROC glCreateShader_ptr;
GLAPI PFNGLCULLFACEPROC glCullFace_ptr;
GLAPI PFNGLDELETEBUFFERSPROC glDeleteBuffers_ptr;
GLAPI PFNGLDELETEPROGRAMPROC glDeleteProgram_ptr;
GLAPI PFNGLDELETESHADERPROC glDeleteShader_ptr;
GLAPI PFNGLDELETETEXTURESPROC glDeleteTextures_ptr;
GLAPI PFNGLDEPTHFUNCPROC glDepthFunc_ptr;
GLAPI PFNGLDEPTHMASKPROC glDepthMask_ptr;
GLAPI PFNGLDETACHSHADERPROC glDetachShader_ptr;
GLAPI PFNGLDISABLEPROC glDisable_ptr;
GLAPI PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray_ptr;
GLAPI PFNGLDRAWARRAYSPROC glDrawArrays_ptr;
GLAPI PFNGLDRAWELEMENTSPROC glDrawElements_ptr;
GLAPI PFNGLENABLEPROC glEnable_ptr;
GLAPI PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray_ptr;
GLAPI PFNGLFINISHPROC glFinish_ptr;
GLAPI PFNGLFLUSHPROC glFlush_ptr;
GLAPI PFNGLFRONTFACEPROC glFrontFace_ptr;
GLAPI PFNGLGENBUFFERSPROC glGenBuffers_ptr;
GLAPI PFNGLGENTEXTURESPROC glGenTextures_ptr;
GLAPI PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib_ptr;
GLAPI PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform_ptr;
GLAPI PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders_ptr;
GLAPI PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation_ptr;
GLAPI PFNGLGETBOOLEANVPROC glGetBooleanv_ptr;
GLAPI PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv_ptr;
GLAPI PFNGLGETERRORPROC glGetError_ptr;
GLAPI PFNGLGETFLOATVPROC glGetFloatv_ptr;
GLAPI PFNGLGETINTEGERVPROC glGetIntegerv_ptr;
GLAPI PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog_ptr;
GLAPI PFNGLGETPROGRAMIVPROC glGetProgramiv_ptr;
GLAPI PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog_ptr;
GLAPI PFNGLGETSHADERIVPROC glGetShaderiv_ptr;
GLAPI PFNGLGETSHADERSOURCEPROC glGetShaderSource_ptr;
GLAPI PFNGLGETSTRINGPROC glGetString_ptr;
GLAPI PFNGLGETTEXPARAMETERFVPROC glGetTexParameterfv_ptr;
GLAPI PFNGLGETTEXPARAMETERIVPROC glGetTexParameteriv_ptr;
GLAPI PFNGLGETUNIFORMFVPROC glGetUniformfv_ptr;
GLAPI PFNGLGETUNIFORMIVPROC glGetUniformiv_ptr;
GLAPI PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation_ptr;
GLAPI PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv_ptr;
GLAPI PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv_ptr;
GLAPI PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv_ptr;
GLAPI PFNGLHINTPROC glHint_ptr;
GLAPI PFNGLISBUFFERPROC glIsBuffer_ptr;
GLAPI PFNGLISENABLEDPROC glIsEnabled_ptr;
GLAPI PFNGLISPROGRAMPROC glIsProgram_ptr;
GLAPI PFNGLISSHADERPROC glIsShader_ptr;
GLAPI PFNGLISTEXTUREPROC glIsTexture_ptr;
GLAPI PFNGLLINEWIDTHPROC glLineWidth_ptr;
GLAPI PFNGLLINKPROGRAMPROC glLinkProgram_ptr;
GLAPI PFNGLPIXELSTOREIPROC glPixelStorei_ptr;
GLAPI PFNGLPOLYGONOFFSETPROC glPolygonOffset_ptr;
GLAPI PFNGLREADPIXELSPROC glReadPixels_ptr;
GLAPI PFNGLSAMPLECOVERAGEPROC glSampleCoverage_ptr;
GLAPI PFNGLSCISSORPROC glScissor_ptr;
GLAPI PFNGLSHADERSOURCEPROC glShaderSource_ptr;
GLAPI PFNGLSTENCILFUNCPROC glStencilFunc_ptr;
GLAPI PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparate_ptr;
GLAPI PFNGLSTENCILMASKPROC glStencilMask_ptr;
GLAPI PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparate_ptr;
GLAPI PFNGLSTENCILOPPROC glStencilOp_ptr;
GLAPI PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparate_ptr;
GLAPI PFNGLTEXIMAGE2DPROC glTexImage2D_ptr;
GLAPI PFNGLTEXPARAMETERFPROC glTexParameterf_ptr;
GLAPI PFNGLTEXPARAMETERFVPROC glTexParameterfv_ptr;
GLAPI PFNGLTEXPARAMETERIPROC glTexParameteri_ptr;
GLAPI PFNGLTEXPARAMETERIVPROC glTexParameteriv_ptr;
GLAPI PFNGLTEXSUBIMAGE2DPROC glTexSubImage2D_ptr;
GLAPI PFNGLUNIFORM1FPROC glUniform1f_ptr;
GLAPI PFNGLUNIFORM1FVPROC glUniform1fv_ptr;
GLAPI PFNGLUNIFORM1IPROC glUniform1i_ptr;
GLAPI PFNGLUNIFORM1IVPROC glUniform1iv_ptr;
GLAPI PFNGLUNIFORM2FPROC glUniform2f_ptr;
GLAPI PFNGLUNIFORM2FVPROC glUniform2fv_ptr;
GLAPI PFNGLUNIFORM2IPROC glUniform2i_ptr;
GLAPI PFNGLUNIFORM2IVPROC glUniform2iv_ptr;
GLAPI PFNGLUNIFORM3FPROC glUniform3f_ptr;
GLAPI PFNGLUNIFORM3FVPROC glUniform3fv_ptr;
GLAPI PFNGLUNIFORM3IPROC glUniform3i_ptr;
GLAPI PFNGLUNIFORM3IVPROC glUniform3iv_ptr;
GLAPI PFNGLUNIFORM4FPROC glUniform4f_ptr;
GLAPI PFNGLUNIFORM4FVPROC glUniform4fv_ptr;
GLAPI PFNGLUNIFORM4IPROC glUniform4i_ptr;
GLAPI PFNGLUNIFORM4IVPROC glUniform4iv_ptr;
GLAPI PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv_ptr;
GLAPI PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv_ptr;
GLAPI PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv_ptr;
GLAPI PFNGLUSEPROGRAMPROC glUseProgram_ptr;
GLAPI PFNGLVALIDATEPROGRAMPROC glValidateProgram_ptr;
GLAPI PFNGLVERTEXATTRIB1FPROC glVertexAttrib1f_ptr;
GLAPI PFNGLVERTEXATTRIB1FVPROC glVertexAttrib1fv_ptr;
GLAPI PFNGLVERTEXATTRIB2FPROC glVertexAttrib2f_ptr;
GLAPI PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fv_ptr;
GLAPI PFNGLVERTEXATTRIB3FPROC glVertexAttrib3f_ptr;
GLAPI PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fv_ptr;
GLAPI PFNGLVERTEXATTRIB4FPROC glVertexAttrib4f_ptr;
GLAPI PFNGLVERTEXATTRIB4FVPROC glVertexAttrib4fv_ptr;
GLAPI PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer_ptr;
GLAPI PFNGLVIEWPORTPROC glViewport_ptr;

// ====================================
// OPENGL MACRO MAPPINGS TO FUNCTIONS
// ====================================

#define glActiveTexture glActiveTexture_ptr
#define glAttachShader glAttachShader_ptr
#define glBindAttribLocation glBindAttribLocation_ptr
#define glBindBuffer glBindBuffer_ptr
#define glBindTexture glBindTexture_ptr
#define glBlendColor glBlendColor_ptr
#define glBlendEquation glBlendEquation_ptr
#define glBlendEquationSeparate glBlendEquationSeparate_ptr
#define glBlendFunc glBlendFunc_ptr
#define glBlendFuncSeparate glBlendFuncSeparate_ptr
#define glBufferData glBufferData_ptr
#define glBufferSubData glBufferSubData_ptr
#define glClearColor glClearColor_ptr
#define glClear glClear_ptr
#define glClearStencil glClearStencil_ptr
#define glColorMask glColorMask_ptr
#define glCompileShader glCompileShader_ptr
#define glCompressedTexImage2D glCompressedTexImage2D_ptr
#define glCompressedTexSubImage2D glCompressedTexSubImage2D_ptr
#define glCopyTexImage2D glCopyTexImage2D_ptr
#define glCopyTexSubImage2D glCopyTexSubImage2D_ptr
#define glCreateProgram glCreateProgram_ptr
#define glCreateShader glCreateShader_ptr
#define glCullFace glCullFace_ptr
#define glDeleteBuffers glDeleteBuffers_ptr
#define glDeleteProgram glDeleteProgram_ptr
#define glDeleteShader glDeleteShader_ptr
#define glDeleteTextures glDeleteTextures_ptr
#define glDepthFunc glDepthFunc_ptr
#define glDepthMask glDepthMask_ptr
#define glDetachShader glDetachShader_ptr
#define glDisable glDisable_ptr
#define glDisableVertexAttribArray glDisableVertexAttribArray_ptr
#define glDrawArrays glDrawArrays_ptr
#define glDrawElements glDrawElements_ptr
#define glEnable glEnable_ptr
#define glEnableVertexAttribArray glEnableVertexAttribArray_ptr
#define glFinish glFinish_ptr
#define glFlush glFlush_ptr
#define glFrontFace glFrontFace_ptr
#define glGenBuffers glGenBuffers_ptr
#define glGenTextures glGenTextures_ptr
#define glGetActiveAttrib glGetActiveAttrib_ptr
#define glGetActiveUniform glGetActiveUniform_ptr
#define glGetAttachedShaders glGetAttachedShaders_ptr
#define glGetAttribLocation glGetAttribLocation_ptr
#define glGetBooleanv glGetBooleanv_ptr
#define glGetBufferParameteriv glGetBufferParameteriv_ptr
#define glGetError glGetError_ptr
#define glGetFloatv glGetFloatv_ptr
#define glGetIntegerv glGetIntegerv_ptr
#define glGetProgramInfoLog glGetProgramInfoLog_ptr
#define glGetProgramiv glGetProgramiv_ptr
#define glGetShaderInfoLog glGetShaderInfoLog_ptr
#define glGetShaderiv glGetShaderiv_ptr
#define glGetShaderSource glGetShaderSource_ptr
#define glGetString glGetString_ptr
#define glGetTexParameterfv glGetTexParameterfv_ptr
#define glGetTexParameteriv glGetTexParameteriv_ptr
#define glGetUniformfv glGetUniformfv_ptr
#define glGetUniformiv glGetUniformiv_ptr
#define glGetUniformLocation glGetUniformLocation_ptr
#define glGetVertexAttribfv glGetVertexAttribfv_ptr
#define glGetVertexAttribiv glGetVertexAttribiv_ptr
#define glGetVertexAttribPointerv glGetVertexAttribPointerv_ptr
#define glHint glHint_ptr
#define glIsBuffer glIsBuffer_ptr
#define glIsEnabled glIsEnabled_ptr
#define glIsProgram glIsProgram_ptr
#define glIsShader glIsShader_ptr
#define glIsTexture glIsTexture_ptr
#define glLineWidth glLineWidth_ptr
#define glLinkProgram glLinkProgram_ptr
#define glPixelStorei glPixelStorei_ptr
#define glPolygonOffset glPolygonOffset_ptr
#define glReadPixels glReadPixels_ptr
#define glSampleCoverage glSampleCoverage_ptr
#define glScissor glScissor_ptr
#define glShaderSource glShaderSource_ptr
#define glStencilFunc glStencilFunc_ptr
#define glStencilFuncSeparate glStencilFuncSeparate_ptr
#define glStencilMask glStencilMask_ptr
#define glStencilMaskSeparate glStencilMaskSeparate_ptr
#define glStencilOp glStencilOp_ptr
#define glStencilOpSeparate glStencilOpSeparate_ptr
#define glTexImage2D glTexImage2D_ptr
#define glTexParameterf glTexParameterf_ptr
#define glTexParameterfv glTexParameterfv_ptr
#define glTexParameteri glTexParameteri_ptr
#define glTexParameteriv glTexParameteriv_ptr
#define glTexSubImage2D glTexSubImage2D_ptr
#define glUniform1f glUniform1f_ptr
#define glUniform1fv glUniform1fv_ptr
#define glUniform1i glUniform1i_ptr
#define glUniform1iv glUniform1iv_ptr
#define glUniform2f glUniform2f_ptr
#define glUniform2fv glUniform2fv_ptr
#define glUniform2i glUniform2i_ptr
#define glUniform2iv glUniform2iv_ptr
#define glUniform3f glUniform3f_ptr
#define glUniform3fv glUniform3fv_ptr
#define glUniform3i glUniform3i_ptr
#define glUniform3iv glUniform3iv_ptr
#define glUniform4f glUniform4f_ptr
#define glUniform4fv glUniform4fv_ptr
#define glUniform4i glUniform4i_ptr
#define glUniform4iv glUniform4iv_ptr
#define glUniformMatrix2fv glUniformMatrix2fv_ptr
#define glUniformMatrix3fv glUniformMatrix3fv_ptr
#define glUniformMatrix4fv glUniformMatrix4fv_ptr
#define glUseProgram glUseProgram_ptr
#define glValidateProgram glValidateProgram_ptr
#define glVertexAttrib1f glVertexAttrib1f_ptr
#define glVertexAttrib1fv glVertexAttrib1fv_ptr
#define glVertexAttrib2f glVertexAttrib2f_ptr
#define glVertexAttrib2fv glVertexAttrib2fv_ptr
#define glVertexAttrib3f glVertexAttrib3f_ptr
#define glVertexAttrib3fv glVertexAttrib3fv_ptr
#define glVertexAttrib4f glVertexAttrib4f_ptr
#define glVertexAttrib4fv glVertexAttrib4fv_ptr
#define glVertexAttribPointer glVertexAttribPointer_ptr
#define glViewport glViewport_ptr

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // MAD_GLWRAP_H

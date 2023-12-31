#include "glwrap.h"
#include <stddef.h>

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#undef APIENTRY
#include <windows.h>
// Windows: WGL implementation of GetProcAddress()
#define GetAddress(name) wglGetProcAddress((LPCSTR)name)
#else
#include <GL/glx.h>
// UNIX/Linux: GLX implementation of GetProcAddress()
extern void (*glXGetProcAddressARB(const GLubyte *procName))();
#define GetAddress(name) (*glXGetProcAddressARB)((const GLubyte*) name)
#endif // _WIN32

// Load function and check for driver dependent error return values
#define GetFunction(type, name) name##_ptr = (type) GetAddress(#name); \
if (name##_ptr == (type) 0 || name##_ptr == (type) 1 || \
    name##_ptr == (type) 2 || name##_ptr == (type) 3 || \
    name##_ptr == (type) -1) \
	return -1;

int glInit(void)
{
	GetFunction(PFNGLACTIVETEXTUREPROC, glActiveTexture);
	GetFunction(PFNGLATTACHSHADERPROC, glAttachShader);
	GetFunction(PFNGLBINDATTRIBLOCATIONPROC, glBindAttribLocation);
	GetFunction(PFNGLBINDBUFFERPROC, glBindBuffer);
	GetFunction(PFNGLBINDTEXTUREPROC, glBindTexture);
	GetFunction(PFNGLBLENDCOLORPROC, glBlendColor);
	GetFunction(PFNGLBLENDEQUATIONPROC, glBlendEquation);
	GetFunction(PFNGLBLENDEQUATIONSEPARATEPROC, glBlendEquationSeparate);
	GetFunction(PFNGLBLENDFUNCPROC, glBlendFunc);
	GetFunction(PFNGLBLENDFUNCSEPARATEPROC, glBlendFuncSeparate);
	GetFunction(PFNGLBUFFERDATAPROC, glBufferData);
	GetFunction(PFNGLBUFFERSUBDATAPROC, glBufferSubData);
	GetFunction(PFNGLCLEARCOLORPROC, glClearColor);
	GetFunction(PFNGLCLEARPROC, glClear);
	GetFunction(PFNGLCLEARSTENCILPROC, glClearStencil);
	GetFunction(PFNGLCOLORMASKPROC, glColorMask);
	GetFunction(PFNGLCOMPILESHADERPROC, glCompileShader);
	GetFunction(PFNGLCOMPRESSEDTEXIMAGE2DPROC, glCompressedTexImage2D);
	GetFunction(PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC, glCompressedTexSubImage2D);
	GetFunction(PFNGLCOPYTEXIMAGE2DPROC, glCopyTexImage2D);
	GetFunction(PFNGLCOPYTEXSUBIMAGE2DPROC, glCopyTexSubImage2D);
	GetFunction(PFNGLCREATEPROGRAMPROC, glCreateProgram);
	GetFunction(PFNGLCREATESHADERPROC, glCreateShader);
	GetFunction(PFNGLCULLFACEPROC, glCullFace);
	GetFunction(PFNGLDELETEBUFFERSPROC, glDeleteBuffers);
	GetFunction(PFNGLDELETEPROGRAMPROC, glDeleteProgram);
	GetFunction(PFNGLDELETESHADERPROC, glDeleteShader);
	GetFunction(PFNGLDELETETEXTURESPROC, glDeleteTextures);
	GetFunction(PFNGLDEPTHFUNCPROC, glDepthFunc);
	GetFunction(PFNGLDEPTHMASKPROC, glDepthMask);
	GetFunction(PFNGLDETACHSHADERPROC, glDetachShader);
	GetFunction(PFNGLDISABLEPROC, glDisable);
	GetFunction(PFNGLDISABLEVERTEXATTRIBARRAYPROC, glDisableVertexAttribArray);
	GetFunction(PFNGLDRAWARRAYSPROC, glDrawArrays);
	GetFunction(PFNGLDRAWELEMENTSPROC, glDrawElements);
	GetFunction(PFNGLENABLEPROC, glEnable);
	GetFunction(PFNGLENABLEVERTEXATTRIBARRAYPROC, glEnableVertexAttribArray);
	GetFunction(PFNGLFINISHPROC, glFinish);
	GetFunction(PFNGLFLUSHPROC, glFlush);
	GetFunction(PFNGLFRONTFACEPROC, glFrontFace);
	GetFunction(PFNGLGENBUFFERSPROC, glGenBuffers);
	GetFunction(PFNGLGENTEXTURESPROC, glGenTextures);
	GetFunction(PFNGLGETACTIVEATTRIBPROC, glGetActiveAttrib);
	GetFunction(PFNGLGETACTIVEUNIFORMPROC, glGetActiveUniform);
	GetFunction(PFNGLGETATTACHEDSHADERSPROC, glGetAttachedShaders);
	GetFunction(PFNGLGETATTRIBLOCATIONPROC, glGetAttribLocation);
	GetFunction(PFNGLGETBOOLEANVPROC, glGetBooleanv);
	GetFunction(PFNGLGETBUFFERPARAMETERIVPROC, glGetBufferParameteriv);
	GetFunction(PFNGLGETERRORPROC, glGetError);
	GetFunction(PFNGLGETFLOATVPROC, glGetFloatv);
	GetFunction(PFNGLGETINTEGERVPROC, glGetIntegerv);
	GetFunction(PFNGLGETPROGRAMINFOLOGPROC, glGetProgramInfoLog);
	GetFunction(PFNGLGETPROGRAMIVPROC, glGetProgramiv);
	GetFunction(PFNGLGETSHADERINFOLOGPROC, glGetShaderInfoLog);
	GetFunction(PFNGLGETSHADERIVPROC, glGetShaderiv);
	GetFunction(PFNGLGETSHADERSOURCEPROC, glGetShaderSource);
	GetFunction(PFNGLGETSTRINGPROC, glGetString);
	GetFunction(PFNGLGETTEXPARAMETERFVPROC, glGetTexParameterfv);
	GetFunction(PFNGLGETTEXPARAMETERIVPROC, glGetTexParameteriv);
	GetFunction(PFNGLGETUNIFORMFVPROC, glGetUniformfv);
	GetFunction(PFNGLGETUNIFORMIVPROC, glGetUniformiv);
	GetFunction(PFNGLGETUNIFORMLOCATIONPROC, glGetUniformLocation);
	GetFunction(PFNGLGETVERTEXATTRIBFVPROC, glGetVertexAttribfv);
	GetFunction(PFNGLGETVERTEXATTRIBIVPROC, glGetVertexAttribiv);
	GetFunction(PFNGLGETVERTEXATTRIBPOINTERVPROC, glGetVertexAttribPointerv);
	GetFunction(PFNGLHINTPROC, glHint);
	GetFunction(PFNGLISBUFFERPROC, glIsBuffer);
	GetFunction(PFNGLISENABLEDPROC, glIsEnabled);
	GetFunction(PFNGLISPROGRAMPROC, glIsProgram);
	GetFunction(PFNGLISSHADERPROC, glIsShader);
	GetFunction(PFNGLISTEXTUREPROC, glIsTexture);
	GetFunction(PFNGLLINEWIDTHPROC, glLineWidth);
	GetFunction(PFNGLLINKPROGRAMPROC, glLinkProgram);
	GetFunction(PFNGLPIXELSTOREIPROC, glPixelStorei);
	GetFunction(PFNGLPOLYGONOFFSETPROC, glPolygonOffset);
	GetFunction(PFNGLREADPIXELSPROC, glReadPixels);
	GetFunction(PFNGLSAMPLECOVERAGEPROC, glSampleCoverage);
	GetFunction(PFNGLSCISSORPROC, glScissor);
	GetFunction(PFNGLSHADERSOURCEPROC, glShaderSource);
	GetFunction(PFNGLSTENCILFUNCPROC, glStencilFunc);
	GetFunction(PFNGLSTENCILFUNCSEPARATEPROC, glStencilFuncSeparate);
	GetFunction(PFNGLSTENCILMASKPROC, glStencilMask);
	GetFunction(PFNGLSTENCILMASKSEPARATEPROC, glStencilMaskSeparate);
	GetFunction(PFNGLSTENCILOPPROC, glStencilOp);
	GetFunction(PFNGLSTENCILOPSEPARATEPROC, glStencilOpSeparate);
	GetFunction(PFNGLTEXIMAGE2DPROC, glTexImage2D);
	GetFunction(PFNGLTEXPARAMETERFPROC, glTexParameterf);
	GetFunction(PFNGLTEXPARAMETERFVPROC, glTexParameterfv);
	GetFunction(PFNGLTEXPARAMETERIPROC, glTexParameteri);
	GetFunction(PFNGLTEXPARAMETERIVPROC, glTexParameteriv);
	GetFunction(PFNGLTEXSUBIMAGE2DPROC, glTexSubImage2D);
	GetFunction(PFNGLUNIFORM1FPROC, glUniform1f);
	GetFunction(PFNGLUNIFORM1FVPROC, glUniform1fv);
	GetFunction(PFNGLUNIFORM1IPROC, glUniform1i);
	GetFunction(PFNGLUNIFORM1IVPROC, glUniform1iv);
	GetFunction(PFNGLUNIFORM2FPROC, glUniform2f);
	GetFunction(PFNGLUNIFORM2FVPROC, glUniform2fv);
	GetFunction(PFNGLUNIFORM2IPROC, glUniform2i);
	GetFunction(PFNGLUNIFORM2IVPROC, glUniform2iv);
	GetFunction(PFNGLUNIFORM3FPROC, glUniform3f);
	GetFunction(PFNGLUNIFORM3FVPROC, glUniform3fv);
	GetFunction(PFNGLUNIFORM3IPROC, glUniform3i);
	GetFunction(PFNGLUNIFORM3IVPROC, glUniform3iv);
	GetFunction(PFNGLUNIFORM4FPROC, glUniform4f);
	GetFunction(PFNGLUNIFORM4FVPROC, glUniform4fv);
	GetFunction(PFNGLUNIFORM4IPROC, glUniform4i);
	GetFunction(PFNGLUNIFORM4IVPROC, glUniform4iv);
	GetFunction(PFNGLUNIFORMMATRIX2FVPROC, glUniformMatrix2fv);
	GetFunction(PFNGLUNIFORMMATRIX3FVPROC, glUniformMatrix3fv);
	GetFunction(PFNGLUNIFORMMATRIX4FVPROC, glUniformMatrix4fv);
	GetFunction(PFNGLUSEPROGRAMPROC, glUseProgram);
	GetFunction(PFNGLVALIDATEPROGRAMPROC, glValidateProgram);
	GetFunction(PFNGLVERTEXATTRIB1FPROC, glVertexAttrib1f);
	GetFunction(PFNGLVERTEXATTRIB1FVPROC, glVertexAttrib1fv);
	GetFunction(PFNGLVERTEXATTRIB2FPROC, glVertexAttrib2f);
	GetFunction(PFNGLVERTEXATTRIB2FVPROC, glVertexAttrib2fv);
	GetFunction(PFNGLVERTEXATTRIB3FPROC, glVertexAttrib3f);
	GetFunction(PFNGLVERTEXATTRIB3FVPROC, glVertexAttrib3fv);
	GetFunction(PFNGLVERTEXATTRIB4FPROC, glVertexAttrib4f);
	GetFunction(PFNGLVERTEXATTRIB4FVPROC, glVertexAttrib4fv);
	GetFunction(PFNGLVERTEXATTRIBPOINTERPROC, glVertexAttribPointer);
	GetFunction(PFNGLVIEWPORTPROC, glViewport);

	return 0;
}

PFNGLACTIVETEXTUREPROC glActiveTexture_ptr = NULL;
PFNGLATTACHSHADERPROC glAttachShader_ptr = NULL;
PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation_ptr = NULL;
PFNGLBINDBUFFERPROC glBindBuffer_ptr = NULL;
PFNGLBINDTEXTUREPROC glBindTexture_ptr = NULL;
PFNGLBLENDCOLORPROC glBlendColor_ptr = NULL;
PFNGLBLENDEQUATIONPROC glBlendEquation_ptr = NULL;
PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate_ptr = NULL;
PFNGLBLENDFUNCPROC glBlendFunc_ptr = NULL;
PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate_ptr = NULL;
PFNGLBUFFERDATAPROC glBufferData_ptr = NULL;
PFNGLBUFFERSUBDATAPROC glBufferSubData_ptr = NULL;
PFNGLCLEARCOLORPROC glClearColor_ptr = NULL;
PFNGLCLEARPROC glClear_ptr = NULL;
PFNGLCLEARSTENCILPROC glClearStencil_ptr = NULL;
PFNGLCOLORMASKPROC glColorMask_ptr = NULL;
PFNGLCOMPILESHADERPROC glCompileShader_ptr = NULL;
PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D_ptr = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D_ptr = NULL;
PFNGLCOPYTEXIMAGE2DPROC glCopyTexImage2D_ptr = NULL;
PFNGLCOPYTEXSUBIMAGE2DPROC glCopyTexSubImage2D_ptr = NULL;
PFNGLCREATEPROGRAMPROC glCreateProgram_ptr = NULL;
PFNGLCREATESHADERPROC glCreateShader_ptr = NULL;
PFNGLCULLFACEPROC glCullFace_ptr = NULL;
PFNGLDELETEBUFFERSPROC glDeleteBuffers_ptr = NULL;
PFNGLDELETEPROGRAMPROC glDeleteProgram_ptr = NULL;
PFNGLDELETESHADERPROC glDeleteShader_ptr = NULL;
PFNGLDELETETEXTURESPROC glDeleteTextures_ptr = NULL;
PFNGLDEPTHFUNCPROC glDepthFunc_ptr = NULL;
PFNGLDEPTHMASKPROC glDepthMask_ptr = NULL;
PFNGLDETACHSHADERPROC glDetachShader_ptr = NULL;
PFNGLDISABLEPROC glDisable_ptr = NULL;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray_ptr = NULL;
PFNGLDRAWARRAYSPROC glDrawArrays_ptr = NULL;
PFNGLDRAWELEMENTSPROC glDrawElements_ptr = NULL;
PFNGLENABLEPROC glEnable_ptr = NULL;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray_ptr = NULL;
PFNGLFINISHPROC glFinish_ptr = NULL;
PFNGLFLUSHPROC glFlush_ptr = NULL;
PFNGLFRONTFACEPROC glFrontFace_ptr = NULL;
PFNGLGENBUFFERSPROC glGenBuffers_ptr = NULL;
PFNGLGENTEXTURESPROC glGenTextures_ptr = NULL;
PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib_ptr = NULL;
PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform_ptr = NULL;
PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders_ptr = NULL;
PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation_ptr = NULL;
PFNGLGETBOOLEANVPROC glGetBooleanv_ptr = NULL;
PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv_ptr = NULL;
PFNGLGETERRORPROC glGetError_ptr = NULL;
PFNGLGETFLOATVPROC glGetFloatv_ptr = NULL;
PFNGLGETINTEGERVPROC glGetIntegerv_ptr = NULL;
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog_ptr = NULL;
PFNGLGETPROGRAMIVPROC glGetProgramiv_ptr = NULL;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog_ptr = NULL;
PFNGLGETSHADERIVPROC glGetShaderiv_ptr = NULL;
PFNGLGETSHADERSOURCEPROC glGetShaderSource_ptr = NULL;
PFNGLGETSTRINGPROC glGetString_ptr = NULL;
PFNGLGETTEXPARAMETERFVPROC glGetTexParameterfv_ptr = NULL;
PFNGLGETTEXPARAMETERIVPROC glGetTexParameteriv_ptr = NULL;
PFNGLGETUNIFORMFVPROC glGetUniformfv_ptr = NULL;
PFNGLGETUNIFORMIVPROC glGetUniformiv_ptr = NULL;
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation_ptr = NULL;
PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv_ptr = NULL;
PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv_ptr = NULL;
PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv_ptr = NULL;
PFNGLHINTPROC glHint_ptr = NULL;
PFNGLISBUFFERPROC glIsBuffer_ptr = NULL;
PFNGLISENABLEDPROC glIsEnabled_ptr = NULL;
PFNGLISPROGRAMPROC glIsProgram_ptr = NULL;
PFNGLISSHADERPROC glIsShader_ptr = NULL;
PFNGLISTEXTUREPROC glIsTexture_ptr = NULL;
PFNGLLINEWIDTHPROC glLineWidth_ptr = NULL;
PFNGLLINKPROGRAMPROC glLinkProgram_ptr = NULL;
PFNGLPIXELSTOREIPROC glPixelStorei_ptr = NULL;
PFNGLPOLYGONOFFSETPROC glPolygonOffset_ptr = NULL;
PFNGLREADPIXELSPROC glReadPixels_ptr = NULL;
PFNGLSAMPLECOVERAGEPROC glSampleCoverage_ptr = NULL;
PFNGLSCISSORPROC glScissor_ptr = NULL;
PFNGLSHADERSOURCEPROC glShaderSource_ptr = NULL;
PFNGLSTENCILFUNCPROC glStencilFunc_ptr = NULL;
PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparate_ptr = NULL;
PFNGLSTENCILMASKPROC glStencilMask_ptr = NULL;
PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparate_ptr = NULL;
PFNGLSTENCILOPPROC glStencilOp_ptr = NULL;
PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparate_ptr = NULL;
PFNGLTEXIMAGE2DPROC glTexImage2D_ptr = NULL;
PFNGLTEXPARAMETERFPROC glTexParameterf_ptr = NULL;
PFNGLTEXPARAMETERFVPROC glTexParameterfv_ptr = NULL;
PFNGLTEXPARAMETERIPROC glTexParameteri_ptr = NULL;
PFNGLTEXPARAMETERIVPROC glTexParameteriv_ptr = NULL;
PFNGLTEXSUBIMAGE2DPROC glTexSubImage2D_ptr = NULL;
PFNGLUNIFORM1FPROC glUniform1f_ptr = NULL;
PFNGLUNIFORM1FVPROC glUniform1fv_ptr = NULL;
PFNGLUNIFORM1IPROC glUniform1i_ptr = NULL;
PFNGLUNIFORM1IVPROC glUniform1iv_ptr = NULL;
PFNGLUNIFORM2FPROC glUniform2f_ptr = NULL;
PFNGLUNIFORM2FVPROC glUniform2fv_ptr = NULL;
PFNGLUNIFORM2IPROC glUniform2i_ptr = NULL;
PFNGLUNIFORM2IVPROC glUniform2iv_ptr = NULL;
PFNGLUNIFORM3FPROC glUniform3f_ptr = NULL;
PFNGLUNIFORM3FVPROC glUniform3fv_ptr = NULL;
PFNGLUNIFORM3IPROC glUniform3i_ptr = NULL;
PFNGLUNIFORM3IVPROC glUniform3iv_ptr = NULL;
PFNGLUNIFORM4FPROC glUniform4f_ptr = NULL;
PFNGLUNIFORM4FVPROC glUniform4fv_ptr = NULL;
PFNGLUNIFORM4IPROC glUniform4i_ptr = NULL;
PFNGLUNIFORM4IVPROC glUniform4iv_ptr = NULL;
PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv_ptr = NULL;
PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv_ptr = NULL;
PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv_ptr = NULL;
PFNGLUSEPROGRAMPROC glUseProgram_ptr = NULL;
PFNGLVALIDATEPROGRAMPROC glValidateProgram_ptr = NULL;
PFNGLVERTEXATTRIB1FPROC glVertexAttrib1f_ptr = NULL;
PFNGLVERTEXATTRIB1FVPROC glVertexAttrib1fv_ptr = NULL;
PFNGLVERTEXATTRIB2FPROC glVertexAttrib2f_ptr = NULL;
PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fv_ptr = NULL;
PFNGLVERTEXATTRIB3FPROC glVertexAttrib3f_ptr = NULL;
PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fv_ptr = NULL;
PFNGLVERTEXATTRIB4FPROC glVertexAttrib4f_ptr = NULL;
PFNGLVERTEXATTRIB4FVPROC glVertexAttrib4fv_ptr = NULL;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer_ptr = NULL;
PFNGLVIEWPORTPROC glViewport_ptr = NULL;

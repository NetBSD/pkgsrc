$NetBSD: patch-glx_indirect__reqsize.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- glx/indirect_reqsize.c.orig	2012-05-17 17:09:02.000000000 +0000
+++ glx/indirect_reqsize.c
@@ -31,24 +31,22 @@
 #include "indirect_size.h"
 #include "indirect_reqsize.h"
 
-#define __GLX_PAD(x)  (((x) + 3) & ~3)
-
 #if defined(__CYGWIN__) || defined(__MINGW32__)
 #undef HAVE_ALIAS
 #endif
 #ifdef HAVE_ALIAS
 #define ALIAS2(from,to) \
-    GLint __glX ## from ## ReqSize( const GLbyte * pc, Bool swap ) \
+    GLint __glX ## from ## ReqSize( const GLbyte * pc, Bool swap, int reqlen ) \
         __attribute__ ((alias( # to )));
 #define ALIAS(from,to) ALIAS2( from, __glX ## to ## ReqSize )
 #else
 #define ALIAS(from,to) \
-    GLint __glX ## from ## ReqSize( const GLbyte * pc, Bool swap ) \
-    { return __glX ## to ## ReqSize( pc, swap ); }
+    GLint __glX ## from ## ReqSize( const GLbyte * pc, Bool swap, int reqlen ) \
+    { return __glX ## to ## ReqSize( pc, swap, reqlen ); }
 #endif
 
 int
-__glXCallListsReqSize(const GLbyte * pc, Bool swap)
+__glXCallListsReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLsizei n = *(GLsizei *) (pc + 0);
     GLenum type = *(GLenum *) (pc + 4);
@@ -60,11 +58,11 @@ __glXCallListsReqSize(const GLbyte * pc,
     }
 
     compsize = __glCallLists_size(type);
-    return __GLX_PAD((compsize * n));
+    return safe_pad(safe_mul(compsize, n));
 }
 
 int
-__glXBitmapReqSize(const GLbyte * pc, Bool swap)
+__glXBitmapReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLint row_length = *(GLint *) (pc + 4);
     GLint image_height = 0;
@@ -88,7 +86,7 @@ __glXBitmapReqSize(const GLbyte * pc, Bo
 }
 
 int
-__glXFogfvReqSize(const GLbyte * pc, Bool swap)
+__glXFogfvReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLenum pname = *(GLenum *) (pc + 0);
     GLsizei compsize;
@@ -98,11 +96,11 @@ __glXFogfvReqSize(const GLbyte * pc, Boo
     }
 
     compsize = __glFogfv_size(pname);
-    return __GLX_PAD((compsize * 4));
+    return safe_pad(safe_mul(compsize, 4));
 }
 
 int
-__glXLightfvReqSize(const GLbyte * pc, Bool swap)
+__glXLightfvReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLenum pname = *(GLenum *) (pc + 4);
     GLsizei compsize;
@@ -112,11 +110,11 @@ __glXLightfvReqSize(const GLbyte * pc, B
     }
 
     compsize = __glLightfv_size(pname);
-    return __GLX_PAD((compsize * 4));
+    return safe_pad(safe_mul(compsize, 4));
 }
 
 int
-__glXLightModelfvReqSize(const GLbyte * pc, Bool swap)
+__glXLightModelfvReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLenum pname = *(GLenum *) (pc + 0);
     GLsizei compsize;
@@ -126,11 +124,11 @@ __glXLightModelfvReqSize(const GLbyte * 
     }
 
     compsize = __glLightModelfv_size(pname);
-    return __GLX_PAD((compsize * 4));
+    return safe_pad(safe_mul(compsize, 4));
 }
 
 int
-__glXMaterialfvReqSize(const GLbyte * pc, Bool swap)
+__glXMaterialfvReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLenum pname = *(GLenum *) (pc + 4);
     GLsizei compsize;
@@ -140,11 +138,11 @@ __glXMaterialfvReqSize(const GLbyte * pc
     }
 
     compsize = __glMaterialfv_size(pname);
-    return __GLX_PAD((compsize * 4));
+    return safe_pad(safe_mul(compsize, 4));
 }
 
 int
-__glXPolygonStippleReqSize(const GLbyte * pc, Bool swap)
+__glXPolygonStippleReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLint row_length = *(GLint *) (pc + 4);
     GLint image_height = 0;
@@ -164,7 +162,7 @@ __glXPolygonStippleReqSize(const GLbyte 
 }
 
 int
-__glXTexParameterfvReqSize(const GLbyte * pc, Bool swap)
+__glXTexParameterfvReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLenum pname = *(GLenum *) (pc + 4);
     GLsizei compsize;
@@ -174,11 +172,11 @@ __glXTexParameterfvReqSize(const GLbyte 
     }
 
     compsize = __glTexParameterfv_size(pname);
-    return __GLX_PAD((compsize * 4));
+    return safe_pad(safe_mul(compsize, 4));
 }
 
 int
-__glXTexImage1DReqSize(const GLbyte * pc, Bool swap)
+__glXTexImage1DReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLint row_length = *(GLint *) (pc + 4);
     GLint image_height = 0;
@@ -206,7 +204,7 @@ __glXTexImage1DReqSize(const GLbyte * pc
 }
 
 int
-__glXTexImage2DReqSize(const GLbyte * pc, Bool swap)
+__glXTexImage2DReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLint row_length = *(GLint *) (pc + 4);
     GLint image_height = 0;
@@ -236,7 +234,7 @@ __glXTexImage2DReqSize(const GLbyte * pc
 }
 
 int
-__glXTexEnvfvReqSize(const GLbyte * pc, Bool swap)
+__glXTexEnvfvReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLenum pname = *(GLenum *) (pc + 4);
     GLsizei compsize;
@@ -246,11 +244,11 @@ __glXTexEnvfvReqSize(const GLbyte * pc, 
     }
 
     compsize = __glTexEnvfv_size(pname);
-    return __GLX_PAD((compsize * 4));
+    return safe_pad(safe_mul(compsize, 4));
 }
 
 int
-__glXTexGendvReqSize(const GLbyte * pc, Bool swap)
+__glXTexGendvReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLenum pname = *(GLenum *) (pc + 4);
     GLsizei compsize;
@@ -260,11 +258,11 @@ __glXTexGendvReqSize(const GLbyte * pc, 
     }
 
     compsize = __glTexGendv_size(pname);
-    return __GLX_PAD((compsize * 8));
+    return safe_pad(safe_mul(compsize, 8));
 }
 
 int
-__glXTexGenfvReqSize(const GLbyte * pc, Bool swap)
+__glXTexGenfvReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLenum pname = *(GLenum *) (pc + 4);
     GLsizei compsize;
@@ -274,11 +272,11 @@ __glXTexGenfvReqSize(const GLbyte * pc, 
     }
 
     compsize = __glTexGenfv_size(pname);
-    return __GLX_PAD((compsize * 4));
+    return safe_pad(safe_mul(compsize, 4));
 }
 
 int
-__glXPixelMapfvReqSize(const GLbyte * pc, Bool swap)
+__glXPixelMapfvReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLsizei mapsize = *(GLsizei *) (pc + 4);
 
@@ -286,11 +284,11 @@ __glXPixelMapfvReqSize(const GLbyte * pc
         mapsize = bswap_32(mapsize);
     }
 
-    return __GLX_PAD((mapsize * 4));
+    return safe_pad(safe_mul(mapsize, 4));
 }
 
 int
-__glXPixelMapusvReqSize(const GLbyte * pc, Bool swap)
+__glXPixelMapusvReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLsizei mapsize = *(GLsizei *) (pc + 4);
 
@@ -298,11 +296,11 @@ __glXPixelMapusvReqSize(const GLbyte * p
         mapsize = bswap_32(mapsize);
     }
 
-    return __GLX_PAD((mapsize * 2));
+    return safe_pad(safe_mul(mapsize, 2));
 }
 
 int
-__glXDrawPixelsReqSize(const GLbyte * pc, Bool swap)
+__glXDrawPixelsReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLint row_length = *(GLint *) (pc + 4);
     GLint image_height = 0;
@@ -330,7 +328,7 @@ __glXDrawPixelsReqSize(const GLbyte * pc
 }
 
 int
-__glXPrioritizeTexturesReqSize(const GLbyte * pc, Bool swap)
+__glXPrioritizeTexturesReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLsizei n = *(GLsizei *) (pc + 0);
 
@@ -338,11 +336,11 @@ __glXPrioritizeTexturesReqSize(const GLb
         n = bswap_32(n);
     }
 
-    return __GLX_PAD((n * 4) + (n * 4));
+    return safe_pad(safe_add(safe_mul(n, 4), safe_mul(n, 4)));
 }
 
 int
-__glXTexSubImage1DReqSize(const GLbyte * pc, Bool swap)
+__glXTexSubImage1DReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLint row_length = *(GLint *) (pc + 4);
     GLint image_height = 0;
@@ -370,7 +368,7 @@ __glXTexSubImage1DReqSize(const GLbyte *
 }
 
 int
-__glXTexSubImage2DReqSize(const GLbyte * pc, Bool swap)
+__glXTexSubImage2DReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLint row_length = *(GLint *) (pc + 4);
     GLint image_height = 0;
@@ -400,7 +398,7 @@ __glXTexSubImage2DReqSize(const GLbyte *
 }
 
 int
-__glXColorTableReqSize(const GLbyte * pc, Bool swap)
+__glXColorTableReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLint row_length = *(GLint *) (pc + 4);
     GLint image_height = 0;
@@ -428,7 +426,7 @@ __glXColorTableReqSize(const GLbyte * pc
 }
 
 int
-__glXColorTableParameterfvReqSize(const GLbyte * pc, Bool swap)
+__glXColorTableParameterfvReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLenum pname = *(GLenum *) (pc + 4);
     GLsizei compsize;
@@ -438,11 +436,11 @@ __glXColorTableParameterfvReqSize(const 
     }
 
     compsize = __glColorTableParameterfv_size(pname);
-    return __GLX_PAD((compsize * 4));
+    return safe_pad(safe_mul(compsize, 4));
 }
 
 int
-__glXColorSubTableReqSize(const GLbyte * pc, Bool swap)
+__glXColorSubTableReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLint row_length = *(GLint *) (pc + 4);
     GLint image_height = 0;
@@ -470,7 +468,7 @@ __glXColorSubTableReqSize(const GLbyte *
 }
 
 int
-__glXConvolutionFilter1DReqSize(const GLbyte * pc, Bool swap)
+__glXConvolutionFilter1DReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLint row_length = *(GLint *) (pc + 4);
     GLint image_height = 0;
@@ -498,7 +496,7 @@ __glXConvolutionFilter1DReqSize(const GL
 }
 
 int
-__glXConvolutionFilter2DReqSize(const GLbyte * pc, Bool swap)
+__glXConvolutionFilter2DReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLint row_length = *(GLint *) (pc + 4);
     GLint image_height = 0;
@@ -528,7 +526,7 @@ __glXConvolutionFilter2DReqSize(const GL
 }
 
 int
-__glXConvolutionParameterfvReqSize(const GLbyte * pc, Bool swap)
+__glXConvolutionParameterfvReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLenum pname = *(GLenum *) (pc + 4);
     GLsizei compsize;
@@ -538,11 +536,11 @@ __glXConvolutionParameterfvReqSize(const
     }
 
     compsize = __glConvolutionParameterfv_size(pname);
-    return __GLX_PAD((compsize * 4));
+    return safe_pad(safe_mul(compsize, 4));
 }
 
 int
-__glXTexImage3DReqSize(const GLbyte * pc, Bool swap)
+__glXTexImage3DReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLint row_length = *(GLint *) (pc + 4);
     GLint image_height = *(GLint *) (pc + 8);
@@ -579,7 +577,7 @@ __glXTexImage3DReqSize(const GLbyte * pc
 }
 
 int
-__glXTexSubImage3DReqSize(const GLbyte * pc, Bool swap)
+__glXTexSubImage3DReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLint row_length = *(GLint *) (pc + 4);
     GLint image_height = *(GLint *) (pc + 8);
@@ -613,7 +611,7 @@ __glXTexSubImage3DReqSize(const GLbyte *
 }
 
 int
-__glXCompressedTexImage1DARBReqSize(const GLbyte * pc, Bool swap)
+__glXCompressedTexImage1DARBReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLsizei imageSize = *(GLsizei *) (pc + 20);
 
@@ -621,11 +619,11 @@ __glXCompressedTexImage1DARBReqSize(cons
         imageSize = bswap_32(imageSize);
     }
 
-    return __GLX_PAD(imageSize);
+    return safe_pad(imageSize);
 }
 
 int
-__glXCompressedTexImage2DARBReqSize(const GLbyte * pc, Bool swap)
+__glXCompressedTexImage2DARBReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLsizei imageSize = *(GLsizei *) (pc + 24);
 
@@ -633,11 +631,11 @@ __glXCompressedTexImage2DARBReqSize(cons
         imageSize = bswap_32(imageSize);
     }
 
-    return __GLX_PAD(imageSize);
+    return safe_pad(imageSize);
 }
 
 int
-__glXCompressedTexImage3DARBReqSize(const GLbyte * pc, Bool swap)
+__glXCompressedTexImage3DARBReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLsizei imageSize = *(GLsizei *) (pc + 28);
 
@@ -645,11 +643,11 @@ __glXCompressedTexImage3DARBReqSize(cons
         imageSize = bswap_32(imageSize);
     }
 
-    return __GLX_PAD(imageSize);
+    return safe_pad(imageSize);
 }
 
 int
-__glXCompressedTexSubImage3DARBReqSize(const GLbyte * pc, Bool swap)
+__glXCompressedTexSubImage3DARBReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLsizei imageSize = *(GLsizei *) (pc + 36);
 
@@ -657,11 +655,11 @@ __glXCompressedTexSubImage3DARBReqSize(c
         imageSize = bswap_32(imageSize);
     }
 
-    return __GLX_PAD(imageSize);
+    return safe_pad(imageSize);
 }
 
 int
-__glXProgramStringARBReqSize(const GLbyte * pc, Bool swap)
+__glXProgramStringARBReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLsizei len = *(GLsizei *) (pc + 8);
 
@@ -669,11 +667,11 @@ __glXProgramStringARBReqSize(const GLbyt
         len = bswap_32(len);
     }
 
-    return __GLX_PAD(len);
+    return safe_pad(len);
 }
 
 int
-__glXDrawBuffersARBReqSize(const GLbyte * pc, Bool swap)
+__glXDrawBuffersARBReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLsizei n = *(GLsizei *) (pc + 0);
 
@@ -681,11 +679,11 @@ __glXDrawBuffersARBReqSize(const GLbyte 
         n = bswap_32(n);
     }
 
-    return __GLX_PAD((n * 4));
+    return safe_pad((n * 4));
 }
 
 int
-__glXPointParameterfvEXTReqSize(const GLbyte * pc, Bool swap)
+__glXPointParameterfvEXTReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLenum pname = *(GLenum *) (pc + 0);
     GLsizei compsize;
@@ -695,11 +693,11 @@ __glXPointParameterfvEXTReqSize(const GL
     }
 
     compsize = __glPointParameterfvEXT_size(pname);
-    return __GLX_PAD((compsize * 4));
+    return safe_pad((compsize * 4));
 }
 
 int
-__glXProgramParameters4dvNVReqSize(const GLbyte * pc, Bool swap)
+__glXProgramParameters4dvNVReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLsizei num = *(GLsizei *) (pc + 8);
 
@@ -707,11 +705,11 @@ __glXProgramParameters4dvNVReqSize(const
         num = bswap_32(num);
     }
 
-    return __GLX_PAD((num * 32));
+    return safe_pad((num * 32));
 }
 
 int
-__glXProgramParameters4fvNVReqSize(const GLbyte * pc, Bool swap)
+__glXProgramParameters4fvNVReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLsizei num = *(GLsizei *) (pc + 8);
 
@@ -719,11 +717,11 @@ __glXProgramParameters4fvNVReqSize(const
         num = bswap_32(num);
     }
 
-    return __GLX_PAD((num * 16));
+    return safe_pad((num * 16));
 }
 
 int
-__glXVertexAttribs1dvNVReqSize(const GLbyte * pc, Bool swap)
+__glXVertexAttribs1dvNVReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLsizei n = *(GLsizei *) (pc + 4);
 
@@ -731,11 +729,11 @@ __glXVertexAttribs1dvNVReqSize(const GLb
         n = bswap_32(n);
     }
 
-    return __GLX_PAD((n * 8));
+    return safe_pad(safe_mul(n, 8));
 }
 
 int
-__glXVertexAttribs2dvNVReqSize(const GLbyte * pc, Bool swap)
+__glXVertexAttribs2dvNVReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLsizei n = *(GLsizei *) (pc + 4);
 
@@ -743,11 +741,11 @@ __glXVertexAttribs2dvNVReqSize(const GLb
         n = bswap_32(n);
     }
 
-    return __GLX_PAD((n * 16));
+    return safe_pad(safe_mul(n, 16));
 }
 
 int
-__glXVertexAttribs3dvNVReqSize(const GLbyte * pc, Bool swap)
+__glXVertexAttribs3dvNVReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLsizei n = *(GLsizei *) (pc + 4);
 
@@ -755,11 +753,11 @@ __glXVertexAttribs3dvNVReqSize(const GLb
         n = bswap_32(n);
     }
 
-    return __GLX_PAD((n * 24));
+    return safe_pad(safe_mul(n, 24));
 }
 
 int
-__glXVertexAttribs3fvNVReqSize(const GLbyte * pc, Bool swap)
+__glXVertexAttribs3fvNVReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLsizei n = *(GLsizei *) (pc + 4);
 
@@ -767,11 +765,11 @@ __glXVertexAttribs3fvNVReqSize(const GLb
         n = bswap_32(n);
     }
 
-    return __GLX_PAD((n * 12));
+    return safe_pad(safe_mul(n, 12));
 }
 
 int
-__glXVertexAttribs3svNVReqSize(const GLbyte * pc, Bool swap)
+__glXVertexAttribs3svNVReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLsizei n = *(GLsizei *) (pc + 4);
 
@@ -779,11 +777,11 @@ __glXVertexAttribs3svNVReqSize(const GLb
         n = bswap_32(n);
     }
 
-    return __GLX_PAD((n * 6));
+    return safe_pad(safe_mul(n, 6));
 }
 
 int
-__glXVertexAttribs4dvNVReqSize(const GLbyte * pc, Bool swap)
+__glXVertexAttribs4dvNVReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLsizei n = *(GLsizei *) (pc + 4);
 
@@ -791,11 +789,11 @@ __glXVertexAttribs4dvNVReqSize(const GLb
         n = bswap_32(n);
     }
 
-    return __GLX_PAD((n * 32));
+    return safe_pad(safe_mul(n, 32));
 }
 
 int
-__glXProgramNamedParameter4fvNVReqSize(const GLbyte * pc, Bool swap)
+__glXProgramNamedParameter4fvNVReqSize(const GLbyte * pc, Bool swap, int reqlen)
 {
     GLsizei len = *(GLsizei *) (pc + 4);
 
@@ -803,7 +801,7 @@ __glXProgramNamedParameter4fvNVReqSize(c
         len = bswap_32(len);
     }
 
-    return __GLX_PAD(len);
+    return safe_pad(len);
 }
 
 ALIAS(Fogiv, Fogfv)

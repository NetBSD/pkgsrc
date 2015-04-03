$NetBSD: patch-glx_indirect__reqsize.h,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- glx/indirect_reqsize.h.orig	2012-05-17 17:09:02.000000000 +0000
+++ glx/indirect_reqsize.h
@@ -36,128 +36,128 @@
 #define PURE
 #endif
 
-extern PURE _X_HIDDEN int __glXCallListsReqSize(const GLbyte * pc, Bool swap);
-extern PURE _X_HIDDEN int __glXBitmapReqSize(const GLbyte * pc, Bool swap);
-extern PURE _X_HIDDEN int __glXFogfvReqSize(const GLbyte * pc, Bool swap);
-extern PURE _X_HIDDEN int __glXFogivReqSize(const GLbyte * pc, Bool swap);
-extern PURE _X_HIDDEN int __glXLightfvReqSize(const GLbyte * pc, Bool swap);
-extern PURE _X_HIDDEN int __glXLightivReqSize(const GLbyte * pc, Bool swap);
+extern PURE _X_HIDDEN int __glXCallListsReqSize(const GLbyte * pc, Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXBitmapReqSize(const GLbyte * pc, Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXFogfvReqSize(const GLbyte * pc, Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXFogivReqSize(const GLbyte * pc, Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXLightfvReqSize(const GLbyte * pc, Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXLightivReqSize(const GLbyte * pc, Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXLightModelfvReqSize(const GLbyte * pc,
-                                                   Bool swap);
+                                                   Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXLightModelivReqSize(const GLbyte * pc,
-                                                   Bool swap);
-extern PURE _X_HIDDEN int __glXMaterialfvReqSize(const GLbyte * pc, Bool swap);
-extern PURE _X_HIDDEN int __glXMaterialivReqSize(const GLbyte * pc, Bool swap);
+                                                   Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXMaterialfvReqSize(const GLbyte * pc, Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXMaterialivReqSize(const GLbyte * pc, Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXPolygonStippleReqSize(const GLbyte * pc,
-                                                     Bool swap);
+                                                     Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXTexParameterfvReqSize(const GLbyte * pc,
-                                                     Bool swap);
+                                                     Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXTexParameterivReqSize(const GLbyte * pc,
-                                                     Bool swap);
-extern PURE _X_HIDDEN int __glXTexImage1DReqSize(const GLbyte * pc, Bool swap);
-extern PURE _X_HIDDEN int __glXTexImage2DReqSize(const GLbyte * pc, Bool swap);
-extern PURE _X_HIDDEN int __glXTexEnvfvReqSize(const GLbyte * pc, Bool swap);
-extern PURE _X_HIDDEN int __glXTexEnvivReqSize(const GLbyte * pc, Bool swap);
-extern PURE _X_HIDDEN int __glXTexGendvReqSize(const GLbyte * pc, Bool swap);
-extern PURE _X_HIDDEN int __glXTexGenfvReqSize(const GLbyte * pc, Bool swap);
-extern PURE _X_HIDDEN int __glXTexGenivReqSize(const GLbyte * pc, Bool swap);
-extern PURE _X_HIDDEN int __glXMap1dReqSize(const GLbyte * pc, Bool swap);
-extern PURE _X_HIDDEN int __glXMap1fReqSize(const GLbyte * pc, Bool swap);
-extern PURE _X_HIDDEN int __glXMap2dReqSize(const GLbyte * pc, Bool swap);
-extern PURE _X_HIDDEN int __glXMap2fReqSize(const GLbyte * pc, Bool swap);
-extern PURE _X_HIDDEN int __glXPixelMapfvReqSize(const GLbyte * pc, Bool swap);
-extern PURE _X_HIDDEN int __glXPixelMapuivReqSize(const GLbyte * pc, Bool swap);
-extern PURE _X_HIDDEN int __glXPixelMapusvReqSize(const GLbyte * pc, Bool swap);
-extern PURE _X_HIDDEN int __glXDrawPixelsReqSize(const GLbyte * pc, Bool swap);
-extern PURE _X_HIDDEN int __glXDrawArraysReqSize(const GLbyte * pc, Bool swap);
+                                                     Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXTexImage1DReqSize(const GLbyte * pc, Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXTexImage2DReqSize(const GLbyte * pc, Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXTexEnvfvReqSize(const GLbyte * pc, Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXTexEnvivReqSize(const GLbyte * pc, Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXTexGendvReqSize(const GLbyte * pc, Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXTexGenfvReqSize(const GLbyte * pc, Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXTexGenivReqSize(const GLbyte * pc, Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXMap1dReqSize(const GLbyte * pc, Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXMap1fReqSize(const GLbyte * pc, Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXMap2dReqSize(const GLbyte * pc, Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXMap2fReqSize(const GLbyte * pc, Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXPixelMapfvReqSize(const GLbyte * pc, Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXPixelMapuivReqSize(const GLbyte * pc, Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXPixelMapusvReqSize(const GLbyte * pc, Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXDrawPixelsReqSize(const GLbyte * pc, Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXDrawArraysReqSize(const GLbyte * pc, Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXPrioritizeTexturesReqSize(const GLbyte * pc,
-                                                         Bool swap);
+                                                         Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXTexSubImage1DReqSize(const GLbyte * pc,
-                                                    Bool swap);
+                                                    Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXTexSubImage2DReqSize(const GLbyte * pc,
-                                                    Bool swap);
-extern PURE _X_HIDDEN int __glXColorTableReqSize(const GLbyte * pc, Bool swap);
+                                                    Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXColorTableReqSize(const GLbyte * pc, Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXColorTableParameterfvReqSize(const GLbyte * pc,
-                                                            Bool swap);
+                                                            Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXColorTableParameterivReqSize(const GLbyte * pc,
-                                                            Bool swap);
+                                                            Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXColorSubTableReqSize(const GLbyte * pc,
-                                                    Bool swap);
+                                                    Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXConvolutionFilter1DReqSize(const GLbyte * pc,
-                                                          Bool swap);
+                                                          Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXConvolutionFilter2DReqSize(const GLbyte * pc,
-                                                          Bool swap);
+                                                          Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXConvolutionParameterfvReqSize(const GLbyte * pc,
-                                                             Bool swap);
+                                                             Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXConvolutionParameterivReqSize(const GLbyte * pc,
-                                                             Bool swap);
+                                                             Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXSeparableFilter2DReqSize(const GLbyte * pc,
-                                                        Bool swap);
-extern PURE _X_HIDDEN int __glXTexImage3DReqSize(const GLbyte * pc, Bool swap);
+                                                        Bool swap, int reqlen);
+extern PURE _X_HIDDEN int __glXTexImage3DReqSize(const GLbyte * pc, Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXTexSubImage3DReqSize(const GLbyte * pc,
-                                                    Bool swap);
+                                                    Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXCompressedTexImage1DARBReqSize(const GLbyte * pc,
-                                                              Bool swap);
+                                                              Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXCompressedTexImage2DARBReqSize(const GLbyte * pc,
-                                                              Bool swap);
+                                                              Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXCompressedTexImage3DARBReqSize(const GLbyte * pc,
-                                                              Bool swap);
+                                                              Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXCompressedTexSubImage1DARBReqSize(const GLbyte *
-                                                                 pc, Bool swap);
+                                                                 pc, Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXCompressedTexSubImage2DARBReqSize(const GLbyte *
-                                                                 pc, Bool swap);
+                                                                 pc, Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXCompressedTexSubImage3DARBReqSize(const GLbyte *
-                                                                 pc, Bool swap);
+                                                                 pc, Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXProgramStringARBReqSize(const GLbyte * pc,
-                                                       Bool swap);
+                                                       Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXDrawBuffersARBReqSize(const GLbyte * pc,
-                                                     Bool swap);
+                                                     Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXPointParameterfvEXTReqSize(const GLbyte * pc,
-                                                          Bool swap);
+                                                          Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXLoadProgramNVReqSize(const GLbyte * pc,
-                                                    Bool swap);
+                                                    Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXProgramParameters4dvNVReqSize(const GLbyte * pc,
-                                                             Bool swap);
+                                                             Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXProgramParameters4fvNVReqSize(const GLbyte * pc,
-                                                             Bool swap);
+                                                             Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXRequestResidentProgramsNVReqSize(const GLbyte *
-                                                                pc, Bool swap);
+                                                                pc, Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXVertexAttribs1dvNVReqSize(const GLbyte * pc,
-                                                         Bool swap);
+                                                         Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXVertexAttribs1fvNVReqSize(const GLbyte * pc,
-                                                         Bool swap);
+                                                         Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXVertexAttribs1svNVReqSize(const GLbyte * pc,
-                                                         Bool swap);
+                                                         Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXVertexAttribs2dvNVReqSize(const GLbyte * pc,
-                                                         Bool swap);
+                                                         Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXVertexAttribs2fvNVReqSize(const GLbyte * pc,
-                                                         Bool swap);
+                                                         Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXVertexAttribs2svNVReqSize(const GLbyte * pc,
-                                                         Bool swap);
+                                                         Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXVertexAttribs3dvNVReqSize(const GLbyte * pc,
-                                                         Bool swap);
+                                                         Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXVertexAttribs3fvNVReqSize(const GLbyte * pc,
-                                                         Bool swap);
+                                                         Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXVertexAttribs3svNVReqSize(const GLbyte * pc,
-                                                         Bool swap);
+                                                         Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXVertexAttribs4dvNVReqSize(const GLbyte * pc,
-                                                         Bool swap);
+                                                         Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXVertexAttribs4fvNVReqSize(const GLbyte * pc,
-                                                         Bool swap);
+                                                         Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXVertexAttribs4svNVReqSize(const GLbyte * pc,
-                                                         Bool swap);
+                                                         Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXVertexAttribs4ubvNVReqSize(const GLbyte * pc,
-                                                          Bool swap);
+                                                          Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXPointParameterivNVReqSize(const GLbyte * pc,
-                                                         Bool swap);
+                                                         Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXProgramNamedParameter4dvNVReqSize(const GLbyte *
-                                                                 pc, Bool swap);
+                                                                 pc, Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXProgramNamedParameter4fvNVReqSize(const GLbyte *
-                                                                 pc, Bool swap);
+                                                                 pc, Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXDeleteFramebuffersEXTReqSize(const GLbyte * pc,
-                                                            Bool swap);
+                                                            Bool swap, int reqlen);
 extern PURE _X_HIDDEN int __glXDeleteRenderbuffersEXTReqSize(const GLbyte * pc,
-                                                             Bool swap);
+                                                             Bool swap, int reqlen);
 
 #undef PURE
 

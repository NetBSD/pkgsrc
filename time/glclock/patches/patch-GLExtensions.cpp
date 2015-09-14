$NetBSD: patch-GLExtensions.cpp,v 1.1 2015/09/14 20:00:31 tnn Exp $

glPolygonOffset has been core OpenGL since 1.1 and mesa no longer
declares it as an extension.

--- GLextensions.cpp.orig	2000-06-18 14:25:12.000000000 +0000
+++ GLextensions.cpp
@@ -1083,7 +1083,7 @@ char *IsSupported_texture_object(int fla
 #ifdef GL_EXT_polygon_offset
 	if (has_EXT_polygon_offset)
 	{
-		glPolygonOffsetEXT(units, bias) ;
+		glPolygonOffset(units, bias) ;
 		glEnable(GL_POLYGON_OFFSET_EXT) ;
 
 		glGetFloatv(GL_POLYGON_OFFSET_FACTOR_EXT, &facter) ;
@@ -1108,7 +1108,7 @@ int IsSupported_EXT_polygon_offset()
 		return FALSE ;
 #endif	// #if defined(WIN32) && !defined(MESA)
 
-	p_glPolygonOffset = glPolygonOffsetEXT ;
+	p_glPolygonOffset = glPolygonOffset;
 
 	DEF_GL_POLYGON_OFFSET_POINT  = GL_POLYGON_OFFSET_EXT ;	// EXT_polygon_offset では、すべて共通（有効なのは FILL のみ？）
 	DEF_GL_POLYGON_OFFSET_LINE   = GL_POLYGON_OFFSET_EXT ;

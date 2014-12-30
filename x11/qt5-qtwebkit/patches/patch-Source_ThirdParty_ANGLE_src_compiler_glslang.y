$NetBSD: patch-Source_ThirdParty_ANGLE_src_compiler_glslang.y,v 1.1 2014/12/30 17:23:47 adam Exp $

* Fix build with bison 3

--- Source/ThirdParty/ANGLE/src/compiler/glslang.y.orig	2013-11-27 01:01:50.000000000 +0000
+++ Source/ThirdParty/ANGLE/src/compiler/glslang.y
@@ -47,7 +47,7 @@ WHICH GENERATES THE GLSL ES PARSER (glsl
 %pure-parser
 %parse-param {TParseContext* context}
 %locations
-%lex-param {YYLEX_PARAM}
+%lex-param {TParseContext* context}
 
 %union {
 #define YYLTYPE TSourceLoc

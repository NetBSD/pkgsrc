$NetBSD: patch-Source_ThirdParty_ANGLE_src_compiler_glslang.y,v 1.1 2013/08/01 06:14:54 wiz Exp $

--- Source/ThirdParty/ANGLE/src/compiler/glslang.y.orig	2012-11-23 20:12:16.000000000 +0000
+++ Source/ThirdParty/ANGLE/src/compiler/glslang.y
@@ -47,6 +47,7 @@ WHICH GENERATES THE GLSL ES PARSER (glsl
 %expect 1 /* One shift reduce conflict because of if | else */
 %pure-parser
 %parse-param {TParseContext* context}
+%lex-param {TParseContext* context}
 
 %union {
     struct {

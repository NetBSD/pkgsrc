$NetBSD: patch-awesomeConfig.cmake,v 1.9 2024/02/14 03:31:15 gutteridge Exp $

If pkgtools/pkg_alternatives is not installed, the asciidoctor
binary is suffixed by the ruby version.

--- awesomeConfig.cmake.orig	2019-01-28 06:53:24.000000000 +0000
+++ awesomeConfig.cmake
@@ -38,6 +38,9 @@ endmacro()
 a_find_program(GIT_EXECUTABLE git FALSE)
 # programs needed for man pages
 a_find_program(ASCIIDOCTOR_EXECUTABLE asciidoctor FALSE)
+a_find_program(ASCIIDOCTOR_EXECUTABLE asciidoctor31 FALSE)
+a_find_program(ASCIIDOCTOR_EXECUTABLE asciidoctor32 FALSE)
+a_find_program(ASCIIDOCTOR_EXECUTABLE asciidoctor33 FALSE)
 a_find_program(GZIP_EXECUTABLE gzip FALSE)
 # Lua documentation
 if(GENERATE_DOC)

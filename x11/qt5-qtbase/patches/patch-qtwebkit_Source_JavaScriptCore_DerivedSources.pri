$NetBSD: patch-qtwebkit_Source_JavaScriptCore_DerivedSources.pri,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Make conditional for Unix

--- qtwebkit/Source/JavaScriptCore/DerivedSources.pri.orig	2013-11-27 01:01:48.000000000 +0000
+++ qtwebkit/Source/JavaScriptCore/DerivedSources.pri
@@ -108,7 +108,7 @@ llint.depends = $$LLINT_DEPENDENCY
 llint.commands = ruby $$llint.script $$LLINT_ASSEMBLER ${QMAKE_FILE_IN} ${QMAKE_FILE_OUT}
 GENERATORS += llint
 
-linux-*:if(isEqual(QT_ARCH, "i386")|isEqual(QT_ARCH, "x86_64")) {
+unix-*:if(isEqual(QT_ARCH, "i386")|isEqual(QT_ARCH, "x86_64")) {
     # GENERATOR: disassembler
     disassembler.output = udis86_itab.c
     disassembler.input = DISASSEMBLER_FILES

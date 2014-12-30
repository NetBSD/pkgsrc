$NetBSD: patch-Source_JavaScriptCore_DerivedSources.pri,v 1.1 2014/12/30 17:23:47 adam Exp $

* Make conditional for Unix

--- Source/JavaScriptCore/DerivedSources.pri.orig	2013-11-27 01:01:48.000000000 +0000
+++ Source/JavaScriptCore/DerivedSources.pri
@@ -108,7 +108,7 @@ llint.depends = $$LLINT_DEPENDENCY
 llint.commands = ruby $$llint.script $$LLINT_ASSEMBLER ${QMAKE_FILE_IN} ${QMAKE_FILE_OUT}
 GENERATORS += llint
 
-linux-*:if(isEqual(QT_ARCH, "i386")|isEqual(QT_ARCH, "x86_64")) {
+unix-*:if(isEqual(QT_ARCH, "i386")|isEqual(QT_ARCH, "x86_64")) {
     # GENERATOR: disassembler
     disassembler.output = udis86_itab.c
     disassembler.input = DISASSEMBLER_FILES

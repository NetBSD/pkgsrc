$NetBSD: patch-Source_ThirdParty_ANGLE_src_compiler_translator_SymbolTable.h,v 1.1 2019/09/15 10:58:52 leot Exp $

Include <cmath> for is isinf/isnan used in SymbolTable_autogen.cpp.

--- Source/ThirdParty/ANGLE/src/compiler/translator/SymbolTable.h.orig	2019-08-28 11:46:28.000000000 +0000
+++ Source/ThirdParty/ANGLE/src/compiler/translator/SymbolTable.h
@@ -30,6 +30,7 @@
 //   are tracked in the intermediate representation, not the symbol table.
 //
 
+#include <cmath>
 #include <memory>
 #include <set>
 

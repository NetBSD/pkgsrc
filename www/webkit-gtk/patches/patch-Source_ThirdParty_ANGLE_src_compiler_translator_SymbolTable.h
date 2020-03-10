$NetBSD: patch-Source_ThirdParty_ANGLE_src_compiler_translator_SymbolTable.h,v 1.2 2020/03/10 18:14:04 leot Exp $

Include <cmath> for is isinf/isnan used in SymbolTable_autogen.cpp.

--- Source/ThirdParty/ANGLE/src/compiler/translator/SymbolTable.h.orig	2020-02-04 10:24:05.000000000 +0000
+++ Source/ThirdParty/ANGLE/src/compiler/translator/SymbolTable.h
@@ -30,6 +30,7 @@
 //   are tracked in the intermediate representation, not the symbol table.
 //
 
+#include <cmath>
 #include <limits>
 #include <memory>
 #include <set>

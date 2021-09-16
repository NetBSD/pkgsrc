$NetBSD: patch-gfx_angle_checkout_src_compiler_translator_SymbolTable__autogen.cpp,v 1.1 2021/09/16 14:59:32 nia Exp $

https://bugzilla.mozilla.org/show_bug.cgi?id=1490673

--- gfx/angle/checkout/src/compiler/translator/SymbolTable_autogen.cpp.orig	2021-05-25 18:33:36.000000000 +0000
+++ gfx/angle/checkout/src/compiler/translator/SymbolTable_autogen.cpp
@@ -9,6 +9,8 @@
 // SymbolTable_autogen.cpp:
 //   Compile-time initialized built-ins.
 
+#include <cmath>
+
 #include "compiler/translator/SymbolTable.h"
 
 #include "angle_gl.h"

$NetBSD: patch-gfx_angle_checkout_src_compiler_translator_SymbolTable__autogen.cpp,v 1.3 2025/04/14 15:33:04 nia Exp $

https://bugzilla.mozilla.org/show_bug.cgi?id=1490673

--- gfx/angle/checkout/src/compiler/translator/SymbolTable_autogen.cpp.orig	2025-03-07 18:41:08.227022033 +0000
+++ gfx/angle/checkout/src/compiler/translator/SymbolTable_autogen.cpp
@@ -11,6 +11,7 @@
 
 #ifndef ANGLE_TRANSLATOR_ESSL_ONLY
 
+#    include <cmath>
 #    include "compiler/translator/SymbolTable.h"
 
 #    include "angle_gl.h"

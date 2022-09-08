$NetBSD: patch-gfx_angle_checkout_src_compiler_translator_SymbolTable__autogen.cpp,v 1.2 2022/09/08 20:27:32 ryoon Exp $

https://bugzilla.mozilla.org/show_bug.cgi?id=1490673

--- gfx/angle/checkout/src/compiler/translator/SymbolTable_autogen.cpp.orig	2022-06-08 19:10:28.000000000 +0000
+++ gfx/angle/checkout/src/compiler/translator/SymbolTable_autogen.cpp
@@ -11,6 +11,8 @@
 
 #ifndef ANGLE_TRANSLATOR_ESSL_ONLY
 
+#include <cmath>
+
 #    include "compiler/translator/SymbolTable.h"
 
 #    include "angle_gl.h"

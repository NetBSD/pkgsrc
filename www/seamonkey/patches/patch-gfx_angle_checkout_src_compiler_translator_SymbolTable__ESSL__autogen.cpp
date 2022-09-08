$NetBSD: patch-gfx_angle_checkout_src_compiler_translator_SymbolTable__ESSL__autogen.cpp,v 1.1 2022/09/08 20:27:32 ryoon Exp $

--- gfx/angle/checkout/src/compiler/translator/SymbolTable_ESSL_autogen.cpp.orig	2022-06-08 19:10:28.000000000 +0000
+++ gfx/angle/checkout/src/compiler/translator/SymbolTable_ESSL_autogen.cpp
@@ -11,6 +11,8 @@
 
 #ifdef ANGLE_TRANSLATOR_ESSL_ONLY
 
+#include <cmath>
+
 #    include "compiler/translator/SymbolTable.h"
 
 #    include "angle_gl.h"

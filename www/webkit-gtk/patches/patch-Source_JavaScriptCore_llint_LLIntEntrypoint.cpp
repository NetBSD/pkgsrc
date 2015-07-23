$NetBSD: patch-Source_JavaScriptCore_llint_LLIntEntrypoint.cpp,v 1.1 2015/07/23 11:10:49 joerg Exp $

--- Source/JavaScriptCore/llint/LLIntEntrypoint.cpp.orig	2015-07-22 11:57:53.000000000 +0000
+++ Source/JavaScriptCore/llint/LLIntEntrypoint.cpp
@@ -28,6 +28,7 @@
 #include "CodeBlock.h"
 #include "HeapInlines.h"
 #include "JITCode.h"
+#include "JSCellInlines.h"
 #include "JSObject.h"
 #include "LLIntThunks.h"
 #include "LowLevelInterpreter.h"

$NetBSD: patch-Source_JavaScriptCore_runtime_FunctionExecutableDump.cpp,v 1.1 2015/07/23 11:10:49 joerg Exp $

--- Source/JavaScriptCore/runtime/FunctionExecutableDump.cpp.orig	2015-07-22 11:57:35.000000000 +0000
+++ Source/JavaScriptCore/runtime/FunctionExecutableDump.cpp
@@ -25,6 +25,7 @@
 
 #include "config.h"
 #include "FunctionExecutableDump.h"
+#include "JSCellInlines.h"
 
 #include "CodeBlock.h"
 

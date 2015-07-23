$NetBSD: patch-Source_WebCore_editing_InsertNodeBeforeCommand.cpp,v 1.1 2015/07/23 11:10:49 joerg Exp $

--- Source/WebCore/editing/InsertNodeBeforeCommand.cpp.orig	2015-07-22 12:33:49.000000000 +0000
+++ Source/WebCore/editing/InsertNodeBeforeCommand.cpp
@@ -29,6 +29,7 @@
 #include "AXObjectCache.h"
 #include "Document.h"
 #include "ExceptionCodePlaceholder.h"
+#include "RenderElement.h"
 #include "htmlediting.h"
 
 namespace WebCore {

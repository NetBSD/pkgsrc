$NetBSD: patch-include_xqilla_framework_XPath2MemoryManager.hpp,v 1.1 2015/06/29 21:41:11 markd Exp $

include <cstddef> for ptrdiff_t

--- include/xqilla/framework/XPath2MemoryManager.hpp.orig	2010-01-13 15:40:36.000000000 +0000
+++ include/xqilla/framework/XPath2MemoryManager.hpp
@@ -24,6 +24,7 @@
 
 #include <algorithm>
 #include <assert.h>
+#include <cstddef>
 
 #include <xqilla/framework/XQillaExport.hpp>
 

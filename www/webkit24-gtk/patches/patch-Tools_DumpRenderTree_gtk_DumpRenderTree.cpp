$NetBSD: patch-Tools_DumpRenderTree_gtk_DumpRenderTree.cpp,v 1.1 2015/07/12 00:37:47 wiz Exp $

--- Tools/DumpRenderTree/gtk/DumpRenderTree.cpp.orig	2014-04-14 06:40:46.000000000 +0000
+++ Tools/DumpRenderTree/gtk/DumpRenderTree.cpp
@@ -47,6 +47,7 @@
 #include <JavaScriptCore/JavaScript.h>
 #include <WebCore/platform/network/soup/GUniquePtrSoup.h>
 #include <cassert>
+#include <clocate>
 #include <cstdlib>
 #include <cstring>
 #include <getopt.h>

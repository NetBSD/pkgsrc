$NetBSD: patch-src_3rdparty_webkit_Source_WebKit2_DerivedSources.pro,v 1.1 2016/04/29 11:17:31 nros Exp $
* Don't create prl since it is created in /include/WebCore and not in
  the source tree.
--- src/3rdparty/webkit/Source/WebKit2/DerivedSources.pro.orig	2016-04-29 10:42:47.000000000 +0000
+++ src/3rdparty/webkit/Source/WebKit2/DerivedSources.pro
@@ -1,7 +1,7 @@
 TEMPLATE = lib
 TARGET = dummy
 
-CONFIG -= debug_and_release
+CONFIG -= debug_and_release create_prl
 
 CONFIG(standalone_package) {
     isEmpty(WEBKIT2_GENERATED_SOURCES_DIR):WEBKIT2_GENERATED_SOURCES_DIR = $$PWD/generated

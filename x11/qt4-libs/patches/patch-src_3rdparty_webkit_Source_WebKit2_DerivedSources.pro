$NetBSD: patch-src_3rdparty_webkit_Source_WebKit2_DerivedSources.pro,v 1.2 2016/05/25 07:46:47 nros Exp $
* Don't create prl and put /include/WebCore inside the src directory
  to not pullute /, it is empty and unused in qt4.
--- src/3rdparty/webkit/Source/WebKit2/DerivedSources.pro.orig	2016-04-29 10:42:47.000000000 +0000
+++ src/3rdparty/webkit/Source/WebKit2/DerivedSources.pro
@@ -1,7 +1,7 @@
 TEMPLATE = lib
 TARGET = dummy
 
-CONFIG -= debug_and_release
+CONFIG -= debug_and_release create_prl
 
 CONFIG(standalone_package) {
     isEmpty(WEBKIT2_GENERATED_SOURCES_DIR):WEBKIT2_GENERATED_SOURCES_DIR = $$PWD/generated
@@ -158,7 +158,7 @@
     HEADER_PATH = $$HEADER
     HEADER_TARGET = $$replace(HEADER_PATH, [^a-zA-Z0-9_], -)
     HEADER_TARGET = "qtheader-$${HEADER_TARGET}"
-    DESTDIR = $$OUTPUT_DIR/include/"WebCore"
+    DESTDIR = $$PWD/../include/"WebCore"
 
     eval($${HEADER_TARGET}.target = $$DESTDIR/$$HEADER_NAME)
     eval($${HEADER_TARGET}.depends = $$HEADER_PATH)

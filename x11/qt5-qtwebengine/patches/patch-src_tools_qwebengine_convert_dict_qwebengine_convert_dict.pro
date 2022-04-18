$NetBSD: patch-src_tools_qwebengine_convert_dict_qwebengine_convert_dict.pro,v 1.2 2022/04/18 11:18:19 adam Exp $

--- src/tools/qwebengine_convert_dict/qwebengine_convert_dict.pro.orig
+++ src/tools/qwebengine_convert_dict/qwebengine_convert_dict.pro
@@ -12,7 +12,7 @@ isEmpty(NINJA_LFLAGS): error("Missing linker flags fro
 isEmpty(NINJA_ARCHIVES): error("Missing archive files from QtWebEngineCore linking pri")
 isEmpty(NINJA_LIBS): error("Missing library files from QtWebEngineCore linking pri")
 OBJECTS = $$eval($$list($$NINJA_OBJECTS))
-linux {
+unix {
     LIBS_PRIVATE = -Wl,--start-group $$NINJA_ARCHIVES -Wl,--end-group
 } else {
     LIBS_PRIVATE = $$NINJA_ARCHIVES

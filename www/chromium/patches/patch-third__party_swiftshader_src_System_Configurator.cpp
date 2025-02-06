$NetBSD: patch-third__party_swiftshader_src_System_Configurator.cpp,v 1.1 2025/02/06 09:58:28 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/swiftshader/src/System/Configurator.cpp.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/swiftshader/src/System/Configurator.cpp
@@ -38,6 +38,9 @@ namespace sw {
 
 Configurator::Configurator(const std::string &filePath)
 {
+#if defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+	return;
+#endif
 	std::fstream file(filePath, std::ios::in);
 	if(file.fail())
 	{

$NetBSD: patch-tools_gn_src_gn_version.h,v 1.8 2025/10/16 19:43:36 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/gn/src/gn/version.h.orig	2025-10-13 21:41:26.000000000 +0000
+++ tools/gn/src/gn/version.h
@@ -22,9 +22,9 @@ class Version {
 
   static std::optional<Version> FromString(std::string s);
 
-  int major() const { return major_; }
-  int minor() const { return minor_; }
-  int patch() const { return patch_; }
+  int gmajor() const { return major_; }
+  int gminor() const { return minor_; }
+  int gpatch() const { return patch_; }
 
   bool operator==(const Version& other) const;
   bool operator<(const Version& other) const;

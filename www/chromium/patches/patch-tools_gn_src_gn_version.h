$NetBSD: patch-tools_gn_src_gn_version.h,v 1.19 2026/05/10 15:30:06 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- tools/gn/src/gn/version.h.orig	2026-04-28 23:05:57.000000000 +0200
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

$NetBSD: patch-chrome_browser_enterprise_profile__management_profile__management__navigation__throttle.cc,v 1.25 2026/09/02 13:13:23 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/enterprise/profile_management/profile_management_navigation_throttle.cc.orig	2026-08-31 22:47:51.000000000 +0000
+++ chrome/browser/enterprise/profile_management/profile_management_navigation_throttle.cc
@@ -66,8 +66,8 @@ base::flat_map<std::string, SAMLProfileA
   // TODO(crbug.com/40267996): Add actual domains with attribute names.
   profile_attributes->insert(std::make_pair(
       "supported.test",
-      SAMLProfileAttributes("placeholderName", "placeholderDomain",
-                            "placeholderToken")));
+      SAMLProfileAttributes(SAMLProfileAttributes{"placeholderName", "placeholderDomain",
+                            "placeholderToken"})));
 
   // Extract domains and attributes from the command line switch.
   const base::CommandLine& command_line =

$NetBSD: patch-content_common_font__list__unittest.cc,v 1.20 2026/06/01 10:09:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/common/font_list_unittest.cc.orig	2026-05-26 20:39:02.000000000 +0000
+++ content/common/font_list_unittest.cc
@@ -48,7 +48,7 @@ TEST(FontList, GetFontList) {
         EXPECT_TRUE(HasFontWithName(fonts, "MS Gothic", "MS Gothic"));
         EXPECT_TRUE(HasFontWithName(fonts, "Segoe UI", "Segoe UI"));
         EXPECT_TRUE(HasFontWithName(fonts, "Verdana", "Verdana"));
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
         EXPECT_TRUE(HasFontWithName(fonts, "Arimo", "Arimo"));
 #else
         EXPECT_TRUE(HasFontWithName(fonts, "Arial", "Arial"));

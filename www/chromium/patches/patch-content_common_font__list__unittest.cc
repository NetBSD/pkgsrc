$NetBSD: patch-content_common_font__list__unittest.cc,v 1.11 2025/12/11 09:13:38 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/common/font_list_unittest.cc.orig	2025-11-19 21:40:05.000000000 +0000
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

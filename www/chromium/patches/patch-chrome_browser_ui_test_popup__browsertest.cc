$NetBSD: patch-chrome_browser_ui_test_popup__browsertest.cc,v 1.19 2026/05/10 15:29:52 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/test/popup_browsertest.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ chrome/browser/ui/test/popup_browsertest.cc
@@ -76,7 +76,7 @@ IN_PROC_BROWSER_TEST_F(PopupTest, OpenLe
   const display::Display display = GetDisplayNearestBrowser(popup);
   gfx::Rect expected(popup->window()->GetBounds().size());
   expected.AdjustToFit(display.work_area());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/40815883) Desktop Linux window bounds are inaccurate.
   expected.Outset(50);
   EXPECT_TRUE(expected.Contains(popup->window()->GetBounds()))
@@ -108,7 +108,7 @@ IN_PROC_BROWSER_TEST_F(PopupTest, OpenCl
     // The popup should be constrained to the opener's available display space.
     EXPECT_EQ(display, GetDisplayNearestBrowser(popup));
     gfx::Rect work_area(display.work_area());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // TODO(crbug.com/40815883) Desktop Linux bounds flakily extend outside the
     // work area on trybots, when opening with excessive width and height, e.g.:
     // width=${screen.availWidth+300},height=${screen.availHeight+300} yields:

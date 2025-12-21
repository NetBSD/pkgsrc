$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_core_editing_editing__behavior.cc,v 1.1 2025/12/21 09:38:39 markd Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- src/3rdparty/chromium/third_party/blink/renderer/core/editing/editing_behavior.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/core/editing/editing_behavior.cc
@@ -304,7 +304,7 @@ bool EditingBehavior::ShouldInsertCharac
   // unexpected behaviour
   if (ch < ' ')
     return false;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // According to XKB map no keyboard combinations with ctrl key are mapped to
   // printable characters, however we need the filter as the DomKey/text could
   // contain printable characters.

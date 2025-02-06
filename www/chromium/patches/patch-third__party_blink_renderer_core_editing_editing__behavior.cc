$NetBSD: patch-third__party_blink_renderer_core_editing_editing__behavior.cc,v 1.1 2025/02/06 09:58:23 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/editing/editing_behavior.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/blink/renderer/core/editing/editing_behavior.cc
@@ -304,7 +304,7 @@ bool EditingBehavior::ShouldInsertCharac
   // unexpected behaviour
   if (ch < ' ')
     return false;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // According to XKB map no keyboard combinations with ctrl key are mapped to
   // printable characters, however we need the filter as the DomKey/text could
   // contain printable characters.

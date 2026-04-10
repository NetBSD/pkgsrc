$NetBSD: patch-third__party_blink_renderer_core_editing_editing__behavior.cc,v 1.17 2026/04/10 17:31:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/core/editing/editing_behavior.cc.orig	2026-04-06 16:25:54.000000000 +0000
+++ third_party/blink/renderer/core/editing/editing_behavior.cc
@@ -138,7 +138,7 @@ const KeyboardCodeKeyDownEntry kKeyboard
     {VKEY_DELETE, 0, "DeleteForward"},
     {VKEY_BACK, OPTION_OR_CTRL_KEY, "DeleteWordBackward"},
     {VKEY_DELETE, OPTION_OR_CTRL_KEY, "DeleteWordForward"},
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {VKEY_BACK, kCtrlKey | kShiftKey, "DeleteToBeginningOfLine"},
 #endif
 #if BUILDFLAG(IS_MAC)
@@ -307,7 +307,7 @@ bool EditingBehavior::ShouldInsertCharac
   // unexpected behaviour
   if (ch < ' ')
     return false;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // According to XKB map no keyboard combinations with ctrl key are mapped to
   // printable characters, however we need the filter as the DomKey/text could
   // contain printable characters.

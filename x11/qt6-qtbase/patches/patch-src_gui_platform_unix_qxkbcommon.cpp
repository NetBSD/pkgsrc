$NetBSD: patch-src_gui_platform_unix_qxkbcommon.cpp,v 1.1 2023/10/20 07:56:57 tnn Exp $

* libxkbcommon-1.6.0 removes these 4 symbols.

--- src/gui/platform/unix/qxkbcommon.cpp.orig	2023-09-21 19:24:26.000000000 +0000
+++ src/gui/platform/unix/qxkbcommon.cpp
@@ -239,10 +239,6 @@ static constexpr const auto KeyTbl = qMa
         Xkb2Qt<XKB_KEY_dead_small_schwa,        Qt::Key_Dead_Small_Schwa>,
         Xkb2Qt<XKB_KEY_dead_capital_schwa,      Qt::Key_Dead_Capital_Schwa>,
         Xkb2Qt<XKB_KEY_dead_greek,              Qt::Key_Dead_Greek>,
-        Xkb2Qt<XKB_KEY_dead_lowline,            Qt::Key_Dead_Lowline>,
-        Xkb2Qt<XKB_KEY_dead_aboveverticalline,  Qt::Key_Dead_Aboveverticalline>,
-        Xkb2Qt<XKB_KEY_dead_belowverticalline,  Qt::Key_Dead_Belowverticalline>,
-        Xkb2Qt<XKB_KEY_dead_longsolidusoverlay, Qt::Key_Dead_Longsolidusoverlay>,
 
         // Special keys from X.org - This include multimedia keys,
         // wireless/bluetooth/uwb keys, special launcher keys, etc.

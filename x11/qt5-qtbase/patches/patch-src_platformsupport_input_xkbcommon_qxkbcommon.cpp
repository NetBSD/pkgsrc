$NetBSD: patch-src_platformsupport_input_xkbcommon_qxkbcommon.cpp,v 1.1 2023/10/19 23:13:18 ryoon Exp $

* libxkbcommon-1.6.0 removes these 4 symbols.

--- src/platformsupport/input/xkbcommon/qxkbcommon.cpp.orig	2023-06-09 14:30:54.000000000 +0000
+++ src/platformsupport/input/xkbcommon/qxkbcommon.cpp
@@ -273,10 +273,6 @@ static constexpr const auto KeyTbl = qMa
         Xkb2Qt<XKB_KEY_dead_small_schwa,        Qt::Key_Dead_Small_Schwa>,
         Xkb2Qt<XKB_KEY_dead_capital_schwa,      Qt::Key_Dead_Capital_Schwa>,
         Xkb2Qt<XKB_KEY_dead_greek,              Qt::Key_Dead_Greek>,
-        Xkb2Qt<XKB_KEY_dead_lowline,            Qt::Key_Dead_Lowline>,
-        Xkb2Qt<XKB_KEY_dead_aboveverticalline,  Qt::Key_Dead_Aboveverticalline>,
-        Xkb2Qt<XKB_KEY_dead_belowverticalline,  Qt::Key_Dead_Belowverticalline>,
-        Xkb2Qt<XKB_KEY_dead_longsolidusoverlay, Qt::Key_Dead_Longsolidusoverlay>,
 
         // Special keys from X.org - This include multimedia keys,
         // wireless/bluetooth/uwb keys, special launcher keys, etc.

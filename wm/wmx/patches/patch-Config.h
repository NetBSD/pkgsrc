$NetBSD: patch-Config.h,v 1.1 2020/04/28 15:28:57 nikita Exp $

--- Config.h.orig       2020-04-28 17:06:07.665643251 +0200
+++ Config.h    2020-04-28 17:10:09.868288671 +0200
@@ -79,7 +79,7 @@
 
 // What to run to get a new window (from the "New" menu option)
 #define CONFIG_NEW_WINDOW_LABEL "New"
-#define CONFIG_NEW_WINDOW_COMMAND "x-terminal-emulator"
+#define CONFIG_NEW_WINDOW_COMMAND "xterm"
 #define CONFIG_NEW_WINDOW_COMMAND_OPTIONS 0
 // or, for example,
 //#define CONFIG_NEW_WINDOW_COMMAND_OPTIONS "-ls","-sb","-sl","1024",0
@@ -94,7 +94,7 @@
 // middle-button menu
 #define CONFIG_COMMAND_MENU       ".wmx"
 // only used if COMMAND_MENU is not found; ignored if invalid directory:
-#define CONFIG_SYSTEM_COMMAND_MENU	"/usr/local/lib/wmx/menu"
+#define CONFIG_SYSTEM_COMMAND_MENU	PREFIX "/etc/wmx/menu"
 // append screennumber to COMMAND_MENU directory;
 // use non screen style as fallback
 #define CONFIG_ADD_SCREEN_TO_COMMAND_MENU False
@@ -419,7 +419,9 @@
 // command menu, and the middle mouse button (button2)
 // acts like the left mouse normally does (list of windows)
 
+#ifndef CONFIG_GNOME_BUTTON_COMPLIANCE
 #define CONFIG_GNOME_BUTTON_COMPLIANCE   False
+#endif
 
 #endif

$NetBSD: patch-setup.py,v 1.4 2026/03/30 16:55:13 ktnb Exp $

Only point to the pkgsrc fonts for darwin

--- setup.py.orig	2026-03-27 19:19:48.618708465 +0000
+++ setup.py
@@ -924,7 +924,8 @@ def add_builtin_fonts(args: Options) ->
         font_file = ''
         if is_macos:
             candidates = (
-                os.path.expanduser('~/Library/Fonts'), '/Library/Fonts', '/System/Library/Fonts', '/Network/Library/Fonts')
+                '@PREFIX@/share/fonts/'
+            )
             for candidate in candidates:
                 q = os.path.join(candidate, filename)
                 if os.path.exists(q):

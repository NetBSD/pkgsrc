$NetBSD: patch-setup.py,v 1.7 2026/07/19 00:35:25 ktnb Exp $

Only point to the pkgsrc fonts for Darwin.
Don't crash on colored emoji render on NetBSD.

--- setup.py.orig	2026-07-18 02:07:54.000000000 +0000
+++ setup.py
@@ -544,6 +544,9 @@ def init_env(
     )
     ldflags = shlex.split(ldflags_)
     ldflags.append('-shared')
+    if is_netbsd:
+        ldflags.insert(0, '-Wl,--no-as-needed')
+        ldflags.insert(1, '@PKGSRC_FREETYPE_LIB@')
     cppflags += env_cppflags
     cflags += env_cflags
     if fortify_source:
@@ -924,7 +927,8 @@ def add_builtin_fonts(args: Options) -> None:
         font_file = ''
         if is_macos:
             candidates = (
-                os.path.expanduser('~/Library/Fonts'), '/Library/Fonts', '/System/Library/Fonts', '/Network/Library/Fonts')
+                '@PREFIX@/share/fonts/',
+            )
             for candidate in candidates:
                 q = os.path.join(candidate, filename)
                 if os.path.exists(q):

$NetBSD: patch-setup.py,v 1.9 2026/09/26 01:04:16 ktnb Exp $

Only point to the pkgsrc fonts for Darwin.
Don't crash on colored emoji render on NetBSD.

--- setup.py.orig	2026-09-21 03:27:08.000000000 +0000
+++ setup.py
@@ -655,6 +655,9 @@ def init_env(
     ldflags_ = os.environ.get('OVERRIDE_LDFLAGS', '-Wall ' + ' '.join(sanitize_args) + ('' if debug else ' -O3'))
     ldflags = shlex.split(ldflags_)
     ldflags.append('-shared')
+    if is_netbsd:
+        ldflags.insert(0, '-Wl,--no-as-needed')
+        ldflags.insert(1, '@PKGSRC_FREETYPE_LIB@')
     cppflags += env_cppflags
     cflags += env_cflags
     if fortify_source:
@@ -1059,7 +1062,10 @@ def add_builtin_fonts(args: Options) -> None:
             continue
         font_file = ''
         if is_macos:
-            candidates = (os.path.expanduser('~/Library/Fonts'), '/Library/Fonts', '/System/Library/Fonts', '/Network/Library/Fonts')
+            candidates = (
+              os.path.expanduser('~/Library/Fonts'), '/Library/Fonts', '/System/Library/Fonts', '/Network/Library/Fonts',
+              '@PREFIX@/share/fonts/',
+            )
             for candidate in candidates:
                 q = os.path.join(candidate, filename)
                 if os.path.exists(q):

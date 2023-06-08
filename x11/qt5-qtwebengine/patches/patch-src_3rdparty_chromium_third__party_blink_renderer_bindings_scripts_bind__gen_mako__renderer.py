$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_bindings_scripts_bind__gen_mako__renderer.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/bind_gen/mako_renderer.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/bind_gen/mako_renderer.py
@@ -105,7 +105,7 @@ class MakoRenderer(object):
             on_error = self._caller_stack_on_error
             if (len(current) <= len(on_error)
                     and all(current[i] == on_error[i]
-                            for i in xrange(len(current)))):
+                            for i in range(len(current)))):
                 pass  # Error happened in a deeper caller.
             else:
                 self._caller_stack_on_error = list(self._caller_stack)

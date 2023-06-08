$NetBSD: patch-src_3rdparty_chromium_third__party_blink_renderer_bindings_scripts_bind__gen_callback__interface.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/bind_gen/callback_interface.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/third_party/blink/renderer/bindings/scripts/bind_gen/callback_interface.py
@@ -177,7 +177,7 @@ def generate_callback_interface(callback
          prop_install_mode=PropInstallMode.UNCONDITIONAL,
          trampoline_var_name=None,
          attribute_entries=[],
-         constant_entries=filter(is_unconditional, constant_entries),
+         constant_entries=list(filter(is_unconditional, constant_entries)),
          exposed_construct_entries=[],
          operation_entries=[])
     (install_interface_template_decl, install_interface_template_def,

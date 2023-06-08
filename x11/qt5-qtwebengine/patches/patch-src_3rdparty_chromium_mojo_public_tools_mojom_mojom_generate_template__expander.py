$NetBSD: patch-src_3rdparty_chromium_mojo_public_tools_mojom_mojom_generate_template__expander.py,v 1.1 2023/06/08 20:38:06 markd Exp $

build with python3

--- src/3rdparty/chromium/mojo/public/tools/mojom/mojom/generate/template_expander.py.orig	2022-03-30 09:48:18.000000000 +0000
+++ src/3rdparty/chromium/mojo/public/tools/mojom/mojom/generate/template_expander.py
@@ -75,9 +75,9 @@ def PrecompileTemplates(generator_module
                 os.path.dirname(module.__file__), generator.GetTemplatePrefix())
         ]))
     jinja_env.filters.update(generator.GetFilters())
-    jinja_env.compile_templates(
-        os.path.join(output_dir, "%s.zip" % generator.GetTemplatePrefix()),
-        extensions=["tmpl"],
-        zip="stored",
-        py_compile=True,
-        ignore_errors=False)
+    jinja_env.compile_templates(os.path.join(
+        output_dir, "%s.zip" % generator.GetTemplatePrefix()),
+                                extensions=["tmpl"],
+                                zip="stored",
+                                py_compile=sys.version_info.major < 3,
+                                ignore_errors=False)

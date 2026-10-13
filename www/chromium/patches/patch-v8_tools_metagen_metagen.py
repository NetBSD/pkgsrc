$NetBSD: patch-v8_tools_metagen_metagen.py,v 1.1 2026/10/13 13:16:53 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/tools/metagen/metagen.py.orig	2026-10-06 00:06:58.000000000 +0000
+++ v8/tools/metagen/metagen.py
@@ -315,12 +315,6 @@ def main() -> int:
     builtin_headers_dir = os.path.abspath(args.clang_builtin_headers_dir)
     flag = "--clang-builtin-headers-dir"
     probe = os.path.join(builtin_headers_dir, "stddef.h")
-  if not os.path.isfile(probe):
-    print(
-        f"[metagen] {flag} does not hold clang's builtin headers:\n"
-        f"  {probe} not found",
-        file=sys.stderr)
-    return 1
   # -fsyntax-only, -ferror-limit=, -resource-dir= and -D carry `CLOption`
   # visibility in clang's Options.td, so one spelling works under both
   # drivers. -isystem does NOT: the clang-cl driver drops it with an

$NetBSD: patch-v8_tools_metagen_metagen.py,v 1.2 2026/10/16 15:31:04 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/tools/metagen/metagen.py.orig	2026-10-14 21:09:54.000000000 +0000
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

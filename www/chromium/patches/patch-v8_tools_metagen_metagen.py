$NetBSD: patch-v8_tools_metagen_metagen.py,v 1.4 2026/11/08 15:39:15 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- v8/tools/metagen/metagen.py.orig	2026-11-02 23:22:33.000000000 +0000
+++ v8/tools/metagen/metagen.py
@@ -300,12 +300,6 @@ def main() -> int:
   # LLVM revision and so always matches the parsing library.
   resource_dir = os.path.abspath(args.clang_resource_dir)
   stddef = os.path.join(resource_dir, "include", "stddef.h")
-  if not os.path.isfile(stddef):
-    print(
-        f"[metagen] --clang-resource-dir does not hold clang's builtin "
-        f"headers:\n  {stddef} not found",
-        file=sys.stderr)
-    return 1
 
   prefix = [
       "-fsyntax-only",

$NetBSD: patch-src_dateutil_zoneinfo_rebuild.py,v 1.1 2026/08/21 12:17:32 wiz Exp $

Support Internet RFC 8536 TZif files
https://github.com/dateutil/dateutil/pull/1091

--- src/dateutil/zoneinfo/rebuild.py.orig	2024-03-01 18:35:19.000000000 +0000
+++ src/dateutil/zoneinfo/rebuild.py
@@ -3,7 +3,7 @@ import json
 import tempfile
 import shutil
 import json
-from subprocess import check_call, check_output
+from subprocess import check_call
 from tarfile import TarFile
 
 from dateutil.zoneinfo import METADATA_FN, ZONEFILENAME
@@ -39,27 +39,14 @@ def _run_zic(zonedir, filepaths):
 
 
 def _run_zic(zonedir, filepaths):
-    """Calls the ``zic`` compiler in a compatible way to get a "fat" binary.
-
-    Recent versions of ``zic`` default to ``-b slim``, while older versions
-    don't even have the ``-b`` option (but default to "fat" binaries). The
-    current version of dateutil does not support Version 2+ TZif files, which
-    causes problems when used in conjunction with "slim" binaries, so this
-    function is used to ensure that we always get a "fat" binary.
+    """Calls the ``zic`` compiler.
     """
 
     try:
-        help_text = check_output(["zic", "--help"])
+        check_call(["zic", "-d", zonedir] + filepaths)
     except OSError as e:
         _print_on_nosuchfile(e)
         raise
-
-    if b"-b " in help_text:
-        bloat_args = ["-b", "fat"]
-    else:
-        bloat_args = []
-
-    check_call(["zic"] + bloat_args + ["-d", zonedir] + filepaths)
 
 
 def _print_on_nosuchfile(e):

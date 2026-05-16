$NetBSD: patch-tests_t__file__check.py,v 1.1 2026/05/16 03:47:29 riastradh Exp $

Missing file, content found from upstream git.

--- tests/t_file_check.py.orig	2025-09-06 17:50:47.497707732 +0000
+++ tests/t_file_check.py
@@ -0,0 +1,15 @@
+#!/usr/bin/env python3
+# Copyright (C) 2020 - mod_auth_gssapi contributors, see COPYING for license.
+
+import os
+
+import requests
+from requests.auth import HTTPBasicAuth
+
+
+if __name__ == '__main__':
+    url = 'http://%s/keytab_file_check/' % os.environ['NSS_WRAPPER_HOSTNAME']
+    r = requests.get(url, auth=HTTPBasicAuth(os.environ['MAG_USER_NAME'],
+                                             os.environ['MAG_USER_PASSWORD']))
+    if r.status_code != 200:
+        raise ValueError('Basic Auth Failed(Keytab File Check)')

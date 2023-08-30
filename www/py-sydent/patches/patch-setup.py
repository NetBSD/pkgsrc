$NetBSD: patch-setup.py,v 1.1 2023/08/30 12:42:05 manu Exp $

setup.py from earlier upstream release

--- setup.py.orig	2023-08-30 08:07:57.248878277 +0000
+++ setup.py	2017-04-25 15:29:32.000000000 +0000
@@ -0,0 +1,50 @@
+# -*- coding: utf-8 -*-
+
+# Copyright 2014 OpenMarket Ltd
+#
+# Licensed under the Apache License, Version 2.0 (the "License");
+# you may not use this file except in compliance with the License.
+# You may obtain a copy of the License at
+#
+#     http://www.apache.org/licenses/LICENSE-2.0
+#
+# Unless required by applicable law or agreed to in writing, software
+# distributed under the License is distributed on an "AS IS" BASIS,
+# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
+# See the License for the specific language governing permissions and
+# limitations under the License.
+
+import os
+from setuptools import setup, find_packages
+
+
+# Utility function to read the README file.
+# Used for the long_description.  It's nice, because now 1) we have a top level
+# README file and 2) it's easier to type in the README file than to put a raw
+# string in below ...
+def read(fname):
+    return open(os.path.join(os.path.dirname(__file__), fname)).read()
+
+setup(
+    name="SynapseIdentityServer",
+    version="0.1",
+    packages=find_packages(exclude=["tests"]),
+    description="Reference Synapse Identity Verification and Lookup Server",
+    install_requires=[
+        "signedjson==1.0.0",
+        "unpaddedbase64==1.1.0",
+        "Twisted>=14.0.0",
+        "service_identity>=1.0.0",
+        "pyasn1",
+        "pynacl",
+        "daemonize",
+        "phonenumbers",
+    ],
+    setup_requires=[
+        "setuptools_trial",
+        "setuptools>=1.0.0", # Needs setuptools that supports git+ssh. It's not obvious when support for this was introduced.
+        "mock"
+    ],
+    include_package_data=True,
+    long_description=read("README.rst"),
+)

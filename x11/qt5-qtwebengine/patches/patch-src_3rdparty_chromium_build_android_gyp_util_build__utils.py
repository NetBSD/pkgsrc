$NetBSD: patch-src_3rdparty_chromium_build_android_gyp_util_build__utils.py,v 1.2 2026/05/25 06:18:16 adam Exp $

Python 3.13 fix
https://sources.debian.org/data/main/q/qtwebengine-opensource-src/5.15.18+dfsg-2~bpo12+1/debian/patches/python3.13-pipes.patch

--- src/3rdparty/chromium/build/android/gyp/util/build_utils.py.orig	2025-04-22 13:00:44.000000000 +0000
+++ src/3rdparty/chromium/build/android/gyp/util/build_utils.py
@@ -13,6 +13,7 @@ import json
 import logging
 import os
 import re
+import shlex
 import shutil
 import stat
 import subprocess

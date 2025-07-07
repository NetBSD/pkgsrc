$NetBSD: patch-src_3rdparty_chromium_mojo_public_tools_mojom_mojom_parse_lexer.py,v 1.1 2025/07/07 13:50:44 wiz Exp $

Python 3.12 fix
https://sources.debian.org/data/main/q/qtwebengine-opensource-src/5.15.18+dfsg-2~bpo12+1/debian/patches/python3.12-imp.patch

--- src/3rdparty/chromium/mojo/public/tools/mojom/mojom/parse/lexer.py.orig	2024-04-03 09:31:09.000000000 +0000
+++ src/3rdparty/chromium/mojo/public/tools/mojom/mojom/parse/lexer.py
@@ -2,7 +2,6 @@
 # Use of this source code is governed by a BSD-style license that can be
 # found in the LICENSE file.
 
-import imp
 import os.path
 import sys
 

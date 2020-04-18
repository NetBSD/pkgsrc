$NetBSD: patch-cmd_minify_install.sh,v 1.1 2020/04/18 14:56:06 nikita Exp $

Upstreamed at https://github.com/tdewolff/minify/pull/298
Avoid usage of bash, this is no bash script.

--- cmd/minify/install.sh~
+++ cmd/minify/install.sh
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 
 if command -v git >/dev/null 2>&1 && git rev-parse --git-dir >/dev/null 2>&1; then
     go install -ldflags "-s -w -X 'main.Version=$(git describe --tags)'" -trimpath
@@ -6,4 +6,4 @@ else
     go install -ldflags "-s -w" -trimpath
 fi
 
-source minify_bash_tab_completion
+. minify_bash_tab_completion

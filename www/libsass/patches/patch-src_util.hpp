$NetBSD: patch-src_util.hpp,v 1.1 2019/07/09 20:31:33 nia Exp $

Include cmath for std::fmod, etc

--- src/util.hpp.orig	2019-06-15 15:05:08.000000000 +0000
+++ src/util.hpp
@@ -8,11 +8,11 @@
 #include "sass/base.h"
 #include "ast_fwd_decl.hpp"
 
+#include <cmath>
 #include <cstring>
 #include <vector>
 #include <string>
 #include <assert.h>
-#include <math.h>
 
 #define SASS_ASSERT(cond, msg) assert(cond && msg)
 

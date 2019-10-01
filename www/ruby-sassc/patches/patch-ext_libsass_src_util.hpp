$NetBSD: patch-ext_libsass_src_util.hpp,v 1.1 2019/10/01 15:34:50 ryoon Exp $

Include cmath for std::fmod, etc

--- ext/libsass/src/util.hpp.orig	2019-09-27 11:16:16.841429469 +0000
+++ ext/libsass/src/util.hpp
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
 

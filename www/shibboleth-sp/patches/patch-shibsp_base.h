--- shibsp/base.h.orig	2018-07-09 18:17:23.000000000 -0700
+++ shibsp/base.h	2020-07-07 12:13:39.779239618 -0700
@@ -32,6 +32,7 @@
 # define XMLTOOLING_LITE
 # include <xmltooling/base.h>
 #else
+# include <boost/lexical_cast.hpp>
 # include <saml/base.h>
 #endif
 

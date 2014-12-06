$NetBSD: patch-rest_oauth-proxy-call.c,v 1.1 2014/12/06 07:41:16 obache Exp $

oauth: Add missing include
This fixes a compilation warning about a missing prototype.

https://git.gnome.org/browse/librest/commit/?id=b50ace7738ea03817acdad87fb2b338a86018329

--- rest/oauth-proxy-call.c.orig	2014-09-03 08:29:14.000000000 +0000
+++ rest/oauth-proxy-call.c
@@ -25,6 +25,7 @@
 #include <rest/rest-proxy-call.h>
 #include "oauth-proxy-call.h"
 #include "oauth-proxy-private.h"
+#include "rest-proxy-call-private.h"
 #include "sha1.h"
 
 G_DEFINE_TYPE (OAuthProxyCall, oauth_proxy_call, REST_TYPE_PROXY_CALL)

$NetBSD: patch-src_wsauth.c,v 1.1 2026/10/19 07:36:19 tm Exp $

--- src/wsauth.c.orig	2026-10-16 11:33:37.615001854 +0000
+++ src/wsauth.c
@@ -141,7 +141,7 @@ generate_ws_auth_secret (void) {
 static char *
 create_jwt_payload (const char *sub, long iat, long exp) {
   char *payload = NULL;
-  char hostname[HOST_NAME_MAX + 1] = { 0 };
+  char hostname[_POSIX_HOST_NAME_MAX + 1] = { 0 };
 
   if (gethostname (hostname, sizeof (hostname)) != 0) {
     perror ("gethostname");
@@ -438,7 +438,7 @@ static int
 validate_jwt_claims (const char *payload_json, size_t payload_len, time_t *expires_at) {
   json_stream json;
   JWTClaims claims = { 0 };
-  char hostname[HOST_NAME_MAX + 1] = { 0 };
+  char hostname[_POSIX_HOST_NAME_MAX + 1] = { 0 };
   time_t now = 0;
   int parsed = 0, verify_only = 0;
 

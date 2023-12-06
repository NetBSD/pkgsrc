$NetBSD: patch-src_sock.c,v 1.1 2023/12/06 15:56:56 abs Exp $

Use getaddrinfo() on more than just __GLIBC__ systems

Submitted upstream as https://github.com/JoeDog/siege/pull/232

--- src/sock.c.orig	2023-01-05 15:52:49.000000000 +0000
+++ src/sock.c
@@ -94,7 +94,7 @@ new_socket(CONN *C, const char *hostpara
   char   hn[512];
   int    port;
   int    domain;
-#if defined(__GLIBC__)
+#if defined(HAVE_GETADDRINFO)
   char port_str[10];
   struct addrinfo hints;
   struct addrinfo *addr_res;
@@ -143,7 +143,7 @@ new_socket(CONN *C, const char *hostpara
     return -1;
   }
 
-#if defined(__GLIBC__)
+#if defined(HAVE_GETADDRINFO)
   {
     snprintf(port_str, sizeof(port_str), "%d", port);
 
@@ -188,7 +188,7 @@ new_socket(CONN *C, const char *hostpara
   herrno = h_errno;
 #endif/*OS SPECIFICS*/ 
 
-#if !defined(__GLIBC__)
+#if !defined(HAVE_GETADDRINFO)
   /* gethostbyname only offers IPv4 support */
   domain = AF_INET;
 
@@ -219,7 +219,7 @@ new_socket(CONN *C, const char *hostpara
 
   s_addr = (struct sockaddr *)&cli;
   addrlen = sizeof(struct sockaddr_in);
-#endif /* end of __GLIBC__ not defined */
+#endif /* end of HAVE_GETADDRINFO not defined */
 
   /* create a socket, return -1 on failure */
   if (__socket_create(C, domain) < 0) {
@@ -233,7 +233,7 @@ new_socket(CONN *C, const char *hostpara
    */ 
   conn = connect(C->sock, s_addr, addrlen);
   pthread_testcancel();
-#if defined(__GLIBC__)
+#if defined(HAVE_GETADDRINFO)
   /**
     * The result of getaddrinfo is a linked list. Attempt
     * to connect to each result until successful

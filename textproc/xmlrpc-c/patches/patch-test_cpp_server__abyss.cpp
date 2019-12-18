$NetBSD: patch-test_cpp_server__abyss.cpp,v 1.1 2019/12/18 12:43:40 joerg Exp $

The socket function, not the generic function call STL method.

--- test/cpp/server_abyss.cpp.orig	2019-12-17 01:07:01.776470052 +0000
+++ test/cpp/server_abyss.cpp
@@ -85,7 +85,7 @@ public:
         sockAddr.sin_port   = htons(portNumber);
         sockAddr.sin_addr.s_addr = 0;
 
-        rc = bind(this->fd, (struct sockaddr *)&sockAddr, sizeof(sockAddr));
+        rc = ::bind(this->fd, (struct sockaddr *)&sockAddr, sizeof(sockAddr));
         
         if (rc != 0) {
             closesock(this->fd);

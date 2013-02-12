commit f5b7bfb12ef74ddbf250e5076bbfaafd0027474c
Author: Michael Stapelberg <michael@stapelberg.de>
Date:   Wed Jan 9 18:11:03 2013 +0100

    Bugfix: fix IPC messages writes with low buffer sizes (Thanks jasper, dcoppa)
    
    Use the following command to reproduce this bug:
    
        echo 4096 | sudo tee /proc/sys/net/core/wmem_default
    
    Then just switch workspaces with some windows on it and i3bar would
    exit due to malformed IPC messages.
    
    This bug hits OpenBSD users (and possibly other BSDs) due to their lower
    default buffer size.
    
    fixes #896

diff --git a/libi3/ipc_send_message.c b/libi3/ipc_send_message.c
index 850fbdd..88d87a6 100644
--- libi3/ipc_send_message.c
+++ libi3/ipc_send_message.c
@@ -10,6 +10,7 @@
 #include <unistd.h>
 #include <stdint.h>
 #include <err.h>
+#include <errno.h>
 
 #include <i3/ipc.h>
 
@@ -38,14 +39,15 @@ int ipc_send_message(int sockfd, uint32_t message_size,
     memcpy(walk, payload, message_size);
 
     int sent_bytes = 0;
-    int bytes_to_go = buffer_size;
-    while (sent_bytes < bytes_to_go) {
-        int n = write(sockfd, msg + sent_bytes, bytes_to_go);
-        if (n == -1)
+    while (sent_bytes < buffer_size) {
+        int n = write(sockfd, msg + sent_bytes, buffer_size - sent_bytes);
+        if (n == -1) {
+            if (errno == EAGAIN)
+                continue;
             return -1;
+        }
 
         sent_bytes += n;
-        bytes_to_go -= n;
     }
 
     return 0;

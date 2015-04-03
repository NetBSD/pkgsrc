$NetBSD: patch-Xi_xichangehierarchy.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

X.Org Security Advisory:  Dec. 9, 2014
Protocol handling issues in X Window System servers

--- Xi/xichangehierarchy.c.orig	2012-05-17 17:09:01.000000000 +0000
+++ Xi/xichangehierarchy.c
@@ -407,7 +407,7 @@ int
 ProcXIChangeHierarchy(ClientPtr client)
 {
     xXIAnyHierarchyChangeInfo *any;
-    int required_len = sizeof(xXIChangeHierarchyReq);
+    size_t len;			/* length of data remaining in request */
     int rc = Success;
     int flags[MAXDEVICES] = { 0 };
 
@@ -417,21 +417,46 @@ ProcXIChangeHierarchy(ClientPtr client)
     if (!stuff->num_changes)
         return rc;
 
+    if (stuff->length > (INT_MAX >> 2))
+        return BadAlloc;
+    len = (stuff->length << 2) - sizeof(xXIAnyHierarchyChangeInfo);
+
     any = (xXIAnyHierarchyChangeInfo *) &stuff[1];
     while (stuff->num_changes--) {
+        if (len < sizeof(xXIAnyHierarchyChangeInfo)) {
+            rc = BadLength;
+            goto unwind;
+        }
+
         SWAPIF(swaps(&any->type));
         SWAPIF(swaps(&any->length));
 
-        required_len += any->length;
-        if ((stuff->length * 4) < required_len)
+        if ((any->length > (INT_MAX >> 2)) || (len < (any->length << 2)))
             return BadLength;
 
+#define CHANGE_SIZE_MATCH(type) \
+    do { \
+        if ((len < sizeof(type)) || (any->length != (sizeof(type) >> 2))) { \
+            rc = BadLength; \
+            goto unwind; \
+        } \
+    } while(0)
+
         switch (any->type) {
         case XIAddMaster:
         {
             xXIAddMasterInfo *c = (xXIAddMasterInfo *) any;
 
+            /* Variable length, due to appended name string */
+            if (len < sizeof(xXIAddMasterInfo)) {
+                rc = BadLength;
+                goto unwind;
+            }
             SWAPIF(swaps(&c->name_len));
+            if (c->name_len > (len - sizeof(xXIAddMasterInfo))) {
+                rc = BadLength;
+                goto unwind;
+            }
 
             rc = add_master(client, c, flags);
             if (rc != Success)
@@ -442,6 +467,7 @@ ProcXIChangeHierarchy(ClientPtr client)
         {
             xXIRemoveMasterInfo *r = (xXIRemoveMasterInfo *) any;
 
+            CHANGE_SIZE_MATCH(xXIRemoveMasterInfo);
             rc = remove_master(client, r, flags);
             if (rc != Success)
                 goto unwind;
@@ -451,6 +477,7 @@ ProcXIChangeHierarchy(ClientPtr client)
         {
             xXIDetachSlaveInfo *c = (xXIDetachSlaveInfo *) any;
 
+            CHANGE_SIZE_MATCH(xXIDetachSlaveInfo);
             rc = detach_slave(client, c, flags);
             if (rc != Success)
                 goto unwind;
@@ -460,6 +487,7 @@ ProcXIChangeHierarchy(ClientPtr client)
         {
             xXIAttachSlaveInfo *c = (xXIAttachSlaveInfo *) any;
 
+            CHANGE_SIZE_MATCH(xXIAttachSlaveInfo);
             rc = attach_slave(client, c, flags);
             if (rc != Success)
                 goto unwind;
@@ -467,6 +495,7 @@ ProcXIChangeHierarchy(ClientPtr client)
             break;
         }
 
+        len -= any->length * 4;
         any = (xXIAnyHierarchyChangeInfo *) ((char *) any + any->length * 4);
     }
 

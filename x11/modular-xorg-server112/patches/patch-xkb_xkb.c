$NetBSD: patch-xkb_xkb.c,v 1.1 2015/04/03 09:46:18 tnn Exp $

From cc830bd3a5b44796f1e8721f336dca4f565a8130 Mon Sep 17 00:00:00 2001
From: Olivier Fourdan <ofourdan@redhat.com>
Date: Fri, 16 Jan 2015 08:44:45 +0100
Subject: [PATCH] xkb: Check strings length against request size

Ensure that the given strings length in an XkbSetGeometry request remain
within the limits of the size of the request.

Signed-off-by: Olivier Fourdan <ofourdan@redhat.com>
---
 xkb/xkb.c | 65 +++++++++++++++++++++++++++++++++++++++------------------------
 1 file changed, 40 insertions(+), 25 deletions(-)

--- xkb/xkb.c.orig	2012-05-17 17:09:05.000000000 +0000
+++ xkb/xkb.c
@@ -4946,26 +4946,29 @@ ProcXkbGetGeometry(ClientPtr client)
 
 /***====================================================================***/
 
-static char *
-_GetCountedString(char **wire_inout, Bool swap)
+static Status
+_GetCountedString(char **wire_inout, ClientPtr client, char **str)
 {
-    char *wire, *str;
-    CARD16 len, *plen;
+    char *wire, *next;
+    CARD16 len;
 
     wire = *wire_inout;
-    plen = (CARD16 *) wire;
-    if (swap) {
-        swaps(plen);
-    }
-    len = *plen;
-    str = malloc(len + 1);
-    if (str) {
-        memcpy(str, &wire[2], len);
-        str[len] = '\0';
+    len = *(CARD16 *) wire;
+    if (client->swapped) {
+        swaps(&len);
     }
-    wire += XkbPaddedSize(len + 2);
-    *wire_inout = wire;
-    return str;
+    next = wire + XkbPaddedSize(len + 2);
+    /* Check we're still within the size of the request */
+    if (client->req_len <
+        bytes_to_int32(next - (char *) client->requestBuffer))
+        return BadValue;
+    *str = malloc(len + 1);
+    if (!*str)
+        return BadAlloc;
+    memcpy(*str, &wire[2], len);
+    *(*str + len) = '\0';
+    *wire_inout = next;
+    return Success;
 }
 
 static Status
@@ -4975,6 +4978,7 @@ _CheckSetDoodad(char **wire_inout,
     char *wire;
     xkbDoodadWireDesc *dWire;
     XkbDoodadPtr doodad;
+    Status status;
 
     dWire = (xkbDoodadWireDesc *) (*wire_inout);
     wire = (char *) &dWire[1];
@@ -5022,8 +5026,14 @@ _CheckSetDoodad(char **wire_inout,
         doodad->text.width = dWire->text.width;
         doodad->text.height = dWire->text.height;
         doodad->text.color_ndx = dWire->text.colorNdx;
-        doodad->text.text = _GetCountedString(&wire, client->swapped);
-        doodad->text.font = _GetCountedString(&wire, client->swapped);
+        status = _GetCountedString(&wire, client, &doodad->text.text);
+        if (status != Success)
+            return status;
+        status = _GetCountedString(&wire, client, &doodad->text.font);
+        if (status != Success) {
+            free (doodad->text.text);
+            return status;
+        }
         break;
     case XkbIndicatorDoodad:
         if (dWire->indicator.onColorNdx >= geom->num_colors) {
@@ -5058,7 +5068,9 @@ _CheckSetDoodad(char **wire_inout,
         }
         doodad->logo.color_ndx = dWire->logo.colorNdx;
         doodad->logo.shape_ndx = dWire->logo.shapeNdx;
-        doodad->logo.logo_name = _GetCountedString(&wire, client->swapped);
+        status = _GetCountedString(&wire, client, &doodad->logo.logo_name);
+        if (status != Success)
+            return status;
         break;
     default:
         client->errorValue = _XkbErrCode2(0x4F, dWire->any.type);
@@ -5290,18 +5302,20 @@ _CheckSetGeom(XkbGeometryPtr geom, xkbSe
     char *wire;
 
     wire = (char *) &req[1];
-    geom->label_font = _GetCountedString(&wire, client->swapped);
+    status = _GetCountedString(&wire, client, &geom->label_font);
+    if (status != Success)
+        return status;
 
     for (i = 0; i < req->nProperties; i++) {
         char *name, *val;
 
-        name = _GetCountedString(&wire, client->swapped);
-        if (!name)
-            return BadAlloc;
-        val = _GetCountedString(&wire, client->swapped);
-        if (!val) {
+        status = _GetCountedString(&wire, client, &name);
+        if (status != Success)
+            return status;
+        status = _GetCountedString(&wire, client, &val);
+        if (status != Success) {
             free(name);
-            return BadAlloc;
+            return status;
         }
         if (XkbAddGeomProperty(geom, name, val) == NULL) {
             free(name);
@@ -5335,9 +5349,9 @@ _CheckSetGeom(XkbGeometryPtr geom, xkbSe
     for (i = 0; i < req->nColors; i++) {
         char *name;
 
-        name = _GetCountedString(&wire, client->swapped);
-        if (!name)
-            return BadAlloc;
+        status = _GetCountedString(&wire, client, &name);
+        if (status != Success)
+            return status;
         if (!XkbAddGeomColor(geom, name, geom->num_colors)) {
             free(name);
             return BadAlloc;

$NetBSD: patch-media_mtransport_objs.mk,v 1.1 2013/11/03 04:51:59 ryoon Exp $

--- media/mtransport/objs.mk.orig	2013-05-11 19:19:43.000000000 +0000
+++ media/mtransport/objs.mk
@@ -23,12 +23,16 @@ LOCAL_INCLUDES += \
  -I$(topsrcdir)/media/mtransport/third_party/nrappkit/src/event \
  $(NULL)
 
-ifeq ($(OS_TARGET), Darwin)
+ifneq (,$(filter Darwin DragonFly FreeBSD NetBSD OpenBSD,$(OS_TARGET)))
 LOCAL_INCLUDES += \
   -I$(topsrcdir)/media/mtransport/third_party/nrappkit/src/port/darwin/include \
   -I$(topsrcdir)/media/mtransport/third_party/nrappkit/src/port/generic/include \
   $(NULL)
+ifeq ($(OS_TARGET), Darwin)
 DEFINES += -DDARWIN
+else
+DEFINES += -DBSD
+endif
 endif
 
 ifeq ($(OS_TARGET), Linux)

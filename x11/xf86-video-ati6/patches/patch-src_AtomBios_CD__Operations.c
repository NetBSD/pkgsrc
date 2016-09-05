$NetBSD: patch-src_AtomBios_CD__Operations.c,v 1.1 2016/09/05 12:08:53 richard Exp $

since some alignment functions were moved out of compiler.h,
simply copy them here.

--- src/AtomBios/CD_Operations.c.orig	2012-06-25 08:19:41.000000000 +0000
+++ src/AtomBios/CD_Operations.c
@@ -43,7 +43,7 @@ Revision History:
 #include <X11/Xos.h>
 #include "xorg-server.h"
 #include "compiler.h"
-
+#include <string.h>	/* needed for memmove */
 #include "Decoder.h"
 
 VOID PutDataRegister(PARSER_TEMP_DATA STACK_BASED * pParserTempData);
@@ -73,6 +73,39 @@ UINT32 GetParametersDirect(PARSER_TEMP_D
 UINT16* GetDataMasterTablePointer(DEVICE_DATA STACK_BASED*  pDeviceData);
 UINT8 GetTrueIndexInMasterTable(PARSER_TEMP_DATA STACK_BASED * pParserTempData, UINT8 IndexInMasterTable);
 
+static __inline__ uint32_t
+ldl_u(uint32_t * p)
+{
+    uint32_t ret;
+
+    memmove(&ret, p, sizeof(*p));
+    return ret;
+}
+
+static __inline__ uint16_t
+ldw_u(uint16_t * p)
+{
+    uint16_t ret;
+
+    memmove(&ret, p, sizeof(*p));
+    return ret;
+}
+
+static __inline__ void
+stl_u(uint32_t val, uint32_t * p)
+{
+    uint32_t tmp = val;
+
+    memmove(p, &tmp, sizeof(*p));
+}
+
+static __inline__ void
+stw_u(uint16_t val, uint16_t * p)
+{
+    uint16_t tmp = val;
+
+    memmove(p, &tmp, sizeof(*p));
+}
 
 WRITE_IO_FUNCTION WritePCIFunctions[8] =   {
     WritePCIReg32,

$NetBSD: patch-src_i830__quirks.c,v 1.1 2011/11/15 20:44:58 jakllsch Exp $

--- src/i830_quirks.c.orig	2009-05-13 00:12:11.000000000 +0000
+++ src/i830_quirks.c
@@ -32,8 +32,14 @@
 
 #define SUBSYS_ANY (~0)
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#define DMIID_SYSCTL_PREFIX "machdep.dmi."
+#else
 #define DMIID_DIR "/sys/class/dmi/id/"
 #define DMIID_FILE(x) (DMIID_DIR # x)
+#endif
 
 typedef struct {
     int chipType;
@@ -66,6 +72,62 @@ enum i830_dmi_data_t {
 
 static char *i830_dmi_data[dmi_data_max];
 
+#ifdef __NetBSD__
+/* NetBSD 6.0+ stores DMI data in sysctl machdep.dmi.* */
+static void
+i830_dmi_sysctl_load(enum i830_dmi_data_t field)
+{
+	const char *name;
+	char *buf;
+	size_t buflen = 0;
+	int err;
+
+	switch (field) {
+	case bios_vendor:	name = DMIID_SYSCTL_PREFIX "bios-vendor"; break;
+	case bios_version:	name = DMIID_SYSCTL_PREFIX "bios-version"; break;
+	case bios_date:		name = DMIID_SYSCTL_PREFIX "bios-date"; break;
+	case sys_vendor:	name = DMIID_SYSCTL_PREFIX "system-vendor"; break;
+	case product_name:	name = DMIID_SYSCTL_PREFIX "system-product"; break;
+	case product_version:	name = DMIID_SYSCTL_PREFIX "system-version"; break;
+	case product_serial:	name = DMIID_SYSCTL_PREFIX "system-serial"; break;
+	case product_uuid:	name = DMIID_SYSCTL_PREFIX "system-uuid"; break;
+	case board_vendor:	name = DMIID_SYSCTL_PREFIX "board-vendor"; break;
+	case board_name:	name = DMIID_SYSCTL_PREFIX "board-product"; break;
+	case board_version:	name = DMIID_SYSCTL_PREFIX "board-version"; break;
+	case board_serial:	name = DMIID_SYSCTL_PREFIX "board-serial"; break;
+	default:		goto not_found;
+	}
+
+	err = sysctlbyname(name, buf, &buflen, NULL, 0);
+	if (err || buflen == 0)
+		goto not_found;
+
+	buf = xcalloc(1, buflen);
+	if (buf == NULL)
+		goto not_found;
+
+	err = sysctlbyname(name, buf, &buflen, NULL, 0);
+	if (err)
+		goto not_found;
+
+	/* i830_dmi_scan uses a fixed-size buffer, use our own instead */
+	xfree(i830_dmi_data[field]);
+	i830_dmi_data[field] = buf;
+
+	return;
+
+not_found:
+	xfree(i830_dmi_data[field]);
+	i830_dmi_data[field] = NULL;
+}
+
+#define I830_DMI_FIELD_FUNC(field) \
+static void i830_dmi_store_##field(void) \
+{\
+    i830_dmi_sysctl_load(field);\
+}
+#else
+/* Linux stores DMI data in /sys/class/dmi/id/... */
 #define I830_DMI_FIELD_FUNC(field) \
 static void i830_dmi_store_##field(void) \
 {\
@@ -78,6 +140,7 @@ static void i830_dmi_store_##field(void)
     fread(i830_dmi_data[field], 64, 1, f);\
     fclose(f);\
 }
+#endif
 
 I830_DMI_FIELD_FUNC(bios_vendor);
 I830_DMI_FIELD_FUNC(bios_version);

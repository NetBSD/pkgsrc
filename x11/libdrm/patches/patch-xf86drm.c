$NetBSD: patch-xf86drm.c,v 1.4.4.1 2019/09/10 18:14:18 bsiegert Exp $

Implement drmParseSubsystemType, drmParsePciBusInfo for NetBSD

--- xf86drm.c.orig	2019-04-19 15:52:29.000000000 +0000
+++ xf86drm.c
@@ -86,7 +86,10 @@
 #endif
 
 #ifdef __NetBSD__
-#define DRM_MAJOR 34
+#define DRM_MAJOR 180
+#include <sys/param.h>
+#include <dev/pci/pcireg.h>
+#include <pci.h>
 #endif
 
 #ifdef __OpenBSD__
@@ -3032,6 +3035,65 @@ static int drmParseSubsystemType(int maj
     }
 
     return -EINVAL;
+#elif defined(__NetBSD__)
+    int type, fd;
+    drmSetVersion sv;
+    char *buf;
+    unsigned domain, bus, dev;
+    int func;
+    int ret;
+
+    /* Get the type of device we're looking for to pick the right pathname.  */
+    type = drmGetMinorType(min);
+    if (type == -1)
+	return -ENODEV;
+
+    /* Open the device.  Don't try to create it if it's not there.  */
+    fd = drmOpenMinor(min, 0, type);
+    if (fd < 0)
+	return -errno;
+
+    /*
+     * Set the interface version to 1.4 or 1.1, which has the effect of
+     * populating the bus id for us.
+     */
+    sv.drm_di_major = 1;
+    sv.drm_di_minor = 4;
+    sv.drm_dd_major = -1;
+    sv.drm_dd_minor = -1;
+    if (drmSetInterfaceVersion(fd, &sv)) {
+	sv.drm_di_major = 1;
+	sv.drm_di_minor = 1;
+	sv.drm_dd_major = -1;
+	sv.drm_dd_minor = -1;
+	if (drmSetInterfaceVersion(fd, &sv)) {
+	    /*
+	     * We're probably not the master.  Hope the master already
+	     * set the version to >=1.1 so that we can get the busid.
+	     */
+	}
+    }
+
+    /* Get the bus id.  */
+    buf = drmGetBusid(fd);
+
+    /* We're done with the device now.  */
+    (void)close(fd);
+
+    /* If there is no bus id, fail.  */
+    if (buf == NULL)
+	return -ENODEV;
+
+    /* Find a string we know about; otherwise -EINVAL.  */
+    ret = -EINVAL;
+    if (strncmp(buf, "pci:", 4) == 0)
+	ret = DRM_BUS_PCI;
+
+    /* We're done with the bus id.  */
+    free(buf);
+
+    /* Success or not, we're done.  */
+    return ret;
 #elif defined(__OpenBSD__) || defined(__DragonFly__)
     return DRM_BUS_PCI;
 #else
@@ -3081,6 +3143,73 @@ static int drmParsePciBusInfo(int maj, i
     info->func = func;
 
     return 0;
+#elif defined(__NetBSD__)
+    int type, fd;
+    drmSetVersion sv;
+    char *buf;
+    unsigned domain, bus, dev;
+    int func;
+    int ret;
+
+    /* Get the type of device we're looking for to pick the right pathname.  */
+    type = drmGetMinorType(min);
+    if (type == -1)
+	return -ENODEV;
+
+    /* Open the device.  Don't try to create it if it's not there.  */
+    fd = drmOpenMinor(min, 0, type);
+    if (fd < 0)
+	return -errno;
+
+    /*
+     * Set the interface version to 1.4 or 1.1, which has the effect of
+     * populating the bus id for us.
+     */
+    sv.drm_di_major = 1;
+    sv.drm_di_minor = 4;
+    sv.drm_dd_major = -1;
+    sv.drm_dd_minor = -1;
+    if (drmSetInterfaceVersion(fd, &sv)) {
+	sv.drm_di_major = 1;
+	sv.drm_di_minor = 1;
+	sv.drm_dd_major = -1;
+	sv.drm_dd_minor = -1;
+	if (drmSetInterfaceVersion(fd, &sv)) {
+            /*
+	     * We're probably not the master.  Hope the master already
+	     * set the version to >=1.1 so that we can get the busid.
+	     */
+	}
+    }
+
+    /* Get the bus id.  */
+    buf = drmGetBusid(fd);
+
+    /* We're done with the device now.  */
+    (void)close(fd);
+
+    /* If there is no bus id, fail.  */
+    if (buf == NULL)
+	return -ENODEV;
+
+    /* Parse the bus id.  */
+    ret = sscanf(buf, "pci:%04x:%02x:%02x.%d", &domain, &bus, &dev, &func);
+
+    /* We're done with the bus id.  */
+    free(buf);
+
+    /* If scanf didn't return 4 -- domain, bus, dev, func -- then fail.  */
+    if (ret != 4)
+	return -ENODEV;
+
+    /* Populate the results.  */
+    info->domain = domain;
+    info->bus = bus;
+    info->dev = dev;
+    info->func = func;
+
+    /* Success!  */
+    return 0;
 #elif defined(__OpenBSD__) || defined(__DragonFly__)
     struct drm_pciinfo pinfo;
     int fd, type;
@@ -3247,6 +3376,48 @@ static int drmParsePciDeviceInfo(int maj
         return parse_config_sysfs_file(maj, min, device);
 
     return 0;
+#elif defined(__NetBSD__)
+    drmPciBusInfo businfo;
+    char fname[PATH_MAX];
+    int pcifd;
+    pcireg_t id, class, subsys;
+    int ret;
+
+    /* Find where on the bus the device lives.  */
+    ret = drmParsePciBusInfo(maj, min, &businfo);
+    if (ret)
+	return ret;
+
+    /* Open the pciN device node to get at its config registers.  */
+    if (snprintf(fname, sizeof fname, "/dev/pci%u", businfo.domain)
+	>= sizeof fname)
+	return -ENODEV;
+    if ((pcifd = open(fname, O_RDONLY)) == -1)
+	return -errno;
+
+    ret = -1;
+    /* Read the id and class pci config registers.  */
+    if (pcibus_conf_read(pcifd, businfo.bus, businfo.dev, businfo.func,
+	    PCI_ID_REG, &id) == -1)
+	goto out;
+    if (pcibus_conf_read(pcifd, businfo.bus, businfo.dev, businfo.func,
+	    PCI_CLASS_REG, &class) == -1)
+	goto out;
+    if (pcibus_conf_read(pcifd, businfo.bus, businfo.dev, businfo.func,
+	    PCI_SUBSYS_ID_REG, &subsys) == -1)
+	goto out;
+
+    ret = 0;
+    device->vendor_id = PCI_VENDOR(id);
+    device->device_id = PCI_PRODUCT(id);
+    device->subvendor_id = PCI_SUBSYS_VENDOR(subsys);
+    device->subdevice_id = PCI_SUBSYS_ID(subsys);
+    device->revision_id = PCI_REVISION(class);
+out:
+    if (ret == -1)
+	ret = -errno;
+    close(pcifd);
+    return ret;
 #elif defined(__OpenBSD__) || defined(__DragonFly__)
     struct drm_pciinfo pinfo;
     int fd, type;

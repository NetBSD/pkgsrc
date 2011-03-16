$NetBSD: patch-gtkmozembed_gtkmozembedmodule.cpp,v 1.1 2011/03/16 06:51:13 obache Exp $

* Allow building with xulrunner 1.9
  https://bugzilla.gnome.org/show_bug.cgi?id=532856

--- gtkmozembed/gtkmozembedmodule.cpp.orig	2011-03-12 10:53:59.000000000 +0000
+++ gtkmozembed/gtkmozembedmodule.cpp
@@ -0,0 +1,72 @@
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+
+/* include this first, before NO_IMPORT_PYGOBJECT is defined */
+#include <pygobject.h>
+#include <pygtk/pygtk.h>
+
+#ifdef XPCOM_GLUE
+#include "gtkmozembed_glue.cpp"
+#endif
+
+G_BEGIN_DECLS
+void initgtkmozembed(void);
+void pygtkmozembed_add_constants(PyObject *module, const gchar *strip_prefix);
+void pygtkmozembed_register_classes (PyObject *d);
+G_END_DECLS
+
+extern PyMethodDef pygtkmozembed_functions[];
+
+void
+initgtkmozembed(void)
+{
+    PyObject *m, *d;
+    int argc = 0;
+
+    init_pygobject ();
+
+#ifdef XPCOM_GLUE
+    static const GREVersionRange greVersion = {
+    "1.9b", PR_TRUE,
+    "1.9.*", PR_TRUE
+    };
+    char xpcomLocation[4096];
+    nsresult rv = GRE_GetGREPathWithProperties(&greVersion, 1, nsnull, 0, xpcomLocation, 4096);
+    if (NS_FAILED(rv)) {
+	printf("GRE_GetGREPathWithProperties failed\n");
+	return;
+    }
+
+    // Startup the XPCOM Glue that links us up with XPCOM.
+    XPCOMGlueStartup(xpcomLocation);
+    if (NS_FAILED(rv)) {
+        printf("XPCOMGlueStartup failed\n");
+        return;
+    }
+
+    rv = GTKEmbedGlueStartup();
+    if (NS_FAILED(rv)) {printf("location: %s \n", xpcomLocation);
+        printf("GTKEmbedGlueStartup failed\n");
+        return;
+    }
+
+    //gtk_moz_embed_set_comp_path(xpcomLocation);
+
+    char *lastSlash = strrchr(xpcomLocation, '/');
+    if (lastSlash)
+      *lastSlash = '\0';
+
+    gtk_moz_embed_set_path(xpcomLocation);
+#endif
+
+    m = Py_InitModule ("gtkmozembed", pygtkmozembed_functions);
+    d = PyModule_GetDict (m);
+
+    pygtkmozembed_add_constants(m, "GTK_MOZ_EMBED_");
+    pygtkmozembed_register_classes (d);
+
+    if (PyErr_Occurred ()) {
+        Py_FatalError ("can't initialise module gtkmozembed");
+    }
+}

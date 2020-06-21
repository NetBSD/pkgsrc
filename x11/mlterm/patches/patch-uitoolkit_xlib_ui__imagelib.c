$NetBSD: patch-uitoolkit_xlib_ui__imagelib.c,v 1.1 2020/06/21 17:53:01 tsutsui Exp $

Pull upstrem fixes from mlterm-3.9.0-fixes.patch:
> This patch gets mlimgloader to exit correctly after loading a wall picture.

--- uitoolkit/xlib/ui_imagelib.c.orig	2020-04-26 12:54:53.000000000 +0000
+++ uitoolkit/xlib/ui_imagelib.c
@@ -1226,20 +1226,24 @@ static int modify_image(GdkPixbuf *pixbu
 
 #else /* NO_TOOLS */
 
-static pid_t exec_mlimgloader(int *read_fd, Window window,
-                              u_int width, u_int height, char *path, char *dst, char *opt) {
-  int fds[2];
+static pid_t exec_mlimgloader(int *read_fd,
+                              int *write_fd /* close(write_fd) makes mlimgloader exit */,
+                              Window window, u_int width, u_int height,
+                              char *path, char *dst, char *opt) {
+  int fds1[2];
+  int fds2[2];
   pid_t pid;
 
-  if (!path || !*path || pipe(fds) == -1) {
+  if (!path || !*path || pipe(fds1) == -1) {
     return -1;
   }
 
-  if ((pid = fork()) == -1) {
-    close(fds[0]);
-    close(fds[1]);
+  if (pipe(fds2) == -1) {
+    goto error1;
+  }
 
-    return -1;
+  if ((pid = fork()) == -1) {
+    goto error2;
   }
 
   if (pid == 0) {
@@ -1262,9 +1266,10 @@ static pid_t exec_mlimgloader(int *read_
     args[6] = opt;
     args[7] = NULL;
 
-    close(fds[0]);
+    close(fds1[1]);
+    close(fds2[0]);
 
-    if (dup2(fds[1], STDOUT_FILENO) != -1) {
+    if (dup2(fds1[0], STDIN_FILENO) != -1 && dup2(fds2[1], STDOUT_FILENO) != -1) {
       execv(args[0], args);
     }
 
@@ -1273,23 +1278,35 @@ static pid_t exec_mlimgloader(int *read_
     exit(1);
   }
 
-  close(fds[1]);
+  close(fds1[0]);
+  close(fds2[1]);
 
-  *read_fd = fds[0];
+  *write_fd = fds1[1];
+  *read_fd = fds2[0];
 
   return pid;
+
+error2:
+  close(fds2[0]);
+  close(fds2[1]);
+error1:
+  close(fds1[0]);
+  close(fds1[1]);
+
+  return -1;
 }
 
 static int load_file(ui_display_t *disp, char *path, u_int *width, u_int *height, int keep_aspect,
                      ui_picture_modifier_t *pic_mod, Pixmap *pixmap, Pixmap *mask /* Can be NULL */
                      ) {
   int read_fd;
+  int write_fd;
   char pix_str[DIGIT_STR_LEN(Pixmap) + 1 + DIGIT_STR_LEN(Pixmap) + 1];
   Pixmap pixmap_tmp;
   Pixmap mask_tmp;
   ssize_t size;
 
-  if (exec_mlimgloader(&read_fd, ui_display_get_group_leader(disp), *width, *height,
+  if (exec_mlimgloader(&read_fd, &write_fd, ui_display_get_group_leader(disp), *width, *height,
                        path, "pixmap", keep_aspect ? "-a" : NULL) == -1) {
     return 0;
   }
@@ -1338,22 +1355,29 @@ static int load_file(ui_display_t *disp,
 
   XSync(disp->display, False);
 
-  close(read_fd); /* child process exited by this. pixmap_tmp is alive until here. */
+  close(read_fd);
+  /*
+   * child process exited by this. pixmap_tmp is alive until here.
+   * (See read(STDIN_FILENO) in mlimgloader/gdk-pixbuf.c)
+   */
+  close(write_fd);
 
   return 1;
 
 error:
   close(read_fd);
+  close(write_fd);
 
   return 0;
 }
 
 static u_int32_t *create_cardinals_from_file(char *path, u_int32_t width, u_int32_t height) {
   int read_fd;
+  int write_fd;
   u_int32_t *cardinal;
   ssize_t size;
 
-  if (exec_mlimgloader(&read_fd, None, width, height, path, "stdout", NULL) == -1) {
+  if (exec_mlimgloader(&read_fd, &write_fd, None, width, height, path, "stdout", NULL) == -1) {
     return 0;
   }
 
@@ -1381,6 +1405,11 @@ static u_int32_t *create_cardinals_from_
   }
 
   close(read_fd);
+  /*
+   * child process exited by this. pixmap_tmp is alive until here.
+   * (See read(STDIN_FILENO) in mlimgloader/gdk-pixbuf.c)
+   */
+  close(write_fd);
 
 #ifdef DEBUG
   bl_debug_printf(BL_DEBUG_TAG " %s(w %d h %d) is loaded.\n", path, width, height);

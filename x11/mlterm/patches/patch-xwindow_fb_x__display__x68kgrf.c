$NetBSD: patch-xwindow_fb_x__display__x68kgrf.c,v 1.4 2014/03/14 17:42:17 tsutsui Exp $

Pull fixes for NetBSD/x68k framebuffer from upstream:
https://bitbucket.org/arakiken/mlterm/commits/f32b4ef020ab4ce25ab46166efac5c02f5e692eb
 - Allow non-privileged users to use mlterm-fb
 - The default resolution is changed to 768x512x4

https://bitbucket.org/arakiken/mlterm/commits/097ac4f2b78e1dea5a53a55fa070007655d85add#chg-xwindow/fb/x_display_x68kgrf.c
 - Also allow non-privileged users to use Text VRAM by --multivram=true option

--- xwindow/fb/x_display_x68kgrf.c.orig	2014-02-21 16:51:44.000000000 +0000
+++ xwindow/fb/x_display_x68kgrf.c
@@ -72,10 +72,10 @@ typedef struct  fb_reg_conf
 /* --- static variables --- */
 
 static int  console_id = -1 ;
-u_int  fb_width = 640 ;
-u_int  fb_height = 480 ;
-u_int  fb_depth = 8 ;
-int  separate_wall_picture ;
+u_int  fb_width = 768 ;
+u_int  fb_height = 512 ;
+u_int  fb_depth = 4 ;
+int  separate_wall_picture = 1 ;
 static fb_reg_conf_t  orig_reg ;
 static int  grf0_fd = -1 ;
 static size_t  grf0_len ;
@@ -185,8 +185,15 @@ open_display(
 	struct rgb_info  rgb_info_15bpp = { 3 , 3 , 3 , 6 , 11 , 1 } ;
 	struct termios  tm ;
 
-	if( ( _display.fb_fd = open( ( dev = getenv("FRAMEBUFFER")) ? dev : "/dev/grf1" ,
-					O_RDWR)) < 0)
+	kik_priv_restore_euid() ;
+	kik_priv_restore_egid() ;
+
+	_display.fb_fd = open( ( dev = getenv("FRAMEBUFFER")) ? dev : "/dev/grf1" , O_RDWR);
+
+	kik_priv_change_euid( kik_getuid()) ;
+	kik_priv_change_egid( kik_getgid()) ;
+
+	if( _display.fb_fd < 0)
 	{
 		kik_msg_printf( "Couldn't open %s.\n" , dev ? dev : "/dev/grf1") ;
 
@@ -663,7 +670,15 @@ x68k_tvram_set_wall_picture(
 	{
 		struct grfinfo  vinfo ;
 
-		if( image && ( grf0_fd = open( "/dev/grf0" , O_RDWR)) >= 0)
+		kik_priv_restore_euid() ;
+		kik_priv_restore_egid() ;
+
+		grf0_fd = open( "/dev/grf0" , O_RDWR) ;
+
+		kik_priv_change_euid( kik_getuid()) ;
+		kik_priv_change_egid( kik_getgid()) ;
+
+		if( grf0_fd >= 0)
 		{
 			kik_file_set_cloexec( grf0_fd) ;
 

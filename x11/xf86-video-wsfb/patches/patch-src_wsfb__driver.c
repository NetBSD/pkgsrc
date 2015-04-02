$NetBSD: patch-src_wsfb__driver.c,v 1.2 2015/04/02 22:16:49 tnn Exp $

Add revision 1.15 from xsrc version:
date: 2013-01-31 12:18:01 +0100; author: macallan; state: Exp; lines: +145 -72;
use WSDISPLAYIO_GET_FBINFO if available

Merge upstream commits for server 1.17 compatibility:
586b722fb17b3eb0ab776c170ee21e6a66fc7f22
fa9aabe95a65c4dd12008e16ad66d5c773a7993a
2993b33c466793c984b0c7cfeab06a3e333a29dd

--- src/wsfb_driver.c.orig	2012-01-01 15:25:08.000000000 +0000
+++ src/wsfb_driver.c
@@ -53,7 +53,6 @@
 #include "xf86_OSproc.h"
 
 #include "mipointer.h"
-#include "mibstore.h"
 #include "micmap.h"
 #include "colormapst.h"
 #include "xf86cmap.h"
@@ -78,6 +77,8 @@
 #include "xf86xv.h"
 #endif
 
+#include "compat-api.h"
+
 #ifdef X_PRIVSEP
 extern int priv_open_device(const char *);
 #else
@@ -110,15 +111,15 @@ static const OptionInfoRec * WsfbAvailab
 static void WsfbIdentify(int);
 static Bool WsfbProbe(DriverPtr, int);
 static Bool WsfbPreInit(ScrnInfoPtr, int);
-static Bool WsfbScreenInit(int, ScreenPtr, int, char **);
-static Bool WsfbCloseScreen(int, ScreenPtr);
+static Bool WsfbScreenInit(SCREEN_INIT_ARGS_DECL);
+static Bool WsfbCloseScreen(CLOSE_SCREEN_ARGS_DECL);
 static void *WsfbWindowLinear(ScreenPtr, CARD32, CARD32, int, CARD32 *,
 			      void *);
-static void WsfbPointerMoved(int, int, int);
-static Bool WsfbEnterVT(int, int);
-static void WsfbLeaveVT(int, int);
-static Bool WsfbSwitchMode(int, DisplayModePtr, int);
-static int WsfbValidMode(int, DisplayModePtr, Bool, int);
+static void WsfbPointerMoved(SCRN_ARG_TYPE, int, int);
+static Bool WsfbEnterVT(VT_FUNC_ARGS_DECL);
+static void WsfbLeaveVT(VT_FUNC_ARGS_DECL);
+static Bool WsfbSwitchMode(SWITCH_MODE_ARGS_DECL);
+static int WsfbValidMode(SCRN_ARG_TYPE, DisplayModePtr, Bool, int);
 static void WsfbLoadPalette(ScrnInfoPtr, int, int *, LOCO *, VisualPtr);
 static Bool WsfbSaveScreen(ScreenPtr, int);
 static void WsfbSave(ScrnInfoPtr);
@@ -231,7 +232,7 @@ WsfbSetup(pointer module, pointer opts, 
 /* Private data */
 typedef struct {
 	int			fd; /* File descriptor of open device. */
-	struct wsdisplay_fbinfo info; /* Frame buffer characteristics. */
+	struct wsdisplayio_fbinfo fbi; /* Frame buffer characteristics. */
 	int			linebytes; /* Number of bytes per row. */
 	unsigned char*		fbstart;
 	unsigned char*		fbmem;
@@ -241,7 +242,7 @@ typedef struct {
 	void *			shadow;
 	CloseScreenProcPtr	CloseScreen;
 	CreateScreenResourcesProcPtr CreateScreenResources;
-	void			(*PointerMoved)(int, int, int);
+	void			(*PointerMoved)(SCRN_ARG_TYPE, int, int);
 	EntityInfoPtr		pEnt;
 	struct wsdisplay_cmap	saved_cmap;
 
@@ -426,48 +427,96 @@ WsfbPreInit(ScrnInfoPtr pScrn, int flags
 		return FALSE;
 	}
 
-	if (ioctl(fPtr->fd, WSDISPLAYIO_GINFO, &fPtr->info) == -1) {
-		xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
-			   "ioctl WSDISPLAY_GINFO: %s\n",
-			   strerror(errno));
-		return FALSE;
-	}
-	if (ioctl(fPtr->fd, WSDISPLAYIO_GTYPE, &wstype) == -1) {
-		xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
-			   "ioctl WSDISPLAY_GTYPE: %s\n",
-			   strerror(errno));
-		return FALSE;
-	}
-	if (ioctl(fPtr->fd, WSDISPLAYIO_LINEBYTES, &fPtr->linebytes) == -1) {
-		xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
-			   "ioctl WSDISPLAYIO_LINEBYTES: %s\n",
-			   strerror(errno));
-		return FALSE;
+	if (ioctl(fPtr->fd, WSDISPLAYIO_GET_FBINFO, &fPtr->fbi) != 0) {
+		struct wsdisplay_fbinfo info;
+		struct wsdisplayio_fbinfo *fbi = &fPtr->fbi;
+		int lb;
+
+		xf86Msg(X_WARNING, "ioctl(WSDISPLAYIO_GET_FBINFO) failed, " \
+			"falling back to old method\n");
+		if (ioctl(fPtr->fd, WSDISPLAYIO_GINFO, &info) == -1) {
+			xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
+				   "ioctl WSDISPLAY_GINFO: %s\n",
+				   strerror(errno));
+			return FALSE;
+		}
+		if (ioctl(fPtr->fd, WSDISPLAYIO_GTYPE, &wstype) == -1) {
+			xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
+				   "ioctl WSDISPLAY_GTYPE: %s\n",
+				   strerror(errno));
+			return FALSE;
+		}
+		if (ioctl(fPtr->fd, WSDISPLAYIO_LINEBYTES, &lb) == -1) {
+			xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
+				   "ioctl WSDISPLAYIO_LINEBYTES: %s\n",
+				   strerror(errno));
+			return FALSE;
+		}
+		/* ok, fake up a new style fbinfo */
+		fbi->fbi_width = info.width;
+		fbi->fbi_height = info.height;
+		fbi->fbi_stride = lb;
+		fbi->fbi_bitsperpixel = info.depth;
+		if (info.depth > 16) {
+			fbi->fbi_pixeltype = WSFB_RGB;
+			if (wstype == WSDISPLAY_TYPE_SUN24 ||
+			    wstype == WSDISPLAY_TYPE_SUNCG12 ||
+			    wstype == WSDISPLAY_TYPE_SUNCG14 ||
+			    wstype == WSDISPLAY_TYPE_SUNTCX ||
+			    wstype == WSDISPLAY_TYPE_SUNFFB ||
+			    wstype == WSDISPLAY_TYPE_XVR1000 ||
+			    wstype == WSDISPLAY_TYPE_VC4) {
+				fbi->fbi_subtype.fbi_rgbmasks.red_offset = 0;
+				fbi->fbi_subtype.fbi_rgbmasks.red_size = 8;
+				fbi->fbi_subtype.fbi_rgbmasks.green_offset = 8;
+				fbi->fbi_subtype.fbi_rgbmasks.green_size = 8;
+				fbi->fbi_subtype.fbi_rgbmasks.blue_offset = 16;
+				fbi->fbi_subtype.fbi_rgbmasks.blue_size = 8;
+			} else {
+				fbi->fbi_subtype.fbi_rgbmasks.red_offset = 16;
+				fbi->fbi_subtype.fbi_rgbmasks.red_size = 8;
+				fbi->fbi_subtype.fbi_rgbmasks.green_offset = 8;
+				fbi->fbi_subtype.fbi_rgbmasks.green_size = 8;
+				fbi->fbi_subtype.fbi_rgbmasks.blue_offset = 0;
+				fbi->fbi_subtype.fbi_rgbmasks.blue_size = 8;
+			}
+			fbi->fbi_subtype.fbi_rgbmasks.alpha_offset = 0;
+			fbi->fbi_subtype.fbi_rgbmasks.alpha_size = 0;
+		} else if (info.depth <= 8) {
+			fbi->fbi_pixeltype = WSFB_CI;
+			fbi->fbi_subtype.fbi_cmapinfo.cmap_entries = info.cmsize;
+		}
+		fbi->fbi_flags = 0;
+		fbi->fbi_fbsize = info.width * lb;
+
 	}
 	/*
 	 * Allocate room for saving the colormap.
 	 */
-	if (fPtr->info.cmsize != 0) {
+	if (fPtr->fbi.fbi_pixeltype == WSFB_CI) {
 		fPtr->saved_cmap.red =
-		    (unsigned char *)malloc(fPtr->info.cmsize);
+		    (unsigned char *)malloc(fPtr->fbi.fbi_subtype.fbi_cmapinfo.cmap_entries);
 		if (fPtr->saved_cmap.red == NULL) {
 			xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
-			    "Cannot malloc %d bytes\n", fPtr->info.cmsize);
+			    "Cannot malloc %d bytes\n",
+			    fPtr->fbi.fbi_subtype.fbi_cmapinfo.cmap_entries);
 			return FALSE;
 		}
 		fPtr->saved_cmap.green =
-		    (unsigned char *)malloc(fPtr->info.cmsize);
+		    (unsigned char *)malloc(fPtr->fbi.fbi_subtype.fbi_cmapinfo.cmap_entries);
 		if (fPtr->saved_cmap.green == NULL) {
 			xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
-			    "Cannot malloc %d bytes\n", fPtr->info.cmsize);
+			    "Cannot malloc %d bytes\n",
+			    fPtr->fbi.fbi_subtype.fbi_cmapinfo.cmap_entries);
 			free(fPtr->saved_cmap.red);
 			return FALSE;
 		}
 		fPtr->saved_cmap.blue =
-		    (unsigned char *)malloc(fPtr->info.cmsize);
+		    (unsigned char *)malloc(fPtr->fbi.fbi_subtype.fbi_cmapinfo.cmap_entries);
 		if (fPtr->saved_cmap.blue == NULL) {
 			xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
-			    "Cannot malloc %d bytes\n", fPtr->info.cmsize);
+			    "Cannot malloc %d bytes\n",
+			    fPtr->fbi.fbi_subtype.fbi_cmapinfo.cmap_entries);
 			free(fPtr->saved_cmap.red);
 			free(fPtr->saved_cmap.green);
 			return FALSE;
@@ -475,18 +524,18 @@ WsfbPreInit(ScrnInfoPtr pScrn, int flags
 	}
 
 	/* Handle depth */
-	default_depth = fPtr->info.depth <= 24 ? fPtr->info.depth : 24;
+	default_depth = fPtr->fbi.fbi_bitsperpixel <= 24 ? fPtr->fbi.fbi_bitsperpixel : 24;
 	if (!xf86SetDepthBpp(pScrn, default_depth, default_depth,
-		fPtr->info.depth,
-		fPtr->info.depth >= 24 ? Support24bppFb|Support32bppFb : 0))
+		fPtr->fbi.fbi_bitsperpixel,
+		fPtr->fbi.fbi_bitsperpixel >= 24 ? Support24bppFb|Support32bppFb : 0))
 		return FALSE;
 
 	/* Check consistency. */
-	if (pScrn->bitsPerPixel != fPtr->info.depth) {
+	if (pScrn->bitsPerPixel != fPtr->fbi.fbi_bitsperpixel) {
 		xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
 		    "specified depth (%d) or bpp (%d) doesn't match "
 		    "framebuffer depth (%d)\n", pScrn->depth,
-		    pScrn->bitsPerPixel, fPtr->info.depth);
+		    fPtr->fbi.fbi_stride * 8, pScrn->bitsPerPixel);
 		return FALSE;
 	}
 	xf86PrintDepthBpp(pScrn);
@@ -496,17 +545,28 @@ WsfbPreInit(ScrnInfoPtr pScrn, int flags
 		pix24bpp = xf86GetBppFromDepth(pScrn, 24);
 
 	/* Color weight */
-	if (pScrn->depth > 8) {
+	if (fPtr->fbi.fbi_pixeltype == WSFB_RGB) {
 		rgb zeros = { 0, 0, 0 }, masks;
 
-		if (wstype == WSDISPLAY_TYPE_SUN24 ||
-		    wstype == WSDISPLAY_TYPE_SUNCG12 ||
-		    wstype == WSDISPLAY_TYPE_SUNCG14 ||
-		    wstype == WSDISPLAY_TYPE_SUNTCX ||
-		    wstype == WSDISPLAY_TYPE_SUNFFB) {
-			masks.red = 0x0000ff;
-			masks.green = 0x00ff00;
-			masks.blue = 0xff0000;
+		if (fPtr->fbi.fbi_subtype.fbi_rgbmasks.red_size > 0) {
+			uint32_t msk;
+
+			msk = 0xffffffff;
+			msk = msk << fPtr->fbi.fbi_subtype.fbi_rgbmasks.red_size;
+			msk = ~msk;
+			masks.red = msk << fPtr->fbi.fbi_subtype.fbi_rgbmasks.red_offset; 
+
+			msk = 0xffffffff;
+			msk = msk << fPtr->fbi.fbi_subtype.fbi_rgbmasks.green_size;
+			msk = ~msk;
+			masks.green = msk << fPtr->fbi.fbi_subtype.fbi_rgbmasks.green_offset; 
+
+			msk = 0xffffffff;
+			msk = msk << fPtr->fbi.fbi_subtype.fbi_rgbmasks.blue_size;
+			msk = ~msk;
+			masks.blue = msk << fPtr->fbi.fbi_subtype.fbi_rgbmasks.blue_offset; 
+			xf86Msg(X_INFO, "masks generated: %08x %08x %08x\n",
+			    masks.red, masks.green, masks.blue);
 		} else {
 			masks.red = 0;
 			masks.green = 0;
@@ -535,7 +595,7 @@ WsfbPreInit(ScrnInfoPtr pScrn, int flags
 	pScrn->progClock = TRUE;
 	pScrn->rgbBits   = 8;
 	pScrn->chipset   = "wsfb";
-	pScrn->videoRam  = fPtr->linebytes * fPtr->info.height;
+	pScrn->videoRam  = fPtr->fbi.fbi_fbsize;
 
 	xf86DrvMsg(pScrn->scrnIndex, X_INFO, "Vidmem: %dk\n",
 		   pScrn->videoRam/1024);
@@ -550,10 +610,12 @@ WsfbPreInit(ScrnInfoPtr pScrn, int flags
 			   fPtr->Options);
 
 	/* Use shadow framebuffer by default, on depth >= 8 */
-	if (pScrn->depth >= 8)
+	xf86Msg(X_INFO, "fbi_flags: %x\n", fPtr->fbi.fbi_flags);
+	if ((pScrn->depth >= 8) &&
+	   ((fPtr->fbi.fbi_flags & WSFB_VRAM_IS_RAM) == 0)) {
 		fPtr->shadowFB = xf86ReturnOptValBool(fPtr->Options,
 						      OPTION_SHADOW_FB, TRUE);
-	else
+	} else
 		if (xf86ReturnOptValBool(fPtr->Options,
 					 OPTION_SHADOW_FB, FALSE)) {
 			xf86DrvMsg(pScrn->scrnIndex, X_WARNING,
@@ -601,12 +663,12 @@ WsfbPreInit(ScrnInfoPtr pScrn, int flags
 	mode->status = MODE_OK;
 	mode->type = M_T_BUILTIN;
 	mode->Clock = 0;
-	mode->HDisplay = fPtr->info.width;
+	mode->HDisplay = fPtr->fbi.fbi_width;
 	mode->HSyncStart = 0;
 	mode->HSyncEnd = 0;
 	mode->HTotal = 0;
 	mode->HSkew = 0;
-	mode->VDisplay = fPtr->info.height;
+	mode->VDisplay = fPtr->fbi.fbi_height;
 	mode->VSyncStart = 0;
 	mode->VSyncEnd = 0;
 	mode->VTotal = 0;
@@ -617,8 +679,8 @@ WsfbPreInit(ScrnInfoPtr pScrn, int flags
 		   "Ignoring mode specification from screen section\n");
 	}
 	pScrn->currentMode = pScrn->modes = mode;
-	pScrn->virtualX = fPtr->info.width;
-	pScrn->virtualY = fPtr->info.height;
+	pScrn->virtualX = fPtr->fbi.fbi_width;
+	pScrn->virtualY = fPtr->fbi.fbi_height;
 	pScrn->displayWidth = pScrn->virtualX;
 
 	/* Set the display resolution. */
@@ -661,10 +723,22 @@ WsfbPreInit(ScrnInfoPtr pScrn, int flags
 	return TRUE;
 }
 
+static void
+wsfbUpdateRotatePacked(ScreenPtr pScreen, shadowBufPtr pBuf)
+{
+	shadowUpdateRotatePacked(pScreen, pBuf);
+}
+
+static void
+wsfbUpdatePacked(ScreenPtr pScreen, shadowBufPtr pBuf)
+{
+	shadowUpdatePacked(pScreen, pBuf);
+}
+
 static Bool
 WsfbCreateScreenResources(ScreenPtr pScreen)
 {
-	ScrnInfoPtr pScrn = xf86Screens[pScreen->myNum];
+	ScrnInfoPtr pScrn = xf86ScreenToScrn(pScreen);
 	WsfbPtr fPtr = WSFBPTR(pScrn);
 	PixmapPtr pPixmap;
 	Bool ret;
@@ -679,7 +753,7 @@ WsfbCreateScreenResources(ScreenPtr pScr
 	pPixmap = pScreen->GetScreenPixmap(pScreen);
 
 	if (!shadowAdd(pScreen, pPixmap, fPtr->rotate ?
-		shadowUpdateRotatePackedWeak() : shadowUpdatePackedWeak(),
+		wsfbUpdateRotatePacked : wsfbUpdatePacked,
 		WsfbWindowLinear, fPtr->rotate, NULL)) {
 		return FALSE;
 	}
@@ -702,7 +776,7 @@ WsfbShadowInit(ScreenPtr pScreen)
 }
 
 static Bool
-WsfbScreenInit(int scrnIndex, ScreenPtr pScreen, int argc, char **argv)
+WsfbScreenInit(SCREEN_INIT_ARGS_DECL)
 {
 	ScrnInfoPtr pScrn = xf86Screens[pScreen->myNum];
 	WsfbPtr fPtr = WSFBPTR(pScrn);
@@ -721,36 +795,39 @@ WsfbScreenInit(int scrnIndex, ScreenPtr 
 	       pScrn->mask.red,pScrn->mask.green,pScrn->mask.blue,
 	       pScrn->offset.red,pScrn->offset.green,pScrn->offset.blue);
 #endif
-	switch (fPtr->info.depth) {
+	switch (fPtr->fbi.fbi_bitsperpixel) {
 	case 1:
 	case 4:
 	case 8:
-		len = fPtr->linebytes*fPtr->info.height;
+		len = fPtr->fbi.fbi_stride * fPtr->fbi.fbi_height;
 		break;
 	case 16:
-		if (fPtr->linebytes == fPtr->info.width) {
-			len = fPtr->info.width*fPtr->info.height*sizeof(short);
+		if (fPtr->fbi.fbi_stride == fPtr->fbi.fbi_width) {
+			xf86Msg(X_ERROR, "Bogus stride == width in 16bit colour\n");
+			len = fPtr->fbi.fbi_width * fPtr->fbi.fbi_height * sizeof(short);
 		} else {
-			len = fPtr->linebytes*fPtr->info.height;
+			len = fPtr->fbi.fbi_stride * fPtr->fbi.fbi_height;
 		}
 		break;
 	case 24:
-		if (fPtr->linebytes == fPtr->info.width) {
-			len = fPtr->info.width*fPtr->info.height*3;
+		if (fPtr->fbi.fbi_stride == fPtr->fbi.fbi_width) {
+			xf86Msg(X_ERROR, "Bogus stride == width in 24bit colour\n");
+			len = fPtr->fbi.fbi_width * fPtr->fbi.fbi_height * 3;
 		} else {
-			len = fPtr->linebytes*fPtr->info.height;
+			len = fPtr->fbi.fbi_stride * fPtr->fbi.fbi_height;
 		}
 		break;
 	case 32:
-		if (fPtr->linebytes == fPtr->info.width) {
-			len = fPtr->info.width*fPtr->info.height*sizeof(int);
+		if (fPtr->fbi.fbi_stride == fPtr->fbi.fbi_width) {
+			xf86Msg(X_ERROR, "Bogus stride == width in 32bit colour\n");
+			len = fPtr->fbi.fbi_width * fPtr->fbi.fbi_height * sizeof(int);
 		} else {
-			len = fPtr->linebytes*fPtr->info.height;
+			len = fPtr->fbi.fbi_stride * fPtr->fbi.fbi_height;
 		}
 		break;
 	default:
 		xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
-			   "unsupported depth %d\n", fPtr->info.depth);
+			   "unsupported depth %d\n", fPtr->fbi.fbi_bitsperpixel);
 		return FALSE;
 	}
 	/* Switch to graphics mode - required before mmap. */
@@ -868,7 +945,7 @@ WsfbScreenInit(int scrnIndex, ScreenPtr 
 				   "RENDER extension initialisation failed.");
 	}
 	if (fPtr->shadowFB && !WsfbShadowInit(pScreen)) {
-		xf86DrvMsg(scrnIndex, X_ERROR,
+		xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
 		    "shadow framebuffer initialization failed\n");
 		return FALSE;
 	}
@@ -877,20 +954,19 @@ WsfbScreenInit(int scrnIndex, ScreenPtr 
 	if (!fPtr->rotate)
 		WsfbDGAInit(pScrn, pScreen);
 	else
-		xf86DrvMsg(scrnIndex, X_INFO, "Rotated display, "
+		xf86DrvMsg(pScrn->scrnIndex, X_INFO, "Rotated display, "
 		    "disabling DGA\n");
 #endif
 	if (fPtr->rotate) {
-		xf86DrvMsg(scrnIndex, X_INFO, "Enabling Driver Rotation, "
+		xf86DrvMsg(pScrn->scrnIndex, X_INFO, "Enabling Driver Rotation, "
 		    "disabling RandR\n");
 		xf86DisableRandR();
 		if (pScrn->bitsPerPixel == 24)
-			xf86DrvMsg(scrnIndex, X_WARNING,
+			xf86DrvMsg(pScrn->scrnIndex, X_WARNING,
 			    "Rotation might be broken in 24 bpp\n");
 	}
 
 	xf86SetBlackWhitePixels(pScreen);
-	miInitializeBackingStore(pScreen);
 	xf86SetBackingStore(pScreen);
 
 	/* Software cursor. */
@@ -907,10 +983,16 @@ WsfbScreenInit(int scrnIndex, ScreenPtr 
 	if (!miCreateDefColormap(pScreen))
 		return FALSE;
 	flags = CMAP_RELOAD_ON_MODE_SWITCH;
-	ncolors = fPtr->info.cmsize;
+
+	ncolors = 0;
+	if (fPtr->fbi.fbi_pixeltype == WSFB_CI) {
+		ncolors = fPtr->fbi.fbi_subtype.fbi_cmapinfo.cmap_entries;
+	}
+
 	/* On StaticGray visuals, fake a 256 entries colormap. */
 	if (ncolors == 0)
 		ncolors = 256;
+
 	if(!xf86HandleColormaps(pScreen, ncolors, 8, WsfbLoadPalette,
 				NULL, flags))
 		return FALSE;
@@ -937,9 +1019,9 @@ WsfbScreenInit(int scrnIndex, ScreenPtr 
 }
 
 static Bool
-WsfbCloseScreen(int scrnIndex, ScreenPtr pScreen)
+WsfbCloseScreen(CLOSE_SCREEN_ARGS_DECL)
 {
-	ScrnInfoPtr pScrn = xf86Screens[scrnIndex];
+	ScrnInfoPtr pScrn = xf86ScreenToScrn(pScreen);
 	PixmapPtr pPixmap;
 	WsfbPtr fPtr = WSFBPTR(pScrn);
 
@@ -971,30 +1053,34 @@ WsfbCloseScreen(int scrnIndex, ScreenPtr
 	/* Unwrap CloseScreen. */
 	pScreen->CloseScreen = fPtr->CloseScreen;
 	TRACE_EXIT("WsfbCloseScreen");
-	return (*pScreen->CloseScreen)(scrnIndex, pScreen);
+	return (*pScreen->CloseScreen)(CLOSE_SCREEN_ARGS);
 }
 
 static void *
 WsfbWindowLinear(ScreenPtr pScreen, CARD32 row, CARD32 offset, int mode,
 		CARD32 *size, void *closure)
 {
-	ScrnInfoPtr pScrn = xf86Screens[pScreen->myNum];
+	ScrnInfoPtr pScrn = xf86ScreenToScrn(pScreen);
 	WsfbPtr fPtr = WSFBPTR(pScrn);
 
-	if (fPtr->linebytes)
-		*size = fPtr->linebytes;
+	/*
+	 * XXX
+	 * This should never happen. Is it really necessary?
+	 */
+	if (fPtr->fbi.fbi_stride)
+		*size = fPtr->fbi.fbi_stride;
 	else {
 		if (ioctl(fPtr->fd, WSDISPLAYIO_LINEBYTES, size) == -1)
 			return NULL;
-		fPtr->linebytes = *size;
+		fPtr->fbi.fbi_stride = *size;
 	}
-	return ((CARD8 *)fPtr->fbmem + row *fPtr->linebytes + offset);
+	return ((CARD8 *)fPtr->fbmem + row * fPtr->fbi.fbi_stride + offset);
 }
 
 static void
-WsfbPointerMoved(int index, int x, int y)
+WsfbPointerMoved(SCRN_ARG_TYPE arg, int x, int y)
 {
-    ScrnInfoPtr pScrn = xf86Screens[index];
+    SCRN_INFO_PTR(arg);
     WsfbPtr fPtr = WSFBPTR(pScrn);
     int newX, newY;
 
@@ -1026,13 +1112,13 @@ WsfbPointerMoved(int index, int x, int y
     }
 
     /* Pass adjusted pointer coordinates to wrapped PointerMoved function. */
-    (*fPtr->PointerMoved)(index, newX, newY);
+    (*fPtr->PointerMoved)(arg, newX, newY);
 }
 
 static Bool
-WsfbEnterVT(int scrnIndex, int flags)
+WsfbEnterVT(VT_FUNC_ARGS_DECL)
 {
-	ScrnInfoPtr pScrn = xf86Screens[scrnIndex];
+	SCRN_INFO_PTR(arg);
 
 	TRACE_ENTER("EnterVT");
 	pScrn->vtSema = TRUE;
@@ -1041,20 +1127,20 @@ WsfbEnterVT(int scrnIndex, int flags)
 }
 
 static void
-WsfbLeaveVT(int scrnIndex, int flags)
+WsfbLeaveVT(VT_FUNC_ARGS_DECL)
 {
 #if DEBUG
-	ScrnInfoPtr pScrn = xf86Screens[scrnIndex];
+	SCRN_INFO_PTR(arg);
 #endif
 
 	TRACE_ENTER("LeaveVT");
 }
 
 static Bool
-WsfbSwitchMode(int scrnIndex, DisplayModePtr mode, int flags)
+WsfbSwitchMode(SWITCH_MODE_ARGS_DECL)
 {
 #if DEBUG
-	ScrnInfoPtr pScrn = xf86Screens[scrnIndex];
+	SCRN_INFO_PTR(arg);
 #endif
 
 	TRACE_ENTER("SwitchMode");
@@ -1063,10 +1149,10 @@ WsfbSwitchMode(int scrnIndex, DisplayMod
 }
 
 static int
-WsfbValidMode(int scrnIndex, DisplayModePtr mode, Bool verbose, int flags)
+WsfbValidMode(SCRN_ARG_TYPE arg, DisplayModePtr mode, Bool verbose, int flags)
 {
 #if DEBUG
-	ScrnInfoPtr pScrn = xf86Screens[scrnIndex];
+	SCRN_INFO_PTR(arg);
 #endif
 
 	TRACE_ENTER("ValidMode");
@@ -1132,7 +1218,7 @@ WsfbLoadPalette(ScrnInfoPtr pScrn, int n
 static Bool
 WsfbSaveScreen(ScreenPtr pScreen, int mode)
 {
-	ScrnInfoPtr pScrn = xf86Screens[pScreen->myNum];
+	ScrnInfoPtr pScrn = xf86ScreenToScrn(pScreen);
 	WsfbPtr fPtr = WSFBPTR(pScrn);
 	int state;
 
@@ -1159,11 +1245,12 @@ WsfbSave(ScrnInfoPtr pScrn)
 
 	TRACE_ENTER("WsfbSave");
 
-	if (fPtr->info.cmsize == 0)
+	/* nothing to save if we don't run in colour-indexed mode */
+	if (fPtr->fbi.fbi_pixeltype != WSFB_CI)
 		return;
 
 	fPtr->saved_cmap.index = 0;
-	fPtr->saved_cmap.count = fPtr->info.cmsize;
+	fPtr->saved_cmap.count = fPtr->fbi.fbi_subtype.fbi_cmapinfo.cmap_entries;
 	if (ioctl(fPtr->fd, WSDISPLAYIO_GETCMAP,
 		  &(fPtr->saved_cmap)) == -1) {
 		xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
@@ -1181,7 +1268,7 @@ WsfbRestore(ScrnInfoPtr pScrn)
 
 	TRACE_ENTER("WsfbRestore");
 
-	if (fPtr->info.cmsize != 0) {
+	if (fPtr->fbi.fbi_pixeltype == WSFB_CI) {
 		/* reset colormap for text mode */
 		if (ioctl(fPtr->fd, WSDISPLAYIO_PUTCMAP,
 			  &(fPtr->saved_cmap)) == -1) {
@@ -1240,9 +1327,9 @@ WsfbDGASetMode(ScrnInfoPtr pScrn, DGAMod
 		frameY0 = pScrn->frameY0;
 	}
 
-	if (!(*pScrn->SwitchMode)(scrnIdx, pMode, 0))
+	if (!(*pScrn->SwitchMode)(SWITCH_MODE_ARGS(pScrn, pMode)))
 		return FALSE;
-	(*pScrn->AdjustFrame)(scrnIdx, frameX0, frameY0, 0);
+	(*pScrn->AdjustFrame)(ADJUST_FRAME_ARGS(pScrn, frameX0, frameY0));
 
 	return TRUE;
 }
@@ -1250,7 +1337,7 @@ WsfbDGASetMode(ScrnInfoPtr pScrn, DGAMod
 static void
 WsfbDGASetViewport(ScrnInfoPtr pScrn, int x, int y, int flags)
 {
-	(*pScrn->AdjustFrame)(pScrn->pScreen->myNum, x, y, flags);
+	(*pScrn->AdjustFrame)(ADJUST_FRAME_ARGS(pScrn, x, y));
 }
 
 static int
@@ -1305,12 +1392,12 @@ WsfbDGAAddModes(ScrnInfoPtr pScrn)
 		pDGAMode->viewportWidth = pMode->HDisplay;
 		pDGAMode->viewportHeight = pMode->VDisplay;
 
-		if (fPtr->linebytes)
-			pDGAMode->bytesPerScanline = fPtr->linebytes;
+		if (fPtr->fbi.fbi_stride)
+			pDGAMode->bytesPerScanline = fPtr->fbi.fbi_stride;
 		else {
 			ioctl(fPtr->fd, WSDISPLAYIO_LINEBYTES,
-			      &fPtr->linebytes);
-			pDGAMode->bytesPerScanline = fPtr->linebytes;
+			      &fPtr->fbi.fbi_stride);
+			pDGAMode->bytesPerScanline = fPtr->fbi.fbi_stride;
 		}
 
 		pDGAMode->imageWidth = pMode->HDisplay;

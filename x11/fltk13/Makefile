# $NetBSD: Makefile,v 1.17 2014/05/05 00:48:28 ryoon Exp $

DISTNAME=	fltk-1.3.2-source
PKGNAME=	${DISTNAME:S/-source//}
VERS=		${DISTNAME:S/fltk-//:S/-source//}
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://fltk.org/pub/fltk/${VERS}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fltk.org/
COMMENT=	Fast Light Tool Kit for graphical user interfaces
LICENSE=	gnu-lgpl-v2

CONFLICTS=		fltk-1.[012].*

DIST_SUBDIR=	fltk13

#TigerVNC requires FLTK 1.3.0 (or later). Although it will build and work
#with plain 1.3.0, to get full functionality and the best behaviour the
#following patches are needed

# Export dead key information from FLTK to the apps
# http://www.fltk.org/str.php?L2599
PATCHFILES=		fltk-1_v4.3.x-keyboard-x11.patch	\
				fltk-1_v4.3.x-keyboard-win32.patch	\
				fltk-1_v6.3.x-keyboard-osx.patch
PATCH_SITES=	http://www.fltk.org/strfiles/2599/

# Notify applications of changes to the clipboard
# http://www.fltk.org/str.php?L2636
PATCHFILES+=	fltk-1.3.x-clipboard.patch	\
				fltk-1_v5.3.x-clipboard-x11.patch	\
				fltk-1_v3.3.x-clipboard-win32-fix.patch	\
				fltk-1_v2.3.x-clipboard-win32.patch	\
				fltk-1_v2.3.x-clipboard-osx.patch
PATCH_SITES+=	http://www.fltk.org/strfiles/2636/

# Ability to convert a Fl_Pixmap to a Fl_RGB_Image
# http://www.fltk.org/str.php?L2659
PATCHFILES+=	pixmap_v2.patch
PATCH_SITES+=	http://www.fltk.org/strfiles/2659/

# Support for custom cursors
# http://www.fltk.org/str.php?L2660
PATCHFILES+=	fltk-1_v5.3.x-cursor.patch
PATCH_SITES+=	http://www.fltk.org/strfiles/2660/

# Improve modality interaction with WM
# http://www.fltk.org/str.php?L2802
PATCHFILES+=	fltk-1_v2.3.0-modal.patch
PATCH_SITES+=	http://www.fltk.org/strfiles/2802/

# Window icons
# http://www.fltk.org/str.php?L2816
PATCHFILES+=	fltk-1_v3.3.0-icons.patch
PATCH_SITES+=	http://www.fltk.org/strfiles/2816/

# Multihead
# http://fltk.org/str.php?L2860
PATCHFILES+=	fltk-1.3.x-screen_num.patch	\
				fltk-1_v3.3.x-multihead.patch
PATCH_SITES+=	http://www.fltk.org/strfiles/2860/

PATCH_DIST_STRIP= -p1

WRKSRC=			${WRKDIR}/${DISTNAME:S/-source//}
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
TEST_TARGET=		test

PKG_OPTIONS_VAR=	PKG_OPTIONS.fltk13
PKG_SUPPORTED_OPTIONS=	opengl # cairo
PKG_SUGGESTED_OPTIONS=	opengl # cairo
#PLIST_VARS+=	cairo
PLIST_VARS+=	opengl

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

PTHREAD_OPTS+=		require
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-libtool=${LIBTOOL:Q}
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	ac_cv_have_overlay=yes

PLIST_VARS+=		cs	# case-sensitive
.if !exists(./descr) && ${OPSYS} != "Darwin"
CONFIGURE_ARGS+=	--with-links
PLIST.cs=		yes
.endif

BUILDLINK_DEPMETHOD.libXt?=	build

#.if !empty(PKG_OPTIONS:Mcairo)
#.  include "../../graphics/cairo/buildlink3.mk"
#CONFIGURE_ARGS+=	--enable-cairo
#PLIST.cairo=	yes
#.else
#CONFIGURE_ARGS+=	--disable-cairo
#.endif

.if !empty(PKG_OPTIONS:Mopengl)
.  include "../../graphics/Mesa/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-gl
PLIST.opengl=	yes
.else
CONFIGURE_ARGS+=	--disable-gl
.endif

CONFIGURE_ARGS+=	--enable-shared
# Use pkgsrc versions, not package's bundled versions.
CONFIGURE_ARGS+=	--disable-localjpeg --disable-localzlib --disable-localpng

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

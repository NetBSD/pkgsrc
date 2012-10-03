# $NetBSD: Makefile,v 1.3.2.1 2012/10/03 12:09:47 spz Exp $

DISTNAME=	fltk-1.3.0-source
PKGNAME=	${DISTNAME:S/-source//}
VERS=		${DISTNAME:S/fltk-//:S/-source//}
PKGREVISION=	7
CATEGORIES=	x11
MASTER_SITES=	http://ftp.easysw.com/pub/fltk/${VERS}/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/fltk/${VERS}/ \
		ftp://ftp.rz.tu-bs.de/pub/mirror/ftp.easysw.com/ftp/pub/fltk/${VERS}/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fltk.org/
COMMENT=	Fast Light Tool Kit for graphical user interfaces
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
CONFLICTS=		fltk-1.[012].*

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
.if !exists(./descr)
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
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

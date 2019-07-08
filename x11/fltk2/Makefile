# $NetBSD: Makefile,v 1.23 2019/07/08 10:36:25 nia Exp $

VERS=		6129
PKGREVISION=	14
DISTNAME=	fltk-2.0.x-r${VERS}
PKGNAME=	fltk2-2.0pre${VERS}
CATEGORIES=	x11
MASTER_SITES=	http://ftp.easysw.com/pub/fltk/snapshots/
MASTER_SITES+=	ftp://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/fltk/snapshots/
MASTER_SITES+=	ftp://ftp.rz.tu-bs.de/pub/mirror/ftp.easysw.com/ftp/pub/fltk/snapshots/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.fltk.org/
COMMENT=	Fast Light Tool Kit for graphical user interfaces

USE_LANGUAGES=		c c++03
USE_TOOLS+=		gmake
TEST_TARGET=		test

PTHREAD_OPTS+=		require
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	ac_cv_have_overlay=yes
LDFLAGS+=		-lfontconfig -lXrender -lfreetype

.include "options.mk"

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.4 2003/02/17 15:28:03 dillo Exp $
#

DISTNAME=	tix8.2.0b1
PKGNAME=	tk-Tix-8.2.0b1
WRKSRC=		${WRKDIR}/tix8.2.0/unix
CATEGORIES=	x11 tcl tk
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tixlibrary/}

MAINTAINER=	he@netbsd.org
HOMEPAGE=	http://tixlibrary.sourceforge.net/
COMMENT=	Powerful widget library for Tcl/Tk

USE_BUILDLINK2=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared --with-tcl=${BUILDLINK_PREFIX.tcl}/lib \
			--with-tk=${BUILDLINK_PREFIX.tk}/lib \
			--disable-stubs
MAKE_ENV+=		TCL_DIR=${BUILDLINK_PREFIX.tcl}
MAKE_ENV+=		TK_DIR=${BUILDLINK_PREFIX.tk}
TEST_TARGET=		test

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.6 2004/01/20 12:28:27 agc Exp $
#

DISTNAME=	tix8.2.0b1
PKGNAME=	tk-Tix-8.2.0b1
CATEGORIES=	x11 tcl tk
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tixlibrary/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://tixlibrary.sourceforge.net/
COMMENT=	Powerful widget library for Tcl/Tk

WRKSRC=			${WRKDIR}/tix8.2.0/unix
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

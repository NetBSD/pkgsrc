# $NetBSD: Makefile,v 1.9 2004/10/03 00:18:38 tv Exp $
#

DISTNAME=	tix8.2.0b1
PKGNAME=	tk-Tix-8.2.0b1
PKGREVISION=	2
CATEGORIES=	x11 tcl tk
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tixlibrary/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://tixlibrary.sourceforge.net/
COMMENT=	Powerful widget library for Tcl/Tk

WRKSRC=			${WRKDIR}/tix8.2.0/unix
USE_BUILDLINK3=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared --with-tcl=${BUILDLINK_PREFIX.tcl}/lib \
			--with-tk=${BUILDLINK_PREFIX.tk}/lib \
			--disable-stubs
MAKE_ENV+=		TCL_DIR=${BUILDLINK_PREFIX.tcl}
MAKE_ENV+=		TK_DIR=${BUILDLINK_PREFIX.tk}
TEST_TARGET=		test

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

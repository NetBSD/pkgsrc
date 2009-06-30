# $NetBSD: Makefile,v 1.14 2009/06/30 00:07:25 joerg Exp $
#

DISTNAME=	tix8.2.0b1
PKGNAME=	tk-Tix-8.2.0b1
PKGREVISION=	3
CATEGORIES=	x11 tcl tk
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tixlibrary/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://tixlibrary.sourceforge.net/
COMMENT=	Powerful widget library for Tcl/Tk

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/tix8.2.0/unix
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared --with-tcl=${BUILDLINK_PREFIX.tcl}/lib \
			--with-tk=${BUILDLINK_PREFIX.tk}/lib \
			--disable-stubs
MAKE_ENV+=		TCL_DIR=${BUILDLINK_PREFIX.tcl}
MAKE_ENV+=		TK_DIR=${BUILDLINK_PREFIX.tk}
TEST_TARGET=		test

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.3 2002/08/25 21:52:46 jlam Exp $
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

test:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} test

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

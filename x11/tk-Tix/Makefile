# $NetBSD: Makefile,v 1.1.1.1 2002/04/15 08:19:02 he Exp $
#

DISTNAME=	tix8.2.0b1
PKGNAME=	tk-Tix-8.2.0b1
CATEGORIES=	x11 tcl tk
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tixlibrary/}

MAINTAINER=	he@netbsd.org
HOMEPAGE=	http://tixlibrary.sourceforge.net/
COMMENT=	Powerful widget library for Tcl/Tk

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared --with-tcl=${BUILDLINK_DIR}/lib \
			--with-tk=${BUILDLINK_DIR}/lib \
			--disable-stubs
USE_BUILDLINK_ONLY=	YES

WRKSRC=			${WRKDIR}/tix8.2.0/unix

test:
	@(cd ${WRKSRC}; ${MAKE_ENV} ${MAKE} test)

.include "../../mk/x11.buildlink.mk"
.include "../../x11/tk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"

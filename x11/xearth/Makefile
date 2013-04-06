# $NetBSD: Makefile,v 1.22 2013/04/06 14:09:35 rodent Exp $
#

DISTNAME=	xearth-1.1
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	# AWOL
COMMENT=	Rotating map of the Earth in X11 root window

USE_IMAKE=	yes
INSTALL_MAKE_FLAGS=	MANPATH=${PREFIX}/${PKGMANDIR}

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

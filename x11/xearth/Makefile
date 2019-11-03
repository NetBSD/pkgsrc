# $NetBSD: Makefile,v 1.23 2019/11/03 09:14:19 rillig Exp $
#

DISTNAME=	xearth-1.1
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	# AWOL
COMMENT=	Rotating map of the Earth in X11 root window

USE_IMAKE=		yes
INSTALL_MAKE_FLAGS=	MANPATH=${PREFIX}/${PKGMANDIR}

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

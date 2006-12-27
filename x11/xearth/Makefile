# $NetBSD: Makefile,v 1.18 2006/12/27 13:37:44 joerg Exp $
#

DISTNAME=	xearth-1.1
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	ftp://cag.lcs.mit.edu/pub/tuna/ \
		http://ftp.x.org/contrib/applications/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	# AWOL
COMMENT=	Rotating map of the Earth in X11 root window

USE_IMAKE=	yes
INSTALL_MAKE_FLAGS=	MANPATH=${PREFIX}/${PKGMANDIR}

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.21 2012/10/29 05:07:02 asau Exp $
#

DISTNAME=	xearth-1.1
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	http://ftp.x.org/contrib/applications/ \
	ftp://ftp.sunet.se/pub/X11/ftp.x.org/contrib/applications/ \
	ftp://ftp.kddlabs.co.jp/X11/ftp.x.org/contrib/applications/ \
	ftp://ftp.gwdg.de/pub/x11/x.org/contrib/applications/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	# AWOL
COMMENT=	Rotating map of the Earth in X11 root window

USE_IMAKE=	yes
INSTALL_MAKE_FLAGS=	MANPATH=${PREFIX}/${PKGMANDIR}

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

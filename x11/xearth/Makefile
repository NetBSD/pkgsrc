# $NetBSD: Makefile,v 1.20 2009/05/01 15:31:14 zafer Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes
INSTALL_MAKE_FLAGS=	MANPATH=${PREFIX}/${PKGMANDIR}

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.2 2007/04/10 13:28:24 joerg Exp $
#

DISTNAME=	xev-1.0.2
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/app/
COMMENT=	Display X events

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

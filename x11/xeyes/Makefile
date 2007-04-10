# $NetBSD: Makefile,v 1.1.1.1 2007/04/10 13:46:51 joerg Exp $
#

DISTNAME=	xeyes-1.0.1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/app/
COMMENT=	Follow the mouse demo

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

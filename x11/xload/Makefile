# $NetBSD: Makefile,v 1.1.1.1 2007/02/25 06:19:02 dsainty Exp $
#

DISTNAME=	xload-1.0.1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/releases/individual/app/
COMMENT=	System load average display for X

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

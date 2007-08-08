# $NetBSD: Makefile,v 1.1.1.1 2007/08/08 17:35:15 joerg Exp $

DISTNAME=	sessreg-1.0.2
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Manage utmp/wtmp entries for xdm

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

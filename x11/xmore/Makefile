# $NetBSD: Makefile,v 1.2 2007/04/16 16:20:40 joerg Exp $
#

DISTNAME=		xmore-1.0.1
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Plain text browser

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXprintUtil/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

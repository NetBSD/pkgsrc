# $NetBSD: Makefile,v 1.3 2007/09/21 19:40:22 bjs Exp $
#

DISTNAME=		xmag-1.0.2
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Magnify parts of the screen

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

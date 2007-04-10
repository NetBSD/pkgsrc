# $NetBSD: Makefile,v 1.1.1.1 2007/04/10 13:46:29 joerg Exp $
#

DISTNAME=		editres-1.0.3
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Dynamic resource editor for libXt applications

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

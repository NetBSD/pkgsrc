# $NetBSD: Makefile,v 1.1.1.1 2007/03/07 15:03:08 joerg Exp $
#

DISTNAME=		appres-1.0.1
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Print resources seen by an application

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

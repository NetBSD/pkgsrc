# $NetBSD: Makefile,v 1.6 2008/04/16 22:07:24 wiz Exp $
#

DISTNAME=		xinit-1.0.8
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/app/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X init program

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config xauth:run

.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

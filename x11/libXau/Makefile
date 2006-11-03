# $NetBSD: Makefile,v 1.1.1.1 2006/11/03 17:56:32 joerg Exp $
#

DISTNAME=		libXau-1.0.0
CATEGORIES=		x11 devel
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Authorization Protocol for X from X.org

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xau.pc.in

.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1.1.1 2006/11/03 19:53:21 joerg Exp $
#

DISTNAME=		printproto-1.0.3
CATEGORIES=		x11 print
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/releases/individual/proto/
COMMENT=		Print extension headers from X.org

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	printproto.pc.in

.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1.1.1 2006/11/14 15:55:20 joerg Exp $
#

DISTNAME=		xf86dgaproto-2.0.2
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		XF86DGA extension headers

PKG_DESTDIR_SUPPORT=	user-destdir

PKGCONFIG_OVERRIDE+=	xf86dgaproto.pc.in
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

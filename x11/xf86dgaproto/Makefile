# $NetBSD: Makefile,v 1.2 2008/01/15 23:27:32 wiz Exp $
#

DISTNAME=		xf86dgaproto-2.0.3
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

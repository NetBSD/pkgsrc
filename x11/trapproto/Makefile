# $NetBSD: Makefile,v 1.1.1.1 2006/11/03 20:02:34 joerg Exp $
#

DISTNAME=		trapproto-3.4.3
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Trap extension headers

PKG_DESTDIR_SUPPORT=	user-destdir

PKGCONFIG_OVERRIDE+=	${WRKSRC}/trapproto.pc.in
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

BUILDLINK_DEPMETHOD.libX11?=	build
BUILDLINK_DEPMETHOD.libXi?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

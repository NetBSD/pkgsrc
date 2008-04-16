# $NetBSD: Makefile,v 1.2 2008/04/16 14:33:04 wiz Exp $
#

DISTNAME=		xf86driproto-2.0.4
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		XF86DRI extension headers from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	xf86driproto.pc.in
USE_LANGUAGES=		# empty

BUILDLINK_DEPMETHOD.libdrm?=	build

.include "../../x11/glproto/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

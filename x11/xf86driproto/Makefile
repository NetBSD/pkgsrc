# $NetBSD: Makefile,v 1.5 2012/06/03 18:39:36 wiz Exp $
#

DISTNAME=		xf86driproto-2.1.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		XF86DRI extension headers from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	xf86driproto.pc.in
USE_LANGUAGES=		c

BUILDLINK_DEPMETHOD.libdrm?=	build

.include "../../x11/glproto/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

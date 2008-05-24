# $NetBSD: Makefile,v 1.3 2008/05/24 21:45:18 tnn Exp $
#

DISTNAME=		xf86driproto-2.0.4
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
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

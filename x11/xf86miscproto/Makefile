# $NetBSD: Makefile,v 1.4 2012/10/29 05:07:08 asau Exp $
#

DISTNAME=		xf86miscproto-0.9.3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		XF86Misc extension headers from modular X.org

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	xf86miscproto.pc.in

.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

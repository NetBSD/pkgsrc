# $NetBSD: Makefile,v 1.3 2010/01/15 18:20:47 tnn Exp $
#

DISTNAME=		xf86vidmodeproto-2.3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		XF86VidMode extension headers from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	xf86vidmodeproto.pc.in

.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

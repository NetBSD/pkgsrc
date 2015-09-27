# $NetBSD: Makefile,v 1.8 2015/09/27 05:17:49 tnn Exp $
#

DISTNAME=		xf86driproto-2.1.1
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		XF86DRI extension headers from modular X.org

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	xf86driproto.pc.in
USE_LANGUAGES=		c

.include "../../mk/bsd.pkg.mk"

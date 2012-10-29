# $NetBSD: Makefile,v 1.5 2012/10/29 05:07:12 asau Exp $
#

DISTNAME=		xineramaproto-1.2.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xinerama extension headers from X.org

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	xineramaproto.pc.in

BUILDLINK_DEPMETHOD.libX11?=	build # uses headers
.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.3 2010/04/09 08:36:30 tnn Exp $
#

DISTNAME=		xineramaproto-1.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xinerama extension headers from X.org

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	xineramaproto.pc.in

BUILDLINK_DEPMETHOD.libX11?=	build # uses headers
.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

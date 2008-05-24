# $NetBSD: Makefile,v 1.2 2008/05/24 21:45:18 tnn Exp $
#

DISTNAME=		xineramaproto-1.1.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Xinerama extension headers from X.org

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	xineramaproto.pc.in
USE_LANGUAGES=		# empty

BUILDLINK_DEPMETHOD.libX11?=	build # uses headers
.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

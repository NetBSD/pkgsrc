# $NetBSD: Makefile,v 1.1.1.1 2006/11/03 20:07:33 joerg Exp $
#

DISTNAME=		xineramaproto-1.1.2
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
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

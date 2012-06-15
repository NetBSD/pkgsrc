# $NetBSD: Makefile,v 1.5 2012/06/15 23:06:04 dholland Exp $
#

DISTNAME=		videoproto-2.3.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Video extension headers from modular X.org X11
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir

PKGCONFIG_OVERRIDE+=	videoproto.pc.in
GNU_CONFIGURE=		yes

BUILDLINK_DEPMETHOD.libX11?=	build # uses headers
.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

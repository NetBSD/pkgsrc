# $NetBSD: Makefile,v 1.3 2009/08/29 15:29:47 wiz Exp $
#

DISTNAME=		videoproto-2.3.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Video extension headers from modular X.org X11

PKG_DESTDIR_SUPPORT=	user-destdir

PKGCONFIG_OVERRIDE+=	videoproto.pc.in
GNU_CONFIGURE=		yes
USE_LANGUAGES=		# empty

BUILDLINK_DEPMETHOD.libX11?=        build # uses headers
.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

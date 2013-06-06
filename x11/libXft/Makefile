# $NetBSD: Makefile,v 1.15 2013/06/06 12:53:41 wiz Exp $

DISTNAME=	libXft-2.3.1
PKGREVISION=	3
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/Xft/
COMMENT=	Library for configuring and customizing font access

CONFLICTS+=	Xft2-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE=	xft.pc.in

.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.6
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

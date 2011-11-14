# $NetBSD: Makefile,v 1.21 2011/11/14 14:07:35 cheusov Exp $
#

DISTNAME=		libXfont-1.4.4
CATEGORIES=		x11 devel fonts
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X font Library
LICENSE=		mit AND modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xfont.pc.in

CONFIGURE_ARGS+=	--disable-devel-docs

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/fontcacheproto/buildlink3.mk"
.include "../../fonts/libfontenc/buildlink3.mk"
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/xtrans/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.39 2007/06/30 03:57:10 joerg Exp $

DISTNAME=	xplanet-1.2.0
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xplanet/}

MAINTAINER=	atatat@NetBSD.org
HOMEPAGE=	http://xplanet.sourceforge.net/
COMMENT=	Rotating rendered map of the Earth in X11 root window

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PERL=${_ENV_PERL:Q}
_ENV_PERL=		${TOOLS_SETENV} perl

# directory creation should be fixed in the future release of xplanet
XPLANET_DIRS=		arcs config ephemeris fonts images markers origin
XPLANET_DIRS+=		satellites scripts spice stars
INSTALLATION_DIRS+=	${XPLANET_DIRS:C,.*,share/xplanet/&,g}

PKG_OPTIONS_VAR=	PKG_OPTIONS.xplanet
PKG_SUPPORTED_OPTIONS=	x11
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
USE_TOOLS+=	pkg-config

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/pango/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pango
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-xscreensaver
.endif


.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/netpbm/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

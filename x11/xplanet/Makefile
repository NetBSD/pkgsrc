# $NetBSD: Makefile,v 1.33 2006/09/20 18:23:48 xtraeme Exp $

DISTNAME=	xplanet-1.2.0
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xplanet/}

MAINTAINER=	atatat@NetBSD.org
HOMEPAGE=	http://xplanet.sourceforge.net/
COMMENT=	Rotating rendered map of the Earth in X11 root window

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

# directory creation should be fixed in the future release of xplanet
pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xplanet
.for dir in arcs config fonts images markers origin satellites \
		scripts spice stars
	${INSTALL_DATA_DIR} ${PREFIX}/share/xplanet/${dir}
.endfor

PKG_OPTIONS_VAR=        PKG_OPTIONS.xplanet
PKG_SUPPORTED_OPTIONS=  x11
PKG_SUGGESTED_OPTIONS=  x11

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mx11)
.include "../../devel/pango/buildlink3.mk"
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

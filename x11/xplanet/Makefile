# $NetBSD: Makefile,v 1.71 2014/05/05 00:48:37 ryoon Exp $

DISTNAME=	xplanet-1.2.2
PKGREVISION=	18
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xplanet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xplanet.sourceforge.net/
COMMENT=	Rotating rendered map of the Earth in X11 root window
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PERL=${_ENV_PERL:Q}
_ENV_PERL=		${TOOLS_SETENV} perl

# directory creation should be fixed in the future release of xplanet
XPLANET_DIRS=		arcs config ephemeris fonts images markers origin
XPLANET_DIRS+=		satellites scripts spice stars
INSTALLATION_DIRS+=	${XPLANET_DIRS:C,.*,share/xplanet/&,g}

.include "options.mk"

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../graphics/netpbm/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

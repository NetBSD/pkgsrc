# $NetBSD: Makefile,v 1.14 2004/01/24 15:30:34 grant Exp $
#

DISTNAME=		xplanet-1.0.1
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xplanet/}

MAINTAINER=		atatat@NetBSD.org
HOMEPAGE=		http://xplanet.sourceforge.net/
COMMENT=		Rotating rendered map of the Earth in X11 root window

USE_BUILDLINK2=		yes
USE_GCC_SHLIB=		yes
USE_X11=		yes
USE_GNU_TOOLS+=		make

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-gl-dir=${BUILDLINK_PREFIX.Mesa}
CONFIGURE_ARGS+=	--with-glut-dir=${BUILDLINK_PREFIX.Mesa}

LIBS=			-lXext -lpbm -lppm -lpgm
MAKE_ENV+=		LIBS="${LIBS}"

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../graphics/netpbm/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"

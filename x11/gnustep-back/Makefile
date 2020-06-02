# $NetBSD: Makefile,v 1.77 2020/06/02 08:23:02 adam Exp $

DISTNAME=	gnustep-back-0.22.0
PKGREVISION=	23
CATEGORIES=	x11 gnustep
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnustep.org/
COMMENT=	X11 AppKit backend for GNUstep
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		objc
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/libexec/GNUstep
LDFLAGS=		${COMPILER_RPATH_FLAG}${PREFIX}/lib
MAKE_FILE=		GNUmakefile

pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${GNUSTEP_ROOT}/lib/GNUstep/Fonts

.include "../../devel/gnustep-make/gnustep.mk"

PREFER_PKGSRC+=	freetype2

.include "../../x11/gnustep-gui/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

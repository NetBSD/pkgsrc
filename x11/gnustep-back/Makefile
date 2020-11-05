# $NetBSD: Makefile,v 1.80 2020/11/05 09:07:14 ryoon Exp $

GITHUB_PROJECT=	libs-back
GITHUB_TAG=	back-0_28_0
DISTNAME=	back-0_28_0
PKGREVISION=	1
CATEGORIES=	x11 gnustep
PKGNAME=	gnustep-${DISTNAME:S/_/./g}
MASTER_SITES=	${MASTER_SITE_GITHUB:=gnustep/}

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

PLIST_SUBST=	API_VERSION=${PKGVERSION:C/\.[0-9]$//:C/\.//}

pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${GNUSTEP_ROOT}/lib/GNUstep/Fonts

.include "../../devel/gnustep-make/gnustep.mk"

#REFER_PKGSRC+=	freetype2

.include "../../x11/gnustep-gui/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

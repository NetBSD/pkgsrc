# $NetBSD: Makefile,v 1.93 2024/05/29 16:34:59 adam Exp $

DISTNAME=	gnustep-gui-0.30.0
PKGREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=gnustep/}
GITHUB_PROJECT=	libs-gui
GITHUB_TAG=	gui-${PKGVERSION_NOREV:S/./_/g}
DIST_SUBDIR=	gnustep-gui

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gnustep/libs-gui/
COMMENT=	GNUstep AppKit Implementation
LICENSE=	gnu-lgpl-v2.1 OR gnu-gpl-v3

USE_TOOLS+=		gmake
USE_LANGUAGES=		objc
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/libexec/GNUstep
MAKE_FILE=		GNUmakefile

# uses _Unwind_Resume, needs to directly link against libunwind
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib -L${PREFIX}/lib -lunwind
PLIST_SUBST=	API_VERSION=${PKGVERSION_NOREV:C/\.[0-9]$//}

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../lang/libunwind/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.81 2020/11/13 02:47:45 mef Exp $

GITHUB_PROJECT=	libs-gui
GITHUB_TAG=	gui-0_28_0
DISTNAME=	gui-0_28_0
PKGNAME=	gnustep-${DISTNAME:S/_/./g}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=gnustep/}
DIST_SUBDIR=	gnustep-gui

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gnustep/libs-gui/
COMMENT=	GNUstep AppKit Implementation
LICENSE=	gnu-lgpl-v2.1 OR gnu-gpl-v3

WRKSRC=			${WRKDIR}/libs-gui-${DISTNAME}
USE_TOOLS+=		gmake
USE_LANGUAGES=		objc
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/libexec/GNUstep
MAKE_FILE=		GNUmakefile

PLIST_SUBST=	API_VERSION=${PKGVERSION:C/\.[0-9][nb]*[0-9]*$//}

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

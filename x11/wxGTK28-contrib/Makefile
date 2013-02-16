# $NetBSD: Makefile,v 1.21 2013/02/16 11:17:57 wiz Exp $
#

.include "../../x11/wxGTK28/Makefile.common"

PKGNAME=		${DISTNAME:S/wxGTK/wxGTK28-contrib/}
PKGREVISION=		19
COMMENT=		GTK-based implementation of the wxWidgets GUI library (contrib libraries)

USE_TOOLS+=		gmake

BUILD_DIRS=		${WRKSRC}/build-non-unicode/contrib/src \
			${WRKSRC}/build-unicode/contrib/src

INSTALL_TARGET=		install

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

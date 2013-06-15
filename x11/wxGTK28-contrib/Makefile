# $NetBSD: Makefile,v 1.27 2013/06/15 02:30:57 ryoon Exp $
#

.include "../../x11/wxGTK28/Makefile.common"

PKGNAME=	${DISTNAME:S/wxGTK/wxGTK28-contrib/}
COMMENT=	Contrib libraries for wxWidgets GTK

USE_TOOLS+=		gmake

BUILD_DIRS=		build-non-unicode/contrib/src \
			build-unicode/contrib/src

INSTALL_TARGET=		install

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.42 2020/03/10 22:09:17 wiz Exp $

.include "../../x11/wxGTK28/Makefile.common"

PKGNAME=	${DISTNAME:S/wxGTK/wxGTK28-contrib/}
PKGREVISION=	15
COMMENT=	Contrib libraries for wxWidgets GTK

USE_TOOLS+=		gmake

BUILD_DIRS=		build-non-unicode/contrib/src \
			build-unicode/contrib/src

INSTALL_TARGET=		install

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

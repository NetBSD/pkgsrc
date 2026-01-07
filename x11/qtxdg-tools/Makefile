# $NetBSD: Makefile,v 1.27 2026/01/07 08:49:47 wiz Exp $

.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	qtxdg-tools-4.3.0
PKGREVISION=	2
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/qtxdg-tools/
COMMENT=	User tools for LXQt components
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

TOOL_DEPENDS+=	lxqt-build-tools>=2.3.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/libqtxdg/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"

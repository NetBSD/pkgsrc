# $NetBSD: Makefile,v 1.30 2026/05/14 16:42:33 ryoon Exp $

PKGREVISION= 1
.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	qtxdg-tools-4.4.0
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/qtxdg-tools/
COMMENT=	User tools for LXQt components
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

TOOL_DEPENDS+=	lxqt-build-tools>=2.4.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/libqtxdg/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"

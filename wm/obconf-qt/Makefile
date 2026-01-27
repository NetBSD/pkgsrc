# $NetBSD: Makefile,v 1.48 2026/01/27 08:40:46 wiz Exp $

.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	obconf-qt-0.16.6
PKGREVISION=	3
CATEGORIES=	wm

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/obconf-qt/
COMMENT=	Qt based configurator of OpenBox window manager
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config perl

TOOL_DEPENDS+=	lxqt-build-tools>=2.3.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../wm/openbox/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"

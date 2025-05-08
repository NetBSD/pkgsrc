# $NetBSD: Makefile,v 1.44 2025/05/08 11:46:31 pin Exp $

DISTNAME=	qterminal-2.2.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/qterminal/
COMMENT=	Terminal emulator for Qt6
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

TOOL_DEPENDS+=	lxqt-build-tools>=2.2.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/qtermwidget/buildlink3.mk"
.include "../../x11/plasma6-layer-shell-qt/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"

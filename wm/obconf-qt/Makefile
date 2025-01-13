# $NetBSD: Makefile,v 1.40 2025/01/13 16:51:56 riastradh Exp $

DISTNAME=	obconf-qt-0.16.5
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/obconf-qt/
COMMENT=	Qt based configurator of OpenBox window manager
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

TOOL_DEPENDS+=	lxqt-build-tools>=2.1.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../wm/openbox/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"

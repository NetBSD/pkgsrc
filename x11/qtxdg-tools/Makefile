# $NetBSD: Makefile,v 1.16 2024/08/20 06:25:48 pin Exp $

DISTNAME=	qtxdg-tools-4.0.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/qtxdg-tools/
COMMENT=	User tools for LXQt components
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

TOOL_DEPENDS+=	lxqt-build-tools>=2.0.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/libqtxdg/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"

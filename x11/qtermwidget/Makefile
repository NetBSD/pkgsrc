# $NetBSD: Makefile,v 1.46 2026/02/06 10:06:20 wiz Exp $

.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	qtermwidget-2.3.0
PKGREVISION=	3
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/qtermwidget/
COMMENT=	Terminal emulator widget for Qt6
LICENSE=	gnu-lgpl-v2.1 AND modified-bsd

USE_TOOLS+=	pkg-config perl

LDFLAGS.NetBSD+=	-lutil

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	lib/qtermwidget.cpp
SUBST_SED.prefix=	-e 's,/usr/share,${PREFIX}/share,g'

TOOL_DEPENDS+=	lxqt-build-tools>=2.3.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"

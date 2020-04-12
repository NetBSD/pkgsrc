# $NetBSD: Makefile,v 1.5 2020/04/12 08:28:12 adam Exp $

DISTNAME=	libfm-qt-0.14.1
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	https://downloads.lxqt.org/downloads/libfm-qt/0.14.1/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	voidpin@protonmail.com
HOMEPAGE=	https://lxqt.org/
COMMENT=	Core library of PCManFM-Qt
LICENSE=	gnu-lgpl-v2.1 AND modified-bsd

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH:PATH=${PREFIX}/qt5

PKG_SYSCONFSUBDIR=	xdg

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	src/core/fileinfo.cpp
SUBST_FILES.prefix+=	src/core/vfs/vfs-menu.c
# Upstream has a typo in a hard-coded path of "xgd" where they mean "xdg".
# On the next update, check vfs-menu.c, as this will likely be corrected
# to "xdg": https://github.com/lxqt/libfm-qt/pull/528
SUBST_SED.prefix=	-e 's,/etc/xgd,${PKG_SYSCONFDIR},g'
SUBST_SED.prefix+=	-e 's,/usr/share,${PREFIX}/share,g'

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools-[0-9]*:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

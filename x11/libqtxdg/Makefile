# $NetBSD: Makefile,v 1.35 2024/08/02 16:54:22 pin Exp $

DISTNAME=	libqtxdg-4.0.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/libqtxdg/
COMMENT=	Qt implementation of freedesktop.org xdg specs
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

QTXDG_CONF=		share/lxqt
PKG_SYSCONFSUBDIR=	xdg

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	src/qtxdg/xdgdirs.cpp
SUBST_SED.prefix=	-e 's,/etc/xdg,${PKG_SYSCONFDIR},g'
SUBST_SED.prefix+=	-e 's,/usr/share,${PREFIX}/share,g'

CONF_FILES=	${QTXDG_CONF}/lxqt-qtxdg.conf \
		${PKG_SYSCONFDIR}/lxqt-qtxdg.conf
CONF_FILES+=	${QTXDG_CONF}/qtxdg.conf \
		${PKG_SYSCONFDIR}/qtxdg.conf

BUILDLINK_TRANSFORM.SunOS+=	rm:-fuse-linker-plugin

TOOL_DEPENDS+=	lxqt-build-tools>=2.0.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "NetBSD" || ${X11_TYPE} == "modular"
DEPENDS+=	{xterm,mxterm}-[0-9]*:../../x11/xterm
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.16 2022/01/03 12:16:36 pin Exp $

DISTNAME=	lxqt-session-1.0.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-session/
COMMENT=	Session manager
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Linux"
CMAKE_ARGS+=	-DWITH_LIBUDEV=OFF
.endif

AUTOSTART_CONF=		share/examples/autostart
PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS=		${PKG_SYSCONFDIR}/autostart

CONF_FILES+=		${AUTOSTART_CONF}/lxqt-xscreensaver-autostart.desktop \
			${PKG_SYSCONFDIR}/autostart/lxqt-xscreensaver-autostart.desktop

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing paths.
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	lxqt-config-session/autostartedit.cpp
SUBST_FILES.prefix+=	lxqt-config-session/sessionconfigwindow.cpp
SUBST_FILES.prefix+=	lxqt-session/src/wmselectdialog.cpp
SUBST_SED.prefix=	-e 's,/usr/bin,${PREFIX}/bin,g'

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools>=0.10.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools
DEPENDS+=	xdg-user-dirs-[0-9]*:../../x11/xdg-user-dirs

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/kwindowsystem/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/liblxqt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.51 2026/04/28 09:20:04 pin Exp $

.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	lxqt-session-2.4.0
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-session/
COMMENT=	Session manager
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config perl

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

TOOL_DEPENDS+=	lxqt-build-tools>=2.4.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools
DEPENDS+=	qtxdg-tools>=4.4.0:../../x11/qtxdg-tools
DEPENDS+=	xdg-user-dirs-[0-9]*:../../x11/xdg-user-dirs

.include "options.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/liblxqt/buildlink3.mk"
.include "../../x11/plasma6-layer-shell-qt/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"

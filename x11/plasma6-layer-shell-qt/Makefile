# $NetBSD: Makefile,v 1.2 2024/11/01 00:54:23 wiz Exp $

DISTNAME=	layer-shell-qt-${PLASMAVER}
PKGREVISION=	1
CATEGORIES=	x11

HOMEPAGE=	https://invent.kde.org/plasma/layer-shell-qt
COMMENT=	Qt component to allow applications to use the Wayland wl-layer-shell protocol
LICENSE=	gnu-lgpl-v3 AND cc0-1.0-universal AND mit AND modified-bsd

.include "../../meta-pkgs/kde/plasma6.mk"

TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

USE_TOOLS+=	pkg-config

.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/qt6-qtwayland/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

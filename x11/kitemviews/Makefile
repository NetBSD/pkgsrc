# $NetBSD: Makefile,v 1.11 2017/09/12 13:52:03 wiz Exp $

DISTNAME=	kitemviews-${KF5VER}
PKGREVISION=	8
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Widget addons for Qt Model/View
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

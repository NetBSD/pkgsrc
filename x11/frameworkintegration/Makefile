# $NetBSD: Makefile,v 1.35 2020/06/02 08:23:02 adam Exp $

DISTNAME=	frameworkintegration-${KF5VER}
PKGREVISION=	4
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Provide components to allow applications to integrate with a KDE Workspace
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

DEPENDS+=	noto-ttf-[0-9]*:../../fonts/noto-ttf

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/kpackage/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

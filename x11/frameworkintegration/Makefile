# $NetBSD: Makefile,v 1.12 2017/09/12 13:52:00 wiz Exp $

DISTNAME=	frameworkintegration-${KF5VER}
PKGREVISION=	9
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Provide components to allow applications to integrate with a KDE Workspace
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

DEPENDS+=	noto-ttf-[0-9]*:../../fonts/noto-ttf
DEPENDS+=	oxygen-fonts-[0-9]*:../../fonts/oxygen-fonts

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.60 2023/01/29 21:15:01 ryoon Exp $

DISTNAME=	sonnet-${KF5VER}
PKGREVISION=	2
CATEGORIES=	textproc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Spelling framework for Qt5
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

.include "../../meta-pkgs/kde/kf5.mk"

.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

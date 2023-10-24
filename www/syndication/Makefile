# $NetBSD: Makefile,v 1.19 2023/10/24 22:11:35 wiz Exp $

DISTNAME=	syndication-${KF5VER}
PKGREVISION=	1
CATEGORIES=	www

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	RSS/Atom parser library
LICENSE=	gnu-lgpl-v2.1 AND 2-clause-bsd

.include "../../meta-pkgs/kde/kf5.mk"

.include "../../textproc/kcodecs/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

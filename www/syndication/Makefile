# $NetBSD: Makefile,v 1.5 2021/12/08 16:02:48 adam Exp $

DISTNAME=	syndication-${KF5VER}
PKGREVISION=	4
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

# $NetBSD: Makefile,v 1.32 2020/08/31 18:12:18 wiz Exp $

DISTNAME=	syntax-highlighting-${KF5VER}
PKGREVISION=	3
CATEGORIES=	textproc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Syntax highlighting engine for structured text and code
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	perl

CHECK_PORTABILITY_SKIP+=	autotests/input/highlight.sh

.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

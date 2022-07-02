# $NetBSD: Makefile,v 1.47 2022/07/02 16:53:36 ryoon Exp $

DISTNAME=	syntax-highlighting-${KF5VER}
PKGREVISION=	2
CATEGORIES=	textproc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Syntax highlighting engine for structured text and code
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	perl

CHECK_PORTABILITY_SKIP+=	autotests/input/highlight.sh
CHECK_PORTABILITY_SKIP+=	autotests/folding/highlight.sh.fold

.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

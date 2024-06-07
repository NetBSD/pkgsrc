# $NetBSD: Makefile,v 1.66 2024/06/07 23:55:47 markd Exp $

DISTNAME=	syntax-highlighting-${KF5VER}
CATEGORIES=	textproc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Syntax highlighting engine for structured text and code
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	perl

CHECK_PORTABILITY_SKIP+=	autotests/input/highlight.sh
CHECK_PORTABILITY_SKIP+=	autotests/folding/highlight.sh.fold

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"

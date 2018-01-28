# $NetBSD: Makefile,v 1.17 2018/01/28 20:11:05 wiz Exp $

DISTNAME=	sonnet-${KF5VER}
PKGREVISION=	3
CATEGORIES=	textproc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Spelling framework for Qt5
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kf5/Makefile.common"

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/sonnet.categories \
		${PKG_SYSCONFDIR}/xdg/sonnet.categories

.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt5-qttools= build
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

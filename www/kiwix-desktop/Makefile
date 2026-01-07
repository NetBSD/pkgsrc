# $NetBSD: Makefile,v 1.6 2026/01/07 08:49:19 wiz Exp $

DISTNAME=	kiwix-desktop-2.5.0
PKGREVISION=	1
CATEGORIES=	www textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=kiwix/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kiwix/kiwix-desktop/
COMMENT=	Kiwix for desktops
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config
MAKE_ENV+=	QT_SELECT=qt6

BUILDLINK_TRANSFORM+=	rm:-Werror

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake PREFIX=${DESTDIR}${PREFIX} .

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../net/aria2/buildlink3.mk"
.include "../../textproc/libzim/buildlink3.mk"
.include "../../www/libkiwix/buildlink3.mk"
.include "../../www/qt6-qtwebengine/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1 2025/08/31 20:22:36 wiz Exp $

DISTNAME=	kiwix-desktop-2.4.1
CATEGORIES=	www textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=kiwix/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kiwix/kiwix-desktop/
COMMENT=	Kiwix for desktops
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config

do-configure:
	cd ${WRKSRC} && ${QTDIR}/bin/qmake PREFIX=${DESTDIR}${PREFIX} .

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/aria2/buildlink3.mk"
.include "../../textproc/libzim/buildlink3.mk"
.include "../../www/libkiwix/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

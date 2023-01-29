# $NetBSD: Makefile,v 1.14 2023/01/29 21:18:07 ryoon Exp $

DISTNAME=	appmenu-qt-0.2.6
PKGREVISION=	9
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/appmenu-qt/trunk/0.2.6/+download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/appmenu-qt/
COMMENT=	Allows Qt applications to export menus over DBus to a menu applet
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

.include "../../devel/libdbusmenu-qt/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

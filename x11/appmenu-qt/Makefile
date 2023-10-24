# $NetBSD: Makefile,v 1.15 2023/10/24 22:11:36 wiz Exp $

DISTNAME=	appmenu-qt-0.2.6
PKGREVISION=	10
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

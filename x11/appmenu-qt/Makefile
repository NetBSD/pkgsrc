# $NetBSD: Makefile,v 1.1 2013/10/19 21:03:37 markd Exp $
#

DISTNAME=	appmenu-qt-0.2.6
CATEGORIES=	x11
MASTER_SITES=	http://launchpad.net/appmenu-qt/trunk/0.2.6/+download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://launchpad.net/appmenu-qt/
COMMENT=	Allows Qt applications to export menus over DBus to a menu applet
LICENSE=	gnu-lgpl-v2.1

FETCH_USING=	curl

USE_LANGUAGES=  c c++
USE_CMAKE=      yes

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

.include "../../devel/libdbusmenu-qt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

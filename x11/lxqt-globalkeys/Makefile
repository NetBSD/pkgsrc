# $NetBSD: Makefile,v 1.1 2020/04/25 01:34:53 gutteridge Exp $

DISTNAME=	lxqt-globalkeys-0.14.3
CATEGORIES=	x11
MASTER_SITES=	https://downloads.lxqt.org/downloads/lxqt-globalkeys/0.14.3/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxqt.org/
COMMENT=	Daemon and library for global keyboard shortcuts registration
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..

pre-configure:
	${MKDIR} -p ${WRKSRC}/build

TOOL_DEPENDS+=	lxqt-build-tools-[0-9]*:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/liblxqt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.2 2020/04/25 15:18:42 gutteridge Exp $

DISTNAME=	lxqt-runner-0.14.1
CATEGORIES=	x11
MASTER_SITES=	https://downloads.lxqt.org/downloads/lxqt-runner/0.14.1/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lxqt.org/
COMMENT=	Launch applications quickly by typing commands
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

.include "../../x11/lxqt-globalkeys/buildlink3.mk"
.include "../../math/muparser/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

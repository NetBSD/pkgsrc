# $NetBSD: Makefile,v 1.24 2026/01/07 08:49:46 wiz Exp $

DISTNAME=	qt6ct-0.11
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	https://www.opencode.net/trialuser/qt6ct/-/archive/${PKGVERSION_NOREV}/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://www.opencode.net/trialuser/qt6ct
COMMENT=	Qt6 configuration tool
LICENSE=	2-clause-bsd

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++11
USE_TOOLS=		pkg-config

GCC_REQD+=	9 #qt6
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,-O1

QMAKE_ARGS+=	qt6ct.pro
QMAKE_ARGS+=	QMAKE_CXXFLAGS=${CXXFLAGS:Q}
QMAKE_ARGS+=	PREFIX=${PREFIX} PLUGINDIR=${QTDIR}/plugins

DOCDIR=			share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${DOCDIR}
INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	${RUN}cd ${WRKSRC} &&			\
		${SETENV} ${CONFIGURE_ENV}	\
		${QTDIR}/bin/qmake ${QMAKE_ARGS}

post-install:
	${INSTALL_DATA}	${WRKSRC}/README.md	\
		${DESTDIR}${PREFIX}/${DOCDIR}/README

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

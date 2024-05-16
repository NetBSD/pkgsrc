# $NetBSD: Makefile,v 1.23 2024/05/16 06:15:46 wiz Exp $

DISTNAME=	x2goclient-${PKGVER}
PKGVER=		4.1.2.3
PKGREVISION=	2
CATEGORIES=	x11 net
MASTER_SITES=	http://code.x2go.org/releases/source/x2goclient/

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://www.x2go.org/
COMMENT=	Qt client for the X2Go remote desktop system

LICENSE=	gnu-gpl-v2

NOT_FOR_PLATFORM+=	Linux-*-* Darwin-*-*

USE_TOOLS+=		pkg-config gmake
USE_LIBTOOL=		yes

USE_LANGUAGES=		c c++

# Supported are qt4, qt5
QT_VERSION=		5

BUILD_TARGET=		build_client

ICON_THEMES=		yes

LIBS+=			-lXpm -lcups

.if ${QT_VERSION} == "5"
LIBS+=			-lQt5X11Extras
.endif

DOCDIR=			share/doc/x2go

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing absolute paths
SUBST_FILES.paths=	Makefile
SUBST_VARS.paths+=	PREFIX DESTDIR PKG_SYSCONFDIR SH
SUBST_VARS.paths+=	INSTALL_DATA INSTALL_DATA_DIR INSTALL_PROGRAM
SUBST_VARS.paths+=	QT_VERSION QMAKE_OPTS LDFLAGS LIBS

SUBST_CLASSES+=		os-def
SUBST_STAGE.os-def=	pre-configure
SUBST_MESSAGE.os-def=	Re-purposing Q_OS_LINUX defines for all Unixen
SUBST_NOOP_OK.os-def=	yes
SUBST_FILES.os-def=	src/*.cpp
SUBST_FILES.os-def+=	src/*.h
# Too broad a brush, but should be dealt with by upstream
SUBST_SED.os-def=	-e 's/Q_OS_LINUX/Q_OS_UNIX/'
# - because above
SUBST_SED.os-def+=	-e '/<linux\/fs.h>/s|^|//|'
# Too sweeping, mostly macosx paths
SUBST_SED.os-def+=	-e 's|/usr/local/bin|${PREFIX}\/bin|'

.include "options.mk"

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	${DOCDIR}
INSTALLATION_DIRS+=	share/icons/hicolor/128x128/apps
INSTALLATION_DIRS+=	share/icons/hicolor/64x64/apps
INSTALLATION_DIRS+=	share/icons/hicolor/32x32/apps
INSTALLATION_DIRS+=	share/icons/hicolor/16x16/apps
INSTALLATION_DIRS+=	share/x2goclient/icons

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/qmake-qt${QT_VERSION}
	${LN} -sf ${QTDIR}/bin/lrelease ${BUILDLINK_DIR}/bin/lrelease-qt${QT_VERSION}

post-install:
	${INSTALL_DATA} ${WRKSRC}/HOWTO.GPGCARD ${DESTDIR}${PREFIX}/${DOCDIR}

.if ${QT_VERSION} == "4"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.elif ${QT_VERSION} == "5"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

.include "../../print/libcups/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../x11/nx-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

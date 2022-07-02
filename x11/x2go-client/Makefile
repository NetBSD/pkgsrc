# $NetBSD: Makefile,v 1.9 2022/07/02 16:53:42 ryoon Exp $

DISTNAME=	x2goclient-${PKGVER}
PKGVER=		4.1.2.2
PKGREVISION=	7
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

ICON_THEMES=		yes

LIBS+=			-lXpm -lcups

DOCDIR=			share/doc/x2go

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing absolute paths
SUBST_FILES.paths=	Makefile
SUBST_VARS.paths+=	PREFIX DESTDIR PKG_SYSCONFDIR SH
SUBST_VARS.paths+=	INSTALL_DATA INSTALL_DATA_DIR INSTALL_PROGRAM
SUBST_VARS.paths+=	QMAKE_OPTS LDFLAGS LIBS

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
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/qmake-qt4
	${LN} -sf ${QTDIR}/bin/lrelease ${BUILDLINK_DIR}/bin/lrelease-qt4

post-install:
	${INSTALL_DATA} ${WRKSRC}/HOWTO.GPGCARD ${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

.include "../../print/libcups/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../x11/nx-libs/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"

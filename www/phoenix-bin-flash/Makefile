# $NetBSD: Makefile,v 1.1.1.1 2003/04/29 13:37:09 kei Exp $

DISTNAME=		install_flash_player_6_${DISTUNAME}
PKGNAME=		phoenix-bin-flash-${FLASH_VERS:S/r/./}
CATEGORIES=		www graphics
MASTER_SITES=		http://download.macromedia.com/pub/shockwave/flash/${SUB}/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.flash.com/
COMMENT=		Flash Player plugin for phoenix-bin

ONLY_FOR_PLATFORM=      *-*-i386

DIST_SUBDIR=		flash/${FLASH_VERS}

.include "../../mk/bsd.prefs.mk"

SUB=			english/${DISTUNAME}/${FLASH_VERS}

FLASH_VERS=		6.0r79
DEPENDS+=		suse_compat>=6.3:../../emulators/${SUSE_DIR_PREFIX}_compat
DEPENDS+=		suse_x11>=6.3:../../emulators/${SUSE_DIR_PREFIX}_x11
DEPENDS+=		phoenix-bin>=0.5:../../www/phoenix-bin
DISTUNAME=		linux
WRKNAME=		install_flash_player_6_${DISTUNAME}

RESTRICTED=             "Redistribution not permitted"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_BUILDLINK2=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes
CHECK_SHLIBS=		no
CRYPTO=			yes

MOZ_NAME=		phoenix-linux
WRKSRC=			${WRKDIR}/${WRKNAME}
NS_PLUGINS_DIR=		${PREFIX}/lib/${MOZ_NAME}/plugins

PLIST_SUBST+=		MOZ_NAME="${MOZ_NAME}"

do-install:
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/flashplayer.xpt ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/libflashplayer.so ${NS_PLUGINS_DIR}

.include "../../mk/bsd.pkg.install.mk"
.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"

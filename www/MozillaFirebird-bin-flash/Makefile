# $NetBSD: Makefile,v 1.1.2.1 2004/01/09 22:22:58 agc Exp $

DISTNAME=		install_flash_player_6_${DISTUNAME}
PKGNAME=		MozillaFirebird-bin-flash-${FLASH_VERS:S/r/./}
CATEGORIES=		www graphics
MASTER_SITES=		http://download.macromedia.com/pub/shockwave/flash/${SUB}/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.flash.com/
COMMENT=		Flash Player plugin for MozillaFirebird-bin

ONLY_FOR_PLATFORM=      *-*-i386

DIST_SUBDIR=		flash/${FLASH_VERS}

.include "../../mk/bsd.prefs.mk"

SUB=			english/${DISTUNAME}/${FLASH_VERS}

FLASH_VERS=		6.0r79
DEPENDS+=		MozillaFirebird-bin>=0.6.1:../../www/MozillaFirebird-bin
DISTUNAME=		linux
WRKNAME=		install_flash_player_6_${DISTUNAME}

RESTRICTED=             "Redistribution not permitted"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
NO_CONFIGURE=		yes
NO_BUILD=		yes
CHECK_SHLIBS=		no
CRYPTO=			yes

MOZ_NAME=		MozillaFirebird-linux
WRKSRC=			${WRKDIR}/${WRKNAME}
NS_PLUGINS_DIR=		${PREFIX}/lib/${MOZ_NAME}/plugins

PLIST_SUBST+=		MOZ_NAME="${MOZ_NAME}"

do-install:
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/flashplayer.xpt ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/libflashplayer.so ${NS_PLUGINS_DIR}

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"

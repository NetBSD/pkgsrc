# $NetBSD: Makefile,v 1.8 2009/04/09 00:48:18 joerg Exp $

DISTNAME= 		firefox-bin-realplayer-1.0
PKGREVISION=		4
CATEGORIES=		www audio graphics
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		kei@NetBSD.org
COMMENT=		RealAudio and RealVideo player plugin for firefox-bin

DEPENDS+=		firefox-bin>=0.8:../../www/firefox-bin
DEPENDS+=		RealPlayerGold-[0-9]*:../../multimedia/RealPlayerGold

EMUL_PLATFORMS=		linux-i386

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty

NS_PLUGINS_DIR=		${PREFIX}/lib/firefox-linux/plugins
PLUGIN_SOURCE=		${PREFIX}/lib/RealPlayer/mozilla/nphelix.so

do-install:
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${LN} -s ${PLUGIN_SOURCE} ${NS_PLUGINS_DIR}/nphelix.so

.include "../../mk/bsd.pkg.mk"

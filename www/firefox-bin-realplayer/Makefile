# $NetBSD: Makefile,v 1.10 2011/03/17 11:38:42 obache Exp $

DISTNAME= 		firefox-bin-realplayer-1.0
PKGREVISION=		4
CATEGORIES=		www audio graphics
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		RealAudio and RealVideo player plugin for firefox-bin

DEPENDS+=		firefox-bin>=0.8:../../www/firefox-bin
DEPENDS+=		RealPlayerGold-[0-9]*:../../multimedia/RealPlayerGold

PKG_DESTDIR_SUPPORT=	user-destdir

EMUL_PLATFORMS=		linux-i386

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty

NS_PLUGINS_DIR=		${PREFIX}/lib/firefox-linux/plugins
PLUGIN_SOURCE=		${PREFIX}/lib/RealPlayer/mozilla/nphelix.so

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${NS_PLUGINS_DIR}
	${LN} -s ${PLUGIN_SOURCE} ${DESTDIR}${NS_PLUGINS_DIR}/nphelix.so

.include "../../mk/bsd.pkg.mk"

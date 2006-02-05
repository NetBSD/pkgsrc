# $NetBSD: Makefile,v 1.5 2006/02/05 23:11:21 joerg Exp $

DISTNAME= 		firefox-bin-realplayer-1.0
PKGREVISION=		3
CATEGORIES=		www audio graphics
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		kei@NetBSD.org
COMMENT=		RealAudio and RealVideo player plugin for firefox-bin

DEPENDS+=		firefox-bin>=0.8:../../www/firefox-bin
DEPENDS+=		RealPlayerGold-[0-9]*:../../multimedia/RealPlayerGold

ONLY_FOR_PLATFORM=	*-*-i386

WRKSRC=			${WRKDIR}
NO_CHECKSUM=		YES
NO_CONFIGURE=		YES
NO_BUILD=		YES

NS_PLUGINS_DIR=		${PREFIX}/lib/firefox-linux/plugins
PLUGIN_SOURCE=		${PREFIX}/lib/netscape/plugins/rpnp.so

do-install:
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${LN} -s ${PLUGIN_SOURCE} ${NS_PLUGINS_DIR}/rpnp.so

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1 2004/02/10 12:58:19 grant Exp $

DISTNAME= 		firefox-bin-realplayer-1.0
PKGREVISION=		1
CATEGORIES=		www audio graphics
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		kei@NetBSD.org
COMMENT=		RealAudio and RealVideo player plugin for firefox-bin

DEPENDS+=		firefox-bin>=0.8:../../www/firefox-bin
DEPENDS+=		realplayer-[0-9]*:../../multimedia/realplayer

ONLY_FOR_PLATFORM=	NetBSD-*-i386

WRKSRC=			${WRKDIR}
NO_CHECKSUM=		YES
NO_CONFIGURE=		YES
NO_BUILD=		YES

NS_PLUGINS_DIR=		${PREFIX}/lib/firefox-linux/plugins
PLUGIN_SOURCE=		${PREFIX}/lib/netscape/plugins/rpnp.so

do-install:
	${LN} -s ${PLUGIN_SOURCE} ${NS_PLUGINS_DIR}/rpnp.so

.include "../../mk/bsd.pkg.mk"

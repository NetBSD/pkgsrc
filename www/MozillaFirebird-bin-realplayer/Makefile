# $NetBSD: Makefile,v 1.3 2003/10/29 22:24:09 xtraeme Exp $

DISTNAME= 		MozillaFirebird-bin-realplayer-1.0
WRKSRC=			${WRKDIR}
PKGREVISION=		1
CATEGORIES=		www audio graphics
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		kei@NetBSD.org
COMMENT=		RealAudio and RealVideo player plugin for MozillaFirebird-bin

DEPENDS+=		MozillaFirebird-bin>=0.6.1:../../www/MozillaFirebird-bin
DEPENDS+=		realplayer-[0-9]*:../../audio/realplayer

# this package was previously called "phoenix-bin-realplayer"
CONFLICTS+=		phoenix-bin-realplayer-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-*-i386

NO_CHECKSUM=		YES
NO_CONFIGURE=		YES
NO_BUILD=		YES

NS_PLUGINS_DIR=		${PREFIX}/lib/MozillaFirebird-linux/plugins
PLUGIN_SOURCE=		${PREFIX}/lib/netscape/plugins/rpnp.so

do-install:
	${LN} -s ${PLUGIN_SOURCE} ${NS_PLUGINS_DIR}/rpnp.so

.include "../../mk/bsd.pkg.mk"

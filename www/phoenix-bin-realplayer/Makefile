# $NetBSD: Makefile,v 1.4 2003/08/08 18:18:05 jmc Exp $

DISTNAME= 		phoenix-bin-realplayer-1.0
PKGREVISION=		1
WRKSRC=			${WRKDIR}
CATEGORIES=		www audio graphics
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		kei@NetBSD.org
COMMENT=		RealAudio and RealVideo player plugin for phoenix-bin

DEPENDS+=		phoenix-bin>=0.6:../../www/phoenix-bin
DEPENDS+=		realplayer-[0-9]*:../../audio/realplayer

ONLY_FOR_PLATFORM=	NetBSD-*-i386

NO_CHECKSUM=		YES
NO_CONFIGURE=		YES
NO_BUILD=		YES

NS_PLUGINS_DIR=		${PREFIX}/lib/MozillaFirebird-linux/plugins
PLUGIN_SOURCE=		${PREFIX}/lib/netscape/plugins/rpnp.so

do-install:
	${LN} -s ${PLUGIN_SOURCE}/rpnp.so ${NS_PLUGINS_DIR}/rpnp.so

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.3 2003/07/17 22:55:57 grant Exp $

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

do-install:
			${LN} -s ${PREFIX}/lib/netscape/plugins/rpnp.so \
				${PREFIX}/lib/MozillaFirebird-linux/plugins/rpnp.so

.include "../../mk/bsd.pkg.mk"

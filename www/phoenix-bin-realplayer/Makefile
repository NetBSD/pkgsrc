# $NetBSD: Makefile,v 1.1.1.1 2003/04/29 13:41:08 kei Exp $

DISTNAME= 		phoenix-bin-realplayer-1.0
WRKSRC=			${WRKDIR}
CATEGORIES=		www audio graphics
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		kei@netbsd.org
COMMENT=		RealAudio and RealVideo player plugin for phoenix-bin

DEPENDS+=		phoenix-bin-[0-9]*:../../www/phoenix-bin
DEPENDS+=		realplayer-[0-9]*:../../audio/realplayer

ONLY_FOR_PLATFORM=	NetBSD-*-i386

NO_CHECKSUM=		YES
NO_CONFIGURE=		YES
NO_BUILD=		YES

do-install:
			${LN} -s ${PREFIX}/lib/netscape/plugins/rpnp.so \
				${PREFIX}/lib/phoenix-linux/plugins/rpnp.so

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.2 1998/06/22 13:14:31 agc Exp $

DISTNAME=	wwwoffle-2.1c
CATEGORIES=	www
MASTER_SITES=	http://www.gedanken.demon.co.uk/wwwoffle/version-2.1/
EXTRACT_SUFX=	.tgz

MAINTAINER=	magick@bundy.lip.owl.de

USE_GMAKE=	yes
NO_CONFIGURE=	yes

post-build:
	${SED} s#@PREFIX@#${PREFIX}#g <${FILESDIR}/wwwoffle.sh \
	  >${WRKDIR}/wwwoffle.sh

pre-install:
	${MKDIR} ${PREFIX}/etc/wwwoffle

post-install:
	${CP} ${PREFIX}/etc/wwwoffle/wwwoffle.conf \
	  ${PREFIX}/etc/wwwoffle/wwwoffle.conf.default
	${INSTALL_SCRIPT} ${WRKDIR}/wwwoffle.sh ${PREFIX}/etc/rc.d

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1 1998/06/06 17:03:58 tron Exp $

DISTNAME=	wwwoffle-2.1c
CATEGORIES=	www
MASTER_SITES=	http://www.gedanken.demon.co.uk/wwwoffle/version-2.1/
EXTRACT_SUFX=	.tgz

MAINTAINER=	magick@bundy.lip.owl.de

USE_GMAKE=	yes
NO_CONFIGURE=	yes

MAN1=	wwwoffle.1
MAN5=	wwwoffle.conf.5
MAN8=	wwwoffled.8

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

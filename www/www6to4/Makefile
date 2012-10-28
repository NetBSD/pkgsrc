# $NetBSD: Makefile,v 1.14 2012/10/28 06:31:09 asau Exp $
#

DISTNAME=	www6to4-1.6
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/Vermicelli/

MAINTAINER=	feico@pasta.cs.uit.no
HOMEPAGE=	http://www.vermicelli.pasta.cs.uit.no/ipv6/software.html
COMMENT=	Lightweight http proxy, helps IPv4 only browsers

USE_FEATURES+=		inet6

BUILD_TARGET=	# empty

WRKSRC=		${WRKDIR}/www6to4-1-6

INSTALLATION_DIRS=	sbin share/examples/www6to4

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/www6to4 ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/www6to4.conf \
		${DESTDIR}${PREFIX}/share/examples/www6to4
	${INSTALL_DATA} ${WRKSRC}/www6to4_forward.conf \
		${DESTDIR}${PREFIX}/share/examples/www6to4

.include "../../mk/bsd.pkg.mk"

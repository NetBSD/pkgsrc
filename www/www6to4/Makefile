# $NetBSD: Makefile,v 1.7 2004/12/03 15:15:12 wiz Exp $
#

DISTNAME=	www6to4-1.5
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/Vermicelli/

MAINTAINER=	feico@pasta.cs.uit.no
HOMEPAGE=	http://www.vermicelli.pasta.cs.uit.no/ipv6/software.html
COMMENT=	Lightweight http proxy, helps IPv4 only browsers

BUILD_TARGET=	# empty

.include "../../mk/bsd.prefs.mk"
# always IPv6 ready
BUILD_DEFS+=	USE_INET6

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/www6to4
	${INSTALL_PROGRAM} ${WRKSRC}/www6to4 ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/www6to4.conf \
		${PREFIX}/share/examples/www6to4
	${INSTALL_DATA} ${WRKSRC}/www6to4_forward.conf \
		${PREFIX}/share/examples/www6to4

.include "../../mk/bsd.pkg.mk"

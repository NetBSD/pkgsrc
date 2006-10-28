# $NetBSD: Makefile,v 1.11 2006/10/28 03:00:35 obache Exp $
#

DISTNAME=	www6to4-1.6
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/Vermicelli/

MAINTAINER=	feico@pasta.cs.uit.no
HOMEPAGE=	http://www.vermicelli.pasta.cs.uit.no/ipv6/software.html
COMMENT=	Lightweight http proxy, helps IPv4 only browsers

BUILD_TARGET=	# empty

WRKSRC=		${WRKDIR}/www6to4-1-6

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/www6to4
	${INSTALL_PROGRAM} ${WRKSRC}/www6to4 ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/www6to4.conf \
		${PREFIX}/share/examples/www6to4
	${INSTALL_DATA} ${WRKSRC}/www6to4_forward.conf \
		${PREFIX}/share/examples/www6to4

PKG_OPTIONS_VAR=		PKG_OPTIONS.www6to4
PKG_OPTIONS_REQUIRED_GROUPS=	inet6 # require inet6 capability
PKG_OPTIONS_GROUP.inet6=	inet6

.include "../../mk/bsd.options.mk"
.include "../../mk/bsd.pkg.mk"

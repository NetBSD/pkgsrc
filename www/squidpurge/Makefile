# $NetBSD: Makefile,v 1.3 2005/10/11 14:11:27 gdt Exp $
#

DISTNAME=	purge-${PURGEVERSION}-src
PKGNAME=	squidpurge-0.${PURGEVERSION}
CATEGORIES=	www
MASTER_SITES=	http://www.wa.apana.org.au/~dean/sources/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.wa.apana.org.au/~dean/squidpurge/
COMMENT=	Squid cache tool to list, extract or purge objects

PURGEVERSION=	20040201

WRKSRC=		${WRKDIR}/purge

USE_TOOLS+=	gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/purge ${PREFIX}/bin/squidpurge
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/squidpurge
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/squidpurge

.include "../../mk/bsd.pkg.mk"

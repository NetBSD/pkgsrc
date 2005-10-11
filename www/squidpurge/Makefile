# $NetBSD: Makefile,v 1.1.1.1 2005/10/11 00:45:39 gdt Exp $
#

DISTNAME=		purge-${PURGEVERSION}-src
PKGNAME=		squidpurge-${PURGEVERSION}
CATEGORIES=		www
MASTER_SITES=		http://www.wa.apana.org.au/~dean/sources/

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://www.wa.apana.org.au/~dean/sources/
COMMENT=		Squid cache tool to list, extract or purge objects

PURGEVERSION=		20040201

WRKSRC=			${WRKDIR}/purge

USE_TOOLS+=	gmake

do-install:
	${INSTALL} ${WRKSRC}/purge ${LOCALBASE}/bin/squidpurge
	${INSTALL} ${WRKSRC}/README ${LOCALBASE}/share/doc/squidpurge

.include "../../mk/bsd.pkg.mk"

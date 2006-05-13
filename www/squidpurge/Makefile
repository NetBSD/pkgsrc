# $NetBSD: Makefile,v 1.5 2006/05/13 14:12:31 gdt Exp $
#

DISTNAME=	purge-${PURGEVERSION}-src
PKGNAME=	squidpurge-0.${PURGEVERSION}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.wa.apana.org.au/~dean/sources/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.wa.apana.org.au/~dean/squidpurge/
COMMENT=	Squid cache tool to list, extract or purge objects

PURGEVERSION=	20040201

WRKSRC=		${WRKDIR}/purge

USE_TOOLS+=	gmake
USE_LANGUAGES+=	c++

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/purge ${PREFIX}/bin/squidpurge
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/squidpurge
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/squidpurge

.include "../../mk/bsd.pkg.mk"

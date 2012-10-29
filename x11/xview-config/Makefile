# $NetBSD: Makefile,v 1.32 2012/10/29 05:07:24 asau Exp $

DISTNAME=		xview3.2p1-X11R6
PKGNAME=		xview-config-3.2.1
PKGREVISION=		6
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

OWNER=			dholland@NetBSD.org
COMMENT=		OpenLook Toolkit config files
LICENSE=		sun-openlook-license

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

EXTRACT_ELEMENTS=	${DISTNAME}/config

WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}
USE_IMAKE=		yes

post-extract:
	${CHMOD} -R go+rX ${WRKSRC}

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.24 2006/03/04 21:31:14 jlam Exp $

DISTNAME=		xview3.2p1-X11R6
PKGNAME=		xview-config-3.2.1
PKGREVISION=		3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		OpenLook Toolkit config files

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

EXTRACT_ELEMENTS=	${DISTNAME}/config

WRKSRC=      		${WRKDIR}/${EXTRACT_ELEMENTS}
USE_IMAKE=		yes

post-extract:
	@${CHMOD} -R go+rX ${WRKDIR}

.include "../../mk/bsd.pkg.mk"

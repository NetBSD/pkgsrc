# $NetBSD: Makefile,v 1.17 2004/01/20 12:28:29 agc Exp $
# $FreeBSD Id: Makefile,v 1.9 1998/05/04 03:34:50 steve Exp
#

DISTNAME=		xview3.2p1-X11R6
PKGNAME=		xview-config-3.2.1
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		jlam@NetBSD.org
COMMENT=		OpenLook Toolkit config files

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

EXTRACT_ELEMENTS=	${DISTNAME}/config

WRKSRC=      		${WRKDIR}/${EXTRACT_ELEMENTS}
USE_BUILDLINK2=		# defined
USE_IMAKE=		# defined

post-extract:
	@${CHMOD} -R go+rX ${WRKDIR}

.include "../../mk/bsd.pkg.mk"

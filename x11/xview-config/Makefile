# $NetBSD: Makefile,v 1.20 2005/03/24 21:13:04 wiz Exp $

DISTNAME=		xview3.2p1-X11R6
PKGNAME=		xview-config-3.2.1
PKGREVISION=		2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		OpenLook Toolkit config files

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

EXTRACT_ELEMENTS=	${DISTNAME}/config

WRKSRC=      		${WRKDIR}/${EXTRACT_ELEMENTS}
USE_BUILDLINK3=		yes
USE_IMAKE=		# defined

post-extract:
	@${CHMOD} -R go+rX ${WRKDIR}

.include "../../mk/bsd.pkg.mk"

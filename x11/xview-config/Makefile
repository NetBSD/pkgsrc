# $NetBSD: Makefile,v 1.11 2000/10/23 18:02:54 jlam Exp $
# $FreeBSD Id: Makefile,v 1.9 1998/05/04 03:34:50 steve Exp
#

DISTNAME=		xview3.2p1-X11R6
PKGNAME=		xview-config-3.2.1nb2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		jlam@netbsd.org

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

EXTRACT_ELEMENTS=	${DISTNAME}/config
WRKSRC=      		${WRKDIR}/${EXTRACT_ELEMENTS}
USE_IMAKE=		# defined

post-extract:
	@${CHMOD} -R go+rX ${WRKDIR}

.include "../../mk/bsd.pkg.mk"

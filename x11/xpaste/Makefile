# $NetBSD: Makefile,v 1.1.1.1 2001/04/16 20:21:01 zuntum Exp $
#

DISTNAME=	xpaste-1.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=utilities/}
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	seb@pbox.org
COMMENT=	Display the content of the X11 paste buffer in a window

EXTRACT_CMD=	${GZCAT} ${DOWNLOADED_DISTFILE} | ${SH}

USE_IMAKE=	yes

WRKSRC=		${WRKDIR}

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.4 2001/09/09 20:36:51 agc Exp $
# FreeBSD Id: Makefile,v 1.4 1997/05/28 06:18:20 fenner Exp
#

DISTNAME=		9wm-1.1
CATEGORIES=		plan9 wm
MASTER_SITES=		ftp://ftp.freefriends.org/arnold/Source/
EXTRACT_SUFX=		.shar.gz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://dhog.g7.org/dhog/9wm.html
COMMENT=		8 1/2-like Window Manager for X

WRKSRC=			${WRKDIR}
EXTRACT_CMD=		${GZCAT} ${DOWNLOADED_DISTFILE} | ${SH}
USE_IMAKE=		yes

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.3 2000/08/05 18:01:18 jlam Exp $
#

DISTNAME=	surfraw-0.5.5
CATEGORIES=	www
MASTER_SITES=	http://download.sourceforge.net/surfraw/
DISTFILES=	${DISTNAME}-1${EXTRACT_SUFX}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://surfraw.sourceforge.net/

CONFLICTS+=	surfaw-*

GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/surfraw
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/surfraw

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.5 2000/08/12 12:16:03 proff Exp $
#

DISTNAME=	surfraw-0.5.7
CATEGORIES=	www
MASTER_SITES=	http://download.sourceforge.net/surfraw/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://surfraw.sourceforge.net/

CONFLICTS+=	surfaw-*

GNU_CONFIGURE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/surfraw
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/surfraw

.include "../../mk/bsd.pkg.mk"

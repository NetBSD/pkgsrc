# $NetBSD: Makefile,v 1.6 2000/10/31 13:10:18 jlam Exp $
#

DISTNAME=	surfraw-1.0.2
CATEGORIES=	www
MASTER_SITES=	http://download.sourceforge.net/surfraw/

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://surfraw.sourceforge.net/

CONFLICTS+=	surfaw-*

GNU_CONFIGURE=	# defined

DOCDIR=		${PREFIX}/share/doc/surfraw

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"

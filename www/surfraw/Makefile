# $NetBSD: Makefile,v 1.2 2000/08/05 08:22:36 proff Exp $
#

DISTNAME=	surfraw-0.5.5
CATEGORIES=	www
MASTER_SITES=	http://download.sourceforge.net/surfraw/
DISTFILES=	surfraw-0.5.5-1.tar.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://surfraw.sourceforge.net/

GNU_CONFIGURE=	yes

post-install:
        ${INSTALL_DATA_DIR} ${PREFIX}/share/doc/surfraw
        ${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/surfraw

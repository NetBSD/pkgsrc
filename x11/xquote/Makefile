# $NetBSD: Makefile,v 1.4 2000/04/17 16:55:25 fredb Exp $

DISTNAME=		xquote-2.1
CATEGORIES=		x11
MASTER_SITES=		http://www.sunsite.auc.dk/xinvest/ \
			${MASTER_SITE_XCONTRIB:=applications/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://sunsite.auc.dk/xinvest/xquote.html

DEPENDS+=		xpm-3.4k:../../graphics/xpm

USE_IMAKE=		yes
USE_MOTIF=		yes
NO_INSTALL_MANPAGES=	yes

post-patch:
	${TOUCH} ${WRKSRC}/Xquote.man

.include "../../mk/bsd.pkg.mk"

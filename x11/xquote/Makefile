# $NetBSD: Makefile,v 1.2 1999/04/15 20:39:50 tron Exp $

DISTNAME=		xquote-1.1
CATEGORIES=		x11
MASTER_SITES=		http://www.sunsite.auc.dk/xinvest/ \
			${MASTER_SITE_XCONTRIB:=applications/}
DISTFILES=		${DISTNAME}.tar.gz Xquote.ad

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://sunsite.auc.dk/xinvest/xquote.html

DEPENDS+=		xpm-3.4k:../../graphics/xpm

USE_IMAKE=		yes
USE_MOTIF=		yes
NO_INSTALL_MANPAGES=	yes

post-patch:
	${TOUCH} ${WRKSRC}/Xquote.man

post-install:
	${INSTALL_DATA} ${DISTDIR}/Xquote.ad ${X11BASE}/lib/X11/app-defaults/Xquote

.include "../../mk/bsd.pkg.mk"

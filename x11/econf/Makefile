# $NetBSD: Makefile,v 1.1.1.1 1999/04/01 05:44:59 garbled Exp $

DISTNAME=		enlightenment-conf-0.15
PKGNAME=		econf-0.15
CATEGORIES=		x11
MASTER_SITES=		ftp://www.rasterman.com/pub/enlightenment/enlightenment/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.enlightenment.org/

DEPENDS+=		controlcenter-1.04:../../x11/controlcenter

WRKSRC=			${WRKDIR}/${DISTNAME}

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_X11=		yes
USE_X11BASE=		yes

.include "../../mk/bsd.pkg.mk"

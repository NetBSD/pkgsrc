# $NetBSD: Makefile,v 1.4 1999/08/30 09:13:02 jlam Exp $

DISTNAME=		enlightenment-conf-0.15
PKGNAME=		econf-0.15
CATEGORIES=		x11
MASTER_SITES=		ftp://www.rasterman.com/pub/enlightenment/enlightenment/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.enlightenment.org/

DEPENDS+=		control-center-1.0.6:../../x11/controlcenter

WRKSRC=			${WRKDIR}/${DISTNAME}

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_X11=		yes
USE_X11BASE=		yes

.include "../../mk/bsd.pkg.mk"

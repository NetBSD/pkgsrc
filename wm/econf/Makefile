# $NetBSD: Makefile,v 1.2 2001/02/17 17:21:33 wiz Exp $
#

DISTNAME=		enlightenment-conf-0.15
PKGNAME=		econf-0.15
CATEGORIES=		x11 wm
MASTER_SITES=		ftp://www.rasterman.com/pub/enlightenment/enlightenment/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.enlightenment.org/
COMMENT=		configuration tool for easily setting up Enlightenment

DEPENDS+=		control-center-*:../../x11/controlcenter

WRKSRC=			${WRKDIR}/${DISTNAME}

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_X11=		yes
USE_X11BASE=		yes

.include "../../mk/bsd.pkg.mk"

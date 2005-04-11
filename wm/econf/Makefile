# $NetBSD: Makefile,v 1.19 2005/04/11 21:47:47 tv Exp $
#

DISTNAME=		enlightenment-conf-0.15
PKGNAME=		econf-0.15
PKGREVISION=		7
CATEGORIES=		x11 wm
MASTER_SITES=		ftp://www.rasterman.com/pub/enlightenment/enlightenment/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.enlightenment.org/
COMMENT=		Configuration tool for easily setting up Enlightenment

USE_LANGUAGES=		c c++
USE_X11=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../x11/controlcenter/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.18 2004/11/30 18:26:40 wiz Exp $
#

DISTNAME=		enlightenment-conf-0.15
PKGNAME=		econf-0.15
PKGREVISION=		7
CATEGORIES=		x11 wm
MASTER_SITES=		ftp://www.rasterman.com/pub/enlightenment/enlightenment/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.enlightenment.org/
COMMENT=		Configuration tool for easily setting up Enlightenment

USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++
USE_X11=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../x11/controlcenter/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

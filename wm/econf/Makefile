# $NetBSD: Makefile,v 1.14 2004/01/24 15:18:32 grant Exp $
#

DISTNAME=		enlightenment-conf-0.15
PKGNAME=		econf-0.15
PKGREVISION=		5
CATEGORIES=		x11 wm
MASTER_SITES=		ftp://www.rasterman.com/pub/enlightenment/enlightenment/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.enlightenment.org/
COMMENT=		Configuration tool for easily setting up Enlightenment

USE_BUILDLINK2=		yes
USE_X11=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../x11/controlcenter/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.7 2003/04/27 12:38:51 cjep Exp $
#

DISTNAME=		enlightenment-conf-0.15
PKGNAME=		econf-0.15
PKGREVISION=		1
CATEGORIES=		x11 wm
MASTER_SITES=		ftp://www.rasterman.com/pub/enlightenment/enlightenment/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.enlightenment.org/
COMMENT=		configuration tool for easily setting up Enlightenment

USE_BUILDLINK2=		yes
USE_X11=		yes
USE_GMAKE=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../x11/controlcenter/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

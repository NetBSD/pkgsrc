# $NetBSD: Makefile,v 1.9 2005/06/01 18:03:29 jlam Exp $
#

DISTNAME=	imwheel-0.9.9
CATEGORIES=	x11
MASTER_SITES=	http://jonatkins.org/imwheel/files/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://jcatki.dhs.org/imwheel/
COMMENT=	Tool which helps to use mousewheels

USE_X11BASE=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-gpm

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.7 2004/04/21 04:30:39 snj Exp $
#

DISTNAME=	imwheel-0.9.9
CATEGORIES=	x11
MASTER_SITES=	http://jonatkins.org/imwheel/files/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://jcatki.dhs.org/imwheel/
COMMENT=	Tool which helps to use mousewheels

USE_BUILDLINK3=		YES
USE_X11BASE=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-gpm

.include "../../mk/bsd.pkg.mk"

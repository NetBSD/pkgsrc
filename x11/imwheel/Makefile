# $NetBSD: Makefile,v 1.6 2003/07/21 17:38:29 martti Exp $
#

DISTNAME=	imwheel-0.9.9
CATEGORIES=	x11
MASTER_SITES=	http://jonatkins.org/imwheel/files/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://jcatki.dhs.org/imwheel/
COMMENT=	Tool which helps to use mousewheels

USE_BUILDLINK2=		YES
USE_X11BASE=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-gpm

.include "../../mk/bsd.pkg.mk"

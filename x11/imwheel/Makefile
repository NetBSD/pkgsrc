# $NetBSD: Makefile,v 1.3 2001/08/29 22:41:29 jlam Exp $
#

DISTNAME=	imwheel-0.9.9
CATEGORIES=	x11
MASTER_SITES=	http://jonatkins.org/imwheel/files/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://jcatki.dhs.org/imwheel/
COMMENT=	tool which helps to use mousewheels

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_X11BASE=		YES

CONFIGURE_ARGS+=	--disable-gpm

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.4 2002/08/25 21:52:39 jlam Exp $
#

DISTNAME=	imwheel-0.9.9
CATEGORIES=	x11
MASTER_SITES=	http://jonatkins.org/imwheel/files/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://jcatki.dhs.org/imwheel/
COMMENT=	tool which helps to use mousewheels

USE_BUILDLINK2=		YES
USE_X11BASE=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-gpm

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.4 2003/07/17 22:56:58 grant Exp $
#

DISTNAME=	xkbd-0.8.5
CATEGORIES=	x11
MASTER_SITES=	http://handhelds.org/~mallum/downloadables/xkbd/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://handhelds.org/~mallum/
COMMENT=	On-screen keyboard for X, useful for palmtops

CONFIGURE_ARGS+=--enable-xpm

USE_BUILDLINK2=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.5 2004/04/24 00:45:58 snj Exp $
#

DISTNAME=	xkbd-0.8.5
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://handhelds.org/~mallum/downloadables/xkbd/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://handhelds.org/~mallum/
COMMENT=	On-screen keyboard for X, useful for palmtops

CONFIGURE_ARGS+=--enable-xpm

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_X11=	YES

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

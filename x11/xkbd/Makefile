# $NetBSD: Makefile,v 1.3 2003/02/05 21:58:05 dmcmahill Exp $
#

DISTNAME=	xkbd-0.8.5
CATEGORIES=	x11
MASTER_SITES=	http://handhelds.org/~mallum/downloadables/xkbd/

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://handhelds.org/~mallum/
COMMENT=	On-screen keyboard for X, useful for palmtops

CONFIGURE_ARGS+=--enable-xpm

USE_BUILDLINK2=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

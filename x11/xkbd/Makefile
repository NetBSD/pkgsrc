# $NetBSD: Makefile,v 1.2 2003/01/10 17:49:15 tsarna Exp $
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

.include "../../mk/bsd.pkg.mk"

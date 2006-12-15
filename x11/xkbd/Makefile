# $NetBSD: Makefile,v 1.9 2006/12/15 20:33:06 joerg Exp $
#

DISTNAME=	xkbd-0.8.5
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://handhelds.org/~mallum/downloadables/xkbd/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://handhelds.org/~mallum/
COMMENT=	On-screen keyboard for X, useful for palmtops

CONFIGURE_ARGS+=--enable-xpm

GNU_CONFIGURE=	YES

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.6 2006/12/15 20:33:01 joerg Exp $
#

DISTNAME=	cwm-3
PKGREVISION=	2
CATEGORIES=	wm
MASTER_SITES=	http://monkey.org/~marius/cwm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://monkey.org/~marius/cwm/
COMMENT=	Window manager for X11 initially inspired by evilwm

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

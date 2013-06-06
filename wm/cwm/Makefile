# $NetBSD: Makefile,v 1.16 2013/06/06 12:55:08 wiz Exp $
#

DISTNAME=	cwm-3
PKGREVISION=	6
CATEGORIES=	wm
MASTER_SITES=	http://monkey.org/~marius/cwm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://monkey.org/~marius/cwm/
COMMENT=	Window manager for X11 initially inspired by evilwm

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

LDFLAGS.DragonFly+=	-lfontconfig
LDFLAGS.SunOS+=		-lfontconfig

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.18 2017/08/01 14:59:06 wiz Exp $
#

DISTNAME=	cwm-3
PKGREVISION=	6
CATEGORIES=	wm
MASTER_SITES=	https://monkey.org/~marius/cwm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://monkey.org/~marius/cwm/
COMMENT=	Window manager for X11 initially inspired by evilwm

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

LDFLAGS.Darwin+=	-lfontconfig
LDFLAGS.DragonFly+=	-lfontconfig
LDFLAGS.SunOS+=		-lfontconfig

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

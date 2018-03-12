# $NetBSD: Makefile,v 1.19 2018/03/12 11:17:42 wiz Exp $
#

DISTNAME=	cwm-3
PKGREVISION=	7
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

# $NetBSD: Makefile,v 1.8 2012/10/29 05:07:10 asau Exp $
#

DISTNAME=	xfd-1.0.1
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Display all the characters in an X font

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1
MAKE_FLAGS+=		appdefaultdir=${PREFIX}/lib/X11/app-defaults

LDFLAGS.DragonFly+=	-lXmu -lXrender

.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

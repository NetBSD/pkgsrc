# $NetBSD: Makefile,v 1.4 2013/01/21 13:17:47 wiz Exp $
#

DISTNAME=		viewres-1.0.4
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Display widget class hierarchy of the Athena Widget Set
#LICENSE=		mit

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

#CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

MAKE_FLAGS+=		appdefaultdir=${PREFIX}/lib/X11/app-defaults

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

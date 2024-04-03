# $NetBSD: Makefile,v 1.22 2024/04/03 21:20:18 wiz Exp $

DISTNAME=		xman-1.2.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Manual page browser

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

CONFIGURE_ARGS.NetBSD+=	--with-manconfig=/etc/man.conf

MAKE_FLAGS+=		appdefaultdir=${PREFIX}/lib/X11/app-defaults

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

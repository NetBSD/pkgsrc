# $NetBSD: Makefile,v 1.13 2024/03/03 23:11:30 wiz Exp $

DISTNAME=		xfontsel-1.1.1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		X font selector

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

MAKE_FLAGS+=		appdefaultdir=${PREFIX}/lib/X11/app-defaults

.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

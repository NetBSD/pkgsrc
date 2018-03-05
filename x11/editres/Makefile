# $NetBSD: Makefile,v 1.9 2018/03/05 09:25:54 wiz Exp $

DISTNAME=		editres-1.0.7
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Dynamic resource editor for libXt applications

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

MAKE_FLAGS+=		appdefaultdir=${PREFIX}/lib/X11/app-defaults

.include "../../x11/libXaw/buildlink3.mk"
BUILDLINK_API_DEPENDS.libXt+=	libXt>=1.0.99.1
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

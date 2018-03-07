# $NetBSD: Makefile,v 1.9 2018/03/07 11:57:39 wiz Exp $

DISTNAME=		rgb-1.0.6
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		RGB color database

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		APP_MAN_SUFFIX=1

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

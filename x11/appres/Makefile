# $NetBSD: Makefile,v 1.12 2024/06/16 19:02:47 wiz Exp $

DISTNAME=		appres-1.0.7
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Print resources seen by an application

USE_TOOLS+=		pkg-config

.include "../../devel/meson/build.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

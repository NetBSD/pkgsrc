# $NetBSD: Makefile,v 1.9 2022/04/03 19:03:22 wiz Exp $

DISTNAME=		appres-1.0.6
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Print resources seen by an application

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

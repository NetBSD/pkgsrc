# $NetBSD: Makefile,v 1.8 2020/01/18 23:35:47 rillig Exp $

DISTNAME=		appres-1.0.5
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Print resources seen by an application

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

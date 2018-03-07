# $NetBSD: Makefile,v 1.4 2018/03/07 11:57:48 wiz Exp $

DISTNAME=	xtrap-1.0.2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	XTrap sample clients

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

CONFIGURE_ENV+=	APP_MAN_SUFFIX=1

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libXTrap/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

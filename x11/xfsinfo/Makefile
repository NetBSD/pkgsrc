# $NetBSD: Makefile,v 1.7 2022/10/22 16:53:28 wiz Exp $

DISTNAME=	xfsinfo-1.0.7
CATEGORIES=	x11 fonts
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Utility for displaying information about an X font server
LICENSE=	x11 # AND others

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libFS/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

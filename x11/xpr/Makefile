# $NetBSD: Makefile,v 1.7 2024/03/03 23:13:56 wiz Exp $

DISTNAME=	xpr-1.2.0
CATEGORIES=	x11 print
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Formats xwd dump files as output for various types of printers

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

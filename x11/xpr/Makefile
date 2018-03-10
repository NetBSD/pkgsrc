# $NetBSD: Makefile,v 1.4 2018/03/10 22:10:32 wiz Exp $

DISTNAME=	xpr-1.0.5
CATEGORIES=	print x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Formats xwd dump files as output for various types of printers

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

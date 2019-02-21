# $NetBSD: Makefile,v 1.5 2019/02/21 09:37:02 wiz Exp $

DISTNAME=	xfsinfo-1.0.6
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Utility for displaying information about an X font server
LICENSE=	x11 # AND others

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../x11/libFS/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

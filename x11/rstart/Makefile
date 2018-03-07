# $NetBSD: Makefile,v 1.3 2018/03/07 11:57:39 wiz Exp $

DISTNAME=	rstart-1.0.5
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Implements "A Flexible Remote Execution Protocol Based on rsh"

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

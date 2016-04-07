# $NetBSD: Makefile,v 1.11 2016/04/07 13:21:38 tnn Exp $

DISTNAME=	sessreg-1.1.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Manage utmp/wtmp entries for xdm

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes

BUILD_DEFS+=	VARBASE
CONFIGURE_ARGS+=--localstatedir=${VARBASE:Q}

TOOL_DEPENDS+=	tradcpp-[0-9]*:../../devel/tradcpp
MAKE_ENV+=	RAWCPP="${PREFIX}/bin/tradcpp -Uunix"

BUILDLINK_API_DEPENDS.xproto+=	xproto>=7.0.25
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

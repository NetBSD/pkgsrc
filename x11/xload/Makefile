# $NetBSD: Makefile,v 1.21 2026/08/18 06:41:59 wiz Exp $

DISTNAME=	xload-1.2.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	System load average display for X

USE_TOOLS+=	pkg-config xgettext

MESON_ARGS+=	-Dappdefaultdir=${PREFIX}/lib/X11/app-defaults

.include "../../devel/meson/build.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

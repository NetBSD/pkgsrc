# $NetBSD: Makefile,v 1.8 2026/06/29 07:21:30 wiz Exp $

DISTNAME=	xedit-1.2.5
CATEGORIES=	x11 editors
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Simple text editor for X
#LICENSE=	modified-bsd AND x11 # XXX AND others

USE_TOOLS+=	pkg-config

MESON_ARGS+=	-Dappdefaultdir=${PREFIX}/lib/X11/app-defaults

# finite(3) was deprecated on macOS aarch64
#CFLAGS.Darwin+=	-Dfinite\(d\)=isfinite\(d\)

.include "../../devel/meson/build.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

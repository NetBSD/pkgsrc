# $NetBSD: Makefile,v 1.6 2022/04/03 22:16:01 wiz Exp $

DISTNAME=	xedit-1.2.3
CATEGORIES=	x11 editors
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Simple text editor for X
#LICENSE=	modified-bsd AND x11 # XXX AND others

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

MAKE_FLAGS+=	appdefaultdir=${PREFIX}/lib/X11/app-defaults

# finite(3) was deprecated on macOS aarch64
CFLAGS.Darwin+=	-Dfinite\(d\)=isfinite\(d\)

.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

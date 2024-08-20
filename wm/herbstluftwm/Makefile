# $NetBSD: Makefile,v 1.17 2024/08/20 06:28:22 pin Exp $

DISTNAME=	herbstluftwm-0.9.5
PKGREVISION=	3
CATEGORIES=	wm
MASTER_SITES=	https://herbstluftwm.org/tarballs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://herbstluftwm.org/
COMMENT=	Manual tiling window manager for X11 using Xlib and Glib
LICENSE=	modified-bsd

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

USE_TOOLS+=	pkg-config bash:run
USE_LANGUAGES=	c c++

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

REPLACE_BASH+=	share/dmenu_run_hlwm

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"

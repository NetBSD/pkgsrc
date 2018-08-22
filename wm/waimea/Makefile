# $NetBSD: Makefile,v 1.57 2018/08/22 09:47:22 wiz Exp $
#

DISTNAME=	waimea-0.4.0
PKGREVISION=	32
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=waimea/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/waimea/
COMMENT=	Fast and highly customizable virtual window manager

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++03
USE_TOOLS+=	gmake perl:run pkg-config

.include "../../mk/bsd.prefs.mk"

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

.if ${X11_TYPE} != "native"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.else
.  if !exists(${X11BASE}/include/X11/extensions/Xinerama.h)
CONFIGURE_ARGS+=	--disable-xinerama
.  endif
.  if !exists(${X11BASE}/include/X11/extensions/Xrender.h)
CONFIGURE_ARGS+=	--disable-render
.  endif
.  if !exists(${X11BASE}/include/X11/extensions/shape.h)
CONFIGURE_ARGS+=	--disable-shape
.  endif
.endif

CONFIGURE_ARGS+=	--disable-randr

REPLACE_PERL= \
	data/scripts/filelist.pl \
	data/scripts/procinfo.pl \
	data/scripts/stylesdir.pl.in

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

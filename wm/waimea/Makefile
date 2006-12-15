# $NetBSD: Makefile,v 1.30 2006/12/15 20:33:02 joerg Exp $
#

DISTNAME=	waimea-0.4.0
PKGREVISION=	12
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=waimea/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/waimea/
COMMENT=	Fast and highly customizable virtual window manager

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake perl:run pkg-config

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/include/X11/extensions/Xinerama.h)
CONFIGURE_ARGS+=	--disable-xinerama
.endif

.if !exists(${X11BASE}/include/X11/extensions/Xrender.h)
CONFIGURE_ARGS+=	--disable-render
.endif

.if !exists(${X11BASE}/include/X11/extensions/shape.h)
CONFIGURE_ARGS+=	--disable-shape
.endif

CONFIGURE_ARGS+=       --disable-randr

REPLACE_PERL = \
	data/scripts/filelist.pl \
	data/scripts/procinfo.pl \
	data/scripts/stylesdir.pl.in

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

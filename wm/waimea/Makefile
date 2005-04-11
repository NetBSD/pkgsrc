# $NetBSD: Makefile,v 1.18 2005/04/11 21:47:49 tv Exp $
#

DISTNAME=	waimea-0.4.0
PKGREVISION=	9
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=waimea/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.waimea.org/
COMMENT=	Fast and highly customizable virtual window manager

GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
USE_PERL5=	run
USE_X11=	YES

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

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

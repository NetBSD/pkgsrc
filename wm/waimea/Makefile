# $NetBSD: Makefile,v 1.7 2003/08/28 20:05:23 xtraeme Exp $
#

DISTNAME=	waimea-0.4.0
PKGREVISION=	4
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=waimea/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.waimea.org/
COMMENT=	Fast and highly customizable virtual window manager

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_GMAKE=	YES
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

CONFIGURE_ARGS+=	--disable-randr

REPLACE_PERL = \
	${WRKSRC}/data/scripts/filelist.pl \
	${WRKSRC}/data/scripts/procinfo.pl \
	${WRKSRC}/data/scripts/stylesdir.pl.in

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../fonts/fontconfig/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/imlib2/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

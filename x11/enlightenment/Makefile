# $NetBSD: Makefile,v 1.13 1999/10/23 00:12:09 tron Exp $

DISTNAME=		enlightenment-0.15.4
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.enlightenment.org/pub/enlightenment/enlightenment/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.enlightenment.org/

DEPENDS+=		ImageMagick-4.2.9:../../graphics/ImageMagick
DEPENDS+=		imlib-*:../../graphics/imlib
DEPENDS+=		freetype-1.1:../../graphics/freetype
DEPENDS+=		fnlib-0.4:../../graphics/fnlib
DEPENDS+=		esound-*:../../audio/esound
DEPENDS+=		eterm-0.8.8:../../x11/eterm

USE_PERL5=		yes
USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-fsstd
USE_GMAKE=		yes
LDFLAGS+=		-L${LOCALBASE}/lib
CFLAGS+=		-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.2 1998/12/13 21:46:52 tron Exp $

DISTNAME=		enlightenment-0.14
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.enlightenment.org/pub/enlightenment/enlightenment/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.enlightenment.org/

DEPENDS+=		ImageMagick-4.1.2:../../graphics/ImageMagick
DEPENDS+=		imlib-1.8.1:../../graphics/imlib
DEPENDS+=		fnlib-0.3:../../graphics/fnlib
DEPENDS+=		esound-0.2.4:../../audio/esound
DEPENDS+=		p5-gtk-0.4:../../x11/p5-gtk

WRKSRC=			${WRKDIR}/e
USE_PERL5=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
LDFLAGS+=		-L${LOCALBASE}/lib
CFLAGS+=		-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.2 2000/05/21 11:39:43 wulf Exp $
#

DISTNAME=       bluefish-0.4
CATEGORIES=     www
MASTER_SITES=   http://bluefish.openoffice.nl/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=     wulf@ping.net.au
HOMEPAGE=       http://bluefish.openoffice.nl/

BUILD_DEPENDS+= ${LOCALBASE}/bin/msgfmt:../../devel/gettext
DEPENDS+=	gtk+-1.2.7:../../x11/gtk
DEPENDS+=	imlib-*:../../graphics/imlib
DEPENDS+=	weblint-*:../../www/weblint

MANCOMPRESSED=	yes

USE_GMAKE=      yes
GNU_CONFIGURE=  yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lz -lm -ljpeg -lungif -ltiff -lpng
CONFIGURE_ENV+=  CPPFLAGS="${CFLAGS}"

.include "../../mk/bsd.pkg.mk"

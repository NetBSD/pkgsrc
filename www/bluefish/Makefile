# $NetBSD: Makefile,v 1.1.1.1 2000/05/10 12:38:26 wulf Exp $
#

DISTNAME=       bluefish-0.4pre11
CATEGORIES=     www
MASTER_SITES=   http://bluefish.openoffice.nl/download/

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
CONFIGURE_ENV=  CPPFLAGS="${CFLAGS}"

.include "../../mk/bsd.pkg.mk"

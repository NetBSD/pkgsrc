# $NetBSD: Makefile,v 1.3 1999/01/30 23:18:54 agc Exp $
#

DISTNAME=		t1lib-0.8-beta
PKGNAME=		t1lib-0.8
CATEGORIES=		textproc x11
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	libs/graphics/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.neuroinformatik.ruhr-uni-bochum.de/ini/PEOPLE/rmz/t1lib.html

#DEPENDS+=		t1lib-0.8:../../textproc/t1lib

WRKSRC=			${WRKDIR}/T1-0.8-beta
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_X11BASE=		yes

PATCHFILES+=		${PKGSRCDIR}/textproc/t1lib/patches/patch-*
ALLFILES=		${DISTFILES}    # don't checksum shared patches

do-install:
	(cd ${WRKSRC}/lib && ${GMAKE} install)
	(cd ${WRKSRC}/xglyph && ${GMAKE} install)
	ln -s ${LOCALBASE}/share/t1lib ${X11BASE}/share/t1lib

.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.1.1.1 1998/11/05 08:28:48 garbled Exp $
#

DISTNAME=		t1lib-0.8-beta
PKGNAME=		t1libx-0.8
CATEGORIES=		textproc x11
MASTER_SITES=		#empty

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.neuroinformatik.ruhr-uni-bochum.de/ini/PEOPLE/rmz/t1lib.html

DEPENDS+=		t1lib-0.8:../../textproc/t1lib

WRKSRC=			../../textproc/t1lib/work/T1-0.8-beta
NO_CHECKSUM=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_X11=		yes

do-fetch:	#empty
do-extract:
	-@${MKDIR} ${WRKDIR}
	(cd ../../textproc/t1lib && make clean)
	(cd ../../textproc/t1lib && make patch)

pre-clean:
	(cd ../../textproc/t1lib && make clean)

do-clean:
	-@${RM} -r ${WRKDIR}

do-install:
	(cd ${WRKSRC}/lib && ${GMAKE} install)
	(cd ${WRKSRC}/xglyph && ${GMAKE} install)
	ln -s ${LOCALBASE}/share/t1lib ${X11BASE}/share/t1lib

.include "../../mk/bsd.pkg.mk"

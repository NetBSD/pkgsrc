# $NetBSD: Makefile,v 1.1.1.1 2000/07/17 09:39:05 rh Exp $
#

DISTNAME=		${PKGNAME}-i386.linux
PKGNAME=		asWedit-4.0.1
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		www
MASTER_SITES=		http://www.advasoft.com/asWedit/ \
			http://gd.tuwien.ac.at/infosys/editors/asWedit/ \
			ftp://ftp.edelweb.fr/pub/asWedit/ \
			ftp://sunsite.icm.edu.pl/pub/www/asWedit/ \
			ftp://sunsite.auc.dk/pub/infosystems/www/asWedit/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.advasoft.com/asWedit.html

DEPENDS+=		suse_linux>=6.1:../../emulators/suse_linux

ONLY_FOR_PLATFORM=	NetBSD-*-i386
NO_CDROM=		"Redistribution not permitted"
RESTRICTED=		"No re-distribution"
MIRROR_DISTFILE=	no
NO_BUILD=		yes
MESSAGE_FILE=		${WRKDIR}/MESSAGE

do-configure:
	cd ${WRKSRC} && ${CP} AsWedit AsWedit.bak && \
	${SED} -e 's:/usr/local/lib:${PREFIX}/libdata:g' \
	       -e 's:^!!\*helpDir:*helpDir:' \
			< AsWedit.bak > AsWedit
	${SED} -e 's:@@PREFIX@@:${PREFIX}:g' \
			< ${PKGDIR}/MESSAGE > ${WRKDIR}/MESSAGE

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asWedit ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/asWedit.hlp ${PREFIX}/libdata
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/asWedit
	${INSTALL_DATA} ${WRKSRC}/AsWedit ${PREFIX}/share/examples/asWedit
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/asWedit
.for docs in INSTALL LICENSE ORDERING README
	${INSTALL_DATA} ${WRKSRC}/${docs} ${PREFIX}/share/doc/asWedit
.endfor

.include "../../mk/bsd.pkg.mk"

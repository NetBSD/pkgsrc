# $NetBSD: Makefile,v 1.8 2002/04/04 12:29:50 tron Exp $

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
COMMENT=		Motif HTML and text editor

DEPENDS+=		suse_libc5>=6.1:../../emulators/${SUSE_DIR_PREFIX}_libc5

ONLY_FOR_PLATFORM=	NetBSD-*-i386

RESTRICTED=		"No re-distribution"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

NO_BUILD=		yes

CHECK_SHLIBS=		no

do-configure:
	cd ${WRKSRC} && ${CP} AsWedit AsWedit.bak && \
	${SED} -e 's:/usr/local/lib:${PREFIX}/libdata:g' \
	       -e 's:^!!\*helpDir:*helpDir:' \
			< AsWedit.bak > AsWedit

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/asWedit ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/asWedit.hlp ${PREFIX}/libdata
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/asWedit
	${INSTALL_DATA} ${WRKSRC}/AsWedit ${PREFIX}/share/examples/asWedit
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/asWedit
.for docs in INSTALL LICENSE ORDERING README
	${INSTALL_DATA} ${WRKSRC}/${docs} ${PREFIX}/share/doc/asWedit
.endfor

.include "../../emulators/suse_linux/Makefile.application"

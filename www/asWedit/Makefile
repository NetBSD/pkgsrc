# $NetBSD: Makefile,v 1.22 2006/05/22 22:22:05 jlam Exp $

DISTNAME=		asWedit-4.0.1-i386.linux
PKGNAME=		${DISTNAME:S/-i386.linux//}
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		ftp://ftp.edelweb.fr/pub/asWedit/ \
			ftp://sunsite.icm.edu.pl/pub/www/asWedit/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.advasoft.com/asWedit.html
COMMENT=		Motif HTML and text editor

.include "../../emulators/suse_linux/Makefile.application"

.if !defined(USE_NATIVE_LINUX)
DEPENDS+=		suse_libc5>=7.3nb1:../../emulators/suse_libc5
.endif

ONLY_FOR_PLATFORM=	*-*-i386

RESTRICTED=		No re-distribution
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
NO_BUILD=		yes

INSTALLATION_DIRS=	bin libdata

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

.include "../../mk/bsd.pkg.mk"

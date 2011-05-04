# $NetBSD: Makefile,v 1.20 2011/05/04 16:27:42 hans Exp $
#

DISTNAME=	rfc-3.2
PKGNAME=	rfcutil-3.2
PKGREVISION=	6
CATEGORIES=	textproc
MASTER_SITES=	http://www.dewn.com/rfc/
EXTRACT_SUFX=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.dewn.com/rfc/
COMMENT=	Search for RFCs and do ports, services & protocol lookups

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	#

NO_BUILD=	YES
USE_TOOLS+=	perl:run
REPLACE_PERL=	rfc

RFCINDEXURL=	http://www.ietf.org/download/

INSTALLATION_DIRS=	bin

.include "options.mk"

do-extract:
	${SED} \
		-e 's,/usr/local,${PREFIX},' \
		-e '/VIEWER=/s,w3m lynx,${RFCVIEWER},' \
		-e '/viewer/s,-dump,${RFCDUMPOPT},' \
		-e '/viewer/s,http://ftp.isi.edu/in-notes/,${RFCINDEXURL},' \
		<${DISTDIR}/${DISTNAME} >${WRKSRC}/rfc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rfc ${DESTDIR}${PREFIX}/bin/rfc

.include "../../mk/bsd.pkg.mk"

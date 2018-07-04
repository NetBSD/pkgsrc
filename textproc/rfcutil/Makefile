# $NetBSD: Makefile,v 1.30 2018/07/04 13:40:39 jperkin Exp $
#

DISTNAME=	rfc-3.2
PKGNAME=	rfcutil-3.2
PKGREVISION=	12
CATEGORIES=	textproc
#MASTER_SITES=	http://www.dewn.com/rfc/
EXTRACT_SUFX=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.dewn.com/rfc/
COMMENT=	Search for RFCs and do ports, services & protocol lookups

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	#

NO_BUILD=	YES
USE_TOOLS+=	perl:run
REPLACE_PERL=	rfc

RFCINDEXURL=	http://www.ietf.org/download/

INSTALLATION_DIRS=	bin

SUBST_CLASSES+=		rfcutil
SUBST_STAGE.rfcutil=	pre-configure
SUBST_FILES.rfcutil=	rfc
SUBST_SED.rfcutil+=	-e 's,/usr/local,${PREFIX},'
SUBST_SED.rfcutil+=	-e '/VIEWER=/s,w3m lynx,${RFCVIEWER},'
SUBST_SED.rfcutil+=	-e '/viewer/s,-dump,${RFCDUMPOPT},'
SUBST_SED.rfcutil+=	-e '/viewer/s,http://ftp.isi.edu/in-notes/,${RFCINDEXURL},'
.include "options.mk"

do-extract:
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}/rfc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rfc ${DESTDIR}${PREFIX}/bin/rfc

.include "../../mk/bsd.pkg.mk"

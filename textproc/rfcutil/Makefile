# $NetBSD: Makefile,v 1.9 2004/01/20 12:26:50 agc Exp $
#

DISTNAME=	rfc-3.2
PKGNAME=	rfcutil-3.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.dewn.com/rfc/
EXTRACT_SUFX=	#

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.dewn.com/rfc/
COMMENT=	Search for RFCs and do ports, services & protocol lookups

DEPENDS+=	w3m-[0-9]*:../../www/w3m

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	#

NO_BUILD=	YES
USE_PERL5=	YES

post-patch:
	${SED}	-e "s|/usr/bin/perl|${LOCALBASE}/bin/perl|g"	\
		-e "s|/usr/local|${PREFIX}|g"			\
		${DISTDIR}/${DISTNAME} > ${WRKSRC}/rfc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rfc ${PREFIX}/bin/rfc

.include "../../mk/bsd.pkg.mk"

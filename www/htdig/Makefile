# $NetBSD: Makefile,v 1.6 2000/02/29 23:31:32 hubertf Exp $
#

DISTNAME=	htdig-3.1.5
CATEGORIES=	www databases
MASTER_SITES=	http://www.htdig.org/files/ \
		ftp://ftp.htdig.org/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.htdig.org/

DEPENDS+=	db-2.7.7:../../databases/db

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cgi-bin-dir=${PREFIX}/libexec/cgi-bin \
		--with-image-dir=${PREFIX}/share/examples/htdig \
		--with-search-dir=${PREFIX}/share/examples/htdig
CONFIGURE_ENV=	CPPFLAGS=-I${PREFIX}/include/db2

MESSAGE_FILE=	${WRKDIR}/MESSAGE

post-build:
	${SED} 's#@PREFIX@#${PREFIX}#g' < ${PKGDIR}/MESSAGE > ${WRKDIR}/MESSAGE

post-install:
	if [ ! -f ${PREFIX}/etc/htdig/htdig.conf ]; then \
	  ${CP} ${PREFIX}/share/examples/htdig/htdig.conf ${PREFIX}/etc/htdig/; \
	fi
	${PREFIX}/bin/htfuzzy -v synonyms
	${PREFIX}/bin/htfuzzy -v endings
	${MKDIR} /var/db/htdig

.include "../../mk/bsd.prefs.mk"
.if defined(EXTRACT_USING_PAX)
EXTRACT_ELEMENTS= -c ${DISTNAME}/db*
.else
EXTRACT_ELEMENTS= --exclude ${DISTNAME}/db*
.endif

.include "../../mk/bsd.pkg.mk"

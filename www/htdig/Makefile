# $NetBSD: Makefile,v 1.2 1999/09/23 01:33:29 fredb Exp $
#

DISTNAME=	htdig-3.1.2
CATEGORIES=	www databases
MASTER_SITES=	${MASTER_SITE_SUNSITE:=apps/www/indexing/} \
		http://www.htdig.org/files/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.htdig.org/

DEPENDS+=	db-2.7.3:../../databases/db

# Needs libstdc++
# XXX fill-in/correct as needed
NOT_FOR_PLATFORM= NetBSD-1.3[A-J]*-*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cgi-bin-dir=${PREFIX}/bin \
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

.include "../../mk/bsd.pkg.mk"

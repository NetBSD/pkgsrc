# $NetBSD: Makefile,v 1.8 2001/02/08 14:43:56 kei Exp $
#

DISTNAME=	htdig-3.1.5
CATEGORIES=	www databases
MASTER_SITES=	http://www.htdig.org/files/ \
		ftp://ftp.htdig.org/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://htdig.sourceforge.net/

DEPENDS+=	db-2.7.7:../../databases/db

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cgi-bin-dir=${PREFIX}/libexec/cgi-bin \
		--with-image-dir=${PREFIX}/share/examples/htdig \
		--with-search-dir=${PREFIX}/share/examples/htdig
CONFIGURE_ENV=	CPPFLAGS=-I${PREFIX}/include/db2

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

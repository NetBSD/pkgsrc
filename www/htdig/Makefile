# $NetBSD: Makefile,v 1.16 2003/12/04 00:16:55 fredb Exp $

DISTNAME=	htdig-3.1.6
CATEGORIES=	www databases
MASTER_SITES=	http://www.htdig.org/files/ \
		ftp://ftp.htdig.org/ \
		${MASTER_SITE_SOURCEFORGE:=files/} \
		${MASTER_SITE_SOURCEFORGE:=pub/sourceforge/htdig/} \
		http://htdig.europeanservers.net/files/ \
		http://www.it.htdig.org/files/ \
		ftp://www.it.htdig.org/pub/htdig/ \
		http://www.opdenbrouw.nl/htdig/maindocs/files/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://htdig.sourceforge.net/
COMMENT=	WWW indexing and searching system

DEPENDS+=	db>=2.7.7:../../databases/db

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cgi-bin-dir=${PREFIX}/libexec/cgi-bin \
		--with-common-dir=${PREFIX}/share/htdig/common \
		--with-config-dir=${PKG_SYSCONFDIR}/htdig/ \
		--with-database-dir=/var/db/htdig \
		--with-image-dir=${PREFIX}/share/examples/htdig \
		--with-search-dir=${PREFIX}/share/examples/htdig
CXXFLAGS+=	-Wno-deprecated
CPPFLAGS+=	-I${PREFIX}/include/db2 ${CXXFLAGS}
PLIST_SUBST=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

post-patch:
	${TOUCH} ${WRKSRC}/configure

post-install:
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}/htdig
	if [ ! -f ${PKG_SYSCONFDIR}/htdig/htdig.conf ]; then \
		${CP} ${PREFIX}/share/examples/htdig/htdig.conf \
			${PKG_SYSCONFDIR}/htdig/; \
	fi
	${PREFIX}/bin/htfuzzy -v synonyms
	${PREFIX}/bin/htfuzzy -v endings
	${INSTALL_DATA_DIR} /var/db/htdig

.include "../../mk/bsd.prefs.mk"
.if defined(EXTRACT_USING_PAX)
EXTRACT_ELEMENTS= -c ${DISTNAME}/db*
.else
EXTRACT_ELEMENTS= --exclude ${DISTNAME}/db*
.endif

.include "../../mk/bsd.pkg.mk"

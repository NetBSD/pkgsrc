# $NetBSD: Makefile,v 1.16 2008/09/15 17:34:48 taca Exp $
#

DISTNAME=	squidGuard-1.3
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.squidguard.org/Downloads/Patches/1.3/ \
		http://www.squidguard.org/Downloads/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		squidGuard-1.3-patch-20080714${EXTRACT_SUFX}

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.squidguard.org/
COMMENT=	Ultrafast and free filter, redirector and access controller for Squid

BDB_ACCEPTED=	db4
GNU_CONFIGURE=	YES
USE_TOOLS+=	lex yacc perl

DEPENDS+=	squid>=1.0:../../www/squid27

#DOCDIR= 	share/doc/squidGuard
EGDIR=		share/examples/squidGuard
DBDIR=		${VARBASE}/squidGuard

PLIST_SUBST+=	EGDIR=${EGDIR}

EXAMPLES=	squidGuard-simple.cgi squidGuard-simple-de.cgi squidGuard.cgi

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-db-inc=${BUILDLINK_PREFIX.db4}/include/db4
CONFIGURE_ARGS+=	--with-db-lib=${BUILDLINK_PREFIX.db4}/lib/db4
CONFIGURE_ARGS+=	--with-sg-config=${PKG_SYSCONFDIR:Q}/squidGuard.conf
CONFIGURE_ARGS+=	--with-sg-logdir=${LOGDIR}
CONFIGURE_ARGS+=	--with-sg-dbhome=${DBDIR}
CONFIGURE_ARGS+=	--squiduser=${SQUID_USER}

CONF_FILES_PERMS+=	${PREFIX}/${EGDIR}/squidGuard-simple.cgi \
			${CGIBINDIR}/squidGuard.cgi ${BINOWN} ${BINGRP} 0755
CONF_FILES_PERMS+=	${PREFIX}/${EGDIR}/squidGuard.conf \
			${PKG_SYSCONFDIR}/squidGuard.conf \
			${BINOWN} ${SQUID_GROUP} 0640
MAKE_DIRS+=		${CGIBINDIR}
OWN_DIRS+=		${DBDIR}
OWN_DIRS_PERMS+= 	${DBDIR} ${SQUID_USER} ${SQUID_GROUP} 0750

BUILD_DEFS+=		VARBASE
INSTALLATION_DIRS+=	bin ${DOCDIR} ${EGDIR}

.include "../../mk/bsd.prefs.mk"
.include "../../www/squid/Makefile.common"

CGIBINDIR?=		${PREFIX}/libexec/cgi-bin/
PKG_SYSCONFSUBDIR?=	squidguard

post-extract:
	cd ${WRKDIR}/squidGuard-1.3-patch-20080714/src/; \
		${MV} sgDb.c sgDiv.c.in ${WRKSRC}/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/squidGuard ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/samples/sample.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/squidGuard.conf
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/samples/${f} ${DESTDIR}${PREFIX}/${EGDIR}
.endfor

.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

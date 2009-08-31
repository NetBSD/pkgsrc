# $NetBSD: Makefile,v 1.18 2009/08/31 08:55:31 adam Exp $

DISTNAME=	squidGuard-1.4
CATEGORIES=	www
MASTER_SITES=	http://www.squidguard.org/Downloads/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.squidguard.org/
COMMENT=	Ultrafast and free filter, redirector and access controller for Squid

.include "../../www/squid/Makefile.common"

PKG_DESTDIR_SUPPORT=	user-destdir

BDB_ACCEPTED=		db4
USE_TOOLS+=		lex yacc perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-db-inc=${BUILDLINK_PREFIX.db4}/include/db4
CONFIGURE_ARGS+=	--with-db-lib=${BUILDLINK_PREFIX.db4}/lib/db4
CONFIGURE_ARGS+=	--with-sg-config=${PKG_SYSCONFDIR}/squidGuard.conf
CONFIGURE_ARGS+=	--with-sg-logdir=${LOGDIR}
CONFIGURE_ARGS+=	--with-sg-dbhome=${DBDIR}
CONFIGURE_ARGS+=	--with-squiduser=${SQUID_USER}

CHECK_PORTABILITY_SKIP=	configure-old

EGDIR=		share/examples/squidGuard
DBDIR=		${VARBASE}/squidGuard

PLIST_SUBST+=	EGDIR=${EGDIR}

CONF_FILES_PERMS+=	${PREFIX}/${EGDIR}/squidGuard-simple.cgi \
			${CGIBINDIR}/squidGuard.cgi ${BINOWN} ${BINGRP} 0755
CONF_FILES_PERMS+=	${PREFIX}/${EGDIR}/squidGuard.conf \
			${PKG_SYSCONFDIR}/squidGuard.conf \
			${BINOWN} ${SQUID_GROUP} 0640
MAKE_DIRS+=		${CGIBINDIR}
OWN_DIRS+=		${DBDIR}
OWN_DIRS_PERMS+=	${DBDIR} ${SQUID_USER} ${SQUID_GROUP} 0750

BUILD_DEFS+=		VARBASE
INSTALLATION_DIRS+=	bin ${EGDIR}

.include "../../mk/bsd.prefs.mk"

CGIBINDIR?=		${PREFIX}/libexec/cgi-bin/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/squidGuard ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/samples/sample.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/squidGuard.conf
	${INSTALL_DATA} ${WRKSRC}/samples/squidGuard-simple.cgi \
		${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/squidGuard-simple-de.cgi \
		${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/squidGuard.cgi \
		${DESTDIR}${PREFIX}/${EGDIR}

.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

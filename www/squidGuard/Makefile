# $NetBSD: Makefile,v 1.42 2022/06/28 11:37:49 wiz Exp $

DISTNAME=		squidGuard-1.4
PKGREVISION=		18
CATEGORIES=		www
MASTER_SITES=		http://www.squidguard.org/Downloads/
MASTER_SITES+=		http://www.squidguard.org/Downloads/Patches/1.4/
DISTFILES=		${DEFAULT_DISTFILES} \
			squidGuard-1.4-patch-20091015.tar.gz \
			squidGuard-1.4-patch-20091019.tar.gz
# http://bugs.squid-cache.org/show_bug.cgi?id=3978
PATCH_SITES=		-http://bugs.squid-cache.org/attachment.cgi?id=2988
PATCHFILES=		squidGuard-1.4_upgrade.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.squidguard.org/
COMMENT=	Ultrafast and free filter, redirector and access controller for Squid
LICENSE=	gnu-gpl-v2

.include "../../www/squid4/Makefile.common"

BDB_ACCEPTED=		db4 db5
USE_TOOLS+=		lex yacc perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-db-inc=${BDBBASE}/include/${BDB_TYPE}
CONFIGURE_ARGS+=	--with-db-lib=${BDBBASE}/lib/${BDB_TYPE}
CONFIGURE_ARGS+=	--with-sg-config=${PKG_SYSCONFDIR}/squidGuard.conf
CONFIGURE_ARGS+=	--with-sg-logdir=${LOGDIR}
CONFIGURE_ARGS+=	--with-sg-dbhome=${DBDIR}
CONFIGURE_ARGS+=	--with-squiduser=${SQUID_USER}

CHECK_PORTABILITY_SKIP=	configure-old

EGDIR=		share/examples/squidGuard
DBDIR=		${VARBASE}/squidGuard

PLIST_SUBST+=	EGDIR=${EGDIR}

CONF_FILES_PERMS+=	${PREFIX}/${EGDIR}/squidGuard-simple.cgi \
			${CGIBINDIR}/squidGuard.cgi ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0755
CONF_FILES_PERMS+=	${PREFIX}/${EGDIR}/squidGuard.conf \
			${PKG_SYSCONFDIR}/squidGuard.conf \
			${REAL_ROOT_USER} ${SQUID_GROUP} 0640
MAKE_DIRS+=		${CGIBINDIR}
OWN_DIRS+=		${DBDIR}
OWN_DIRS_PERMS+=	${DBDIR} ${SQUID_USER} ${SQUID_GROUP} 0750

BUILD_DEFS+=		VARBASE
INSTALLATION_DIRS+=	bin ${EGDIR}

.include "../../mk/bsd.prefs.mk"

CGIBINDIR?=		${PREFIX}/libexec/cgi-bin/

pre-patch:
	${CP} ${WRKDIR}/squidGuard-1.4-patch-20091015/sgLog.c ${WRKSRC}/src
	${CP} ${WRKDIR}/squidGuard-1.4-20091019/sg.h.in ${WRKSRC}/src
	${CP} ${WRKDIR}/squidGuard-1.4-20091019/sgDiv.c.in ${WRKSRC}/src

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

BUILDLINK_TRANSFORM+=	l:db:${BDB_TYPE}
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

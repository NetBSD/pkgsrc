# $NetBSD: Makefile,v 1.9 2023/11/10 13:19:49 sborrill Exp $

DISTNAME=	ufdbGuard-${VERSION}
VERSION=	1.35.5
PKGREVISION=	2
PKGNAME=	ufdbguard-${VERSION}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ufdbguard/}

MAINTAINER=	sborrill@NetBSD.org
HOMEPAGE=	http://ufdbguard.sourceforge.net/
COMMENT=	URL filter for use with squid
LICENSE=	gnu-gpl-v2

BUILD_DEFS+=	VARBASE

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes
REPLACE_PERL=	samples/URLblocked.cgi
USE_TOOLS+=	perl:run bash

RCD_SCRIPTS+=	ufdbguardd

.include "../../mk/bsd.prefs.mk"
UFDB_USER?=		ufdb
UFDB_GROUP?=		ufdb
PKG_USERS=		${UFDB_USER}:${UFDB_GROUP}
PKG_GROUPS=		${UFDB_GROUP}
PKG_GROUPS_VARS+=	UFDB_GROUP
PKG_USERS_VARS+=	UFDB_USER

CONFIGURE_ARGS+=	--with-ufdb-user=${UFDB_USER}
CONFIGURE_ARGS+=	--with-ufdb-mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--datadir=${DBDIR}
CONFIGURE_ARGS+=	--with-ufdb-samplesdir=${PREFIX}/${EGDIR}
CONFIGURE_ARGS+=	--with-ufdb-imagesdir=${PREFIX}/share/ufdbguard
CONFIGURE_ARGS+=	--with-ufdb-dbhome=${DBDIR}
CONFIGURE_ARGS+=	--with-ufdb-logdir=${VARBASE}/log/ufdbguard

CFLAGS.NetBSD+=		-D_NETBSD_SOURCE	# needed for struct timezone

DBDIR=			${PKG_SYSCONFDIR}/ufdbguard
EGDIR=			share/examples/ufdbguard
OWN_DIRS+=		${PKG_SYSCONFDIR}/ufdbguard/security
OWN_DIRS_PERMS+=	${VARBASE}/log/ufdbguard ${UFDB_USER} ${UFDB_GROUP} 0755
OWN_DIRS_PERMS+=	${DBDIR} ${UFDB_USER} ${UFDB_GROUP} 0755

CONF_FILES+=	${PREFIX}/${EGDIR}/ufdbGuard.conf \
		${PKG_SYSCONFDIR}/ufdbGuard.conf
CONF_FILES+=	${PREFIX}/${EGDIR}/cacerts \
		${PKG_SYSCONFDIR}/ufdbguard/security/cacerts

DEPENDS+=	wget-[0-9]*:../../net/wget

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/ufdbGuard.conf \
		${DESTDIR}${PREFIX}/${EGDIR}/ufdbGuard.conf; \
	${INSTALL_DATA} ${WRKSRC}/src/security/cacerts \
		${DESTDIR}${PREFIX}/${EGDIR}/cacerts

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

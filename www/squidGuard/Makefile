# $NetBSD: Makefile,v 1.1.1.1 2002/08/04 10:15:53 zuntum Exp $
#

DISTNAME=	squidGuard-1.2.0
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.teledanmark.no/pub/www/proxy/squidGuard/		\
		http://ftp.teledanmark.no/pub/www/proxy/squidGuard/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.squidguard.org/
COMMENT=	ultrafast and free filter, redirector and access controller for Squid

GNU_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"

SQUID_SYSCONFDIR?=      ${PKG_SYSCONFDIR}

CONFIGURE_ARGS+=	--with-db-inc=${BUILDLINK_DIR}/include/db2
CONFIGURE_ARGS+=	--with-db-lib=${BUILDLINK_DIR}/lib/db2
CONFIGURE_ARGS+=	--with-sg-config=${SQUID_SYSCONFDIR}/squid/filter.conf
CONFIGURE_ARGS+=	--with-sg-logdir=/var/squid/logs
CONFIGURE_ARGS+=	--with-sg-dbhome=${SQUID_SYSCONFDIR}/squid/db

.include "../../databases/db/buildlink.mk"
.include "../../mk/bsd.pkg.mk"

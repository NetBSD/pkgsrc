# $NetBSD: Makefile,v 1.2 2002/08/05 00:13:32 zuntum Exp $
#

DISTNAME=	squidGuard-1.2.0
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.teledanmark.no/pub/www/proxy/squidGuard/		\
		http://ftp.teledanmark.no/pub/www/proxy/squidGuard/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.squidguard.org/
COMMENT=	ultrafast and free filter, redirector and access controller for Squid

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-db-inc=${BUILDLINK_DIR}/include/db2
CONFIGURE_ARGS+=	--with-db-lib=${BUILDLINK_DIR}/lib/db2
CONFIGURE_ARGS+=	--with-sg-config=${PKG_SYSCONFDIR.squidguard}/squidguard/filter.conf
CONFIGURE_ARGS+=	--with-sg-logdir=/var/squidguard/log
CONFIGURE_ARGS+=	--with-sg-dbhome=/var/squidguard/db

.include "../../databases/db/buildlink.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.7 2003/10/19 10:22:47 jmmv Exp $
#

DISTNAME=	squidGuard-1.2.0
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.teledanmark.no/pub/www/proxy/squidGuard/		\
		http://ftp.teledanmark.no/pub/www/proxy/squidGuard/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.squidguard.org/
COMMENT=	Ultrafast and free filter, redirector and access controller for Squid

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

CONFIGURE_ARGS+=	--with-db-inc=${BUILDLINK_PREFIX.db3}/include/db3
CONFIGURE_ARGS+=	--with-db-lib=${BUILDLINK_PREFIX.db3}/lib/db3
CONFIGURE_ARGS+=	--with-sg-config=${PKG_SYSCONFDIR}/squidguard/filter.conf
CONFIGURE_ARGS+=	--with-sg-logdir=/var/squidguard/log
CONFIGURE_ARGS+=	--with-sg-dbhome=/var/squidguard/db

.include "../../databases/db3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.3 2002/08/06 01:02:44 zuntum Exp $
#

DISTNAME=	squidGuard-1.2.0
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.teledanmark.no/pub/www/proxy/squidGuard/		\
		http://ftp.teledanmark.no/pub/www/proxy/squidGuard/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.squidguard.org/
COMMENT=	ultrafast and free filter, redirector and access controller for Squid

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-db-inc=${BUILDLINK_DIR}/include/db3
CONFIGURE_ARGS+=	--with-db-lib=${BUILDLINK_DIR}/lib/db3
CONFIGURE_ARGS+=	--with-sg-config=${PKG_SYSCONFDIR.squidguard}/squidguard/filter.conf
CONFIGURE_ARGS+=	--with-sg-logdir=/var/squidguard/log
CONFIGURE_ARGS+=	--with-sg-dbhome=/var/squidguard/db

.include "../../databases/db3/buildlink.mk"
.include "../../mk/bsd.pkg.mk"

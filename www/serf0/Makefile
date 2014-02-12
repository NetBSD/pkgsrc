# $NetBSD: Makefile,v 1.5 2014/02/12 23:18:47 tron Exp $
#

DISTNAME=	serf-0.7.2
PKGNAME=	${DISTNAME:S/serf/serf0/}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://serf.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/serf/
COMMENT=	High-performance asynchronous HTTP client library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

TEST_TARGET=		check

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

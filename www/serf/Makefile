# $NetBSD: Makefile,v 1.6 2008/01/18 05:09:53 tnn Exp $
#

DISTNAME=	serf-0.1.2
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://serf.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://code.google.com/p/serf/
COMMENT=	High-performance asynchronous HTTP client library

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

TEST_TARGET=		check

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

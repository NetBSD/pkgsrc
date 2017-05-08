# $NetBSD: Makefile,v 1.29 2017/05/08 12:02:16 schmonz Exp $

DISTNAME=		xapian-core-${VERSION}
VERSION=		1.4.2
PKGNAME=		xapian-${VERSION}
CATEGORIES=		textproc
MASTER_SITES=		http://oligarchy.co.uk/xapian/${VERSION}/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://xapian.org/
COMMENT=		Probabilistic Information Retrieval search engine
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++11

TEST_TARGET=		check

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

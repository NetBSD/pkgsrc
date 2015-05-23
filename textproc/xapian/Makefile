# $NetBSD: Makefile,v 1.22 2015/05/23 18:20:59 schmonz Exp $
#

DISTNAME=		xapian-core-${VERSION}
VERSION=		1.2.21
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
USE_LANGUAGES=		c c++

TEST_TARGET=		check

.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.16 2012/10/10 16:10:31 wiz Exp $
#

DISTNAME=		xapian-core-${VERSION}
VERSION=		1.2.12
PKGNAME=		xapian-${VERSION}
CATEGORIES=		textproc
MASTER_SITES=		http://oligarchy.co.uk/xapian/${VERSION}/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://xapian.org/
COMMENT=		Probabilistic Information Retrieval search engine
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

TEST_TARGET=		check

.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# $NetBSD: Makefile,v 1.15 2012/01/10 02:41:29 schmonz Exp $
#

DISTNAME=		xapian-core-1.2.8
PKGNAME=		${DISTNAME:S/-core//}
CATEGORIES=		textproc
MASTER_SITES=		http://oligarchy.co.uk/xapian/1.2.8/

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

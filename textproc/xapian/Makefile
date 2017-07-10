# $NetBSD: Makefile,v 1.31 2017/07/10 17:29:58 schmonz Exp $

.include "../../textproc/xapian/Makefile.common"

DISTNAME=		xapian-core-${VERSION}
PKGNAME=		${DISTNAME:S/-core-/-/}

HOMEPAGE=		http://xapian.org/
COMMENT=		Probabilistic Information Retrieval search engine

TEST_TARGET=		check

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

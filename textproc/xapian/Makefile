# $NetBSD: Makefile,v 1.32 2017/09/06 09:03:05 wiz Exp $

.include "../../textproc/xapian/Makefile.common"

DISTNAME=		xapian-core-${VERSION}
PKGNAME=		${DISTNAME:S/-core-/-/}

HOMEPAGE=		https://xapian.org/
COMMENT=		Probabilistic Information Retrieval search engine

TEST_TARGET=		check

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

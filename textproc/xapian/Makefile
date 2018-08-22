# $NetBSD: Makefile,v 1.33 2018/08/22 09:47:13 wiz Exp $

PKGREVISION= 1
.include "../../textproc/xapian/Makefile.common"

DISTNAME=		xapian-core-${VERSION}
PKGNAME=		${DISTNAME:S/-core-/-/}

HOMEPAGE=		https://xapian.org/
COMMENT=		Probabilistic Information Retrieval search engine

TEST_TARGET=		check

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

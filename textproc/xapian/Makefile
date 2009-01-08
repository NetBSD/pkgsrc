# $NetBSD: Makefile,v 1.3 2009/01/08 03:43:31 dsainty Exp $
#

DISTNAME=	xapian-core-1.0.10
PKGNAME=	${DISTNAME:S/-core//}
CATEGORIES=	textproc
MASTER_SITES=	http://oligarchy.co.uk/xapian/1.0.10/

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://xapian.org/
COMMENT=	Search engine based on Probabilistic Information Retrieval

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

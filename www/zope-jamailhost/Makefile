# $NetBSD: Makefile,v 1.1.1.1 2007/12/18 16:03:48 taca Exp $
# FreeBSD: ports/japanese/zope-jamailhost/Makefile,v 1.6 2006/10/31 10:55:17 miwi Exp
#

DISTNAME=	${ZOPE_PRODUCT_NAME}-${ZOPE_PRODUCT_VER}
PKGNAME=	${ZOPE_PKG_PREFIX}-${ZOPE_PRODUCT_NAME}-${ZOPE_PRODUCT_VER}
CATEGORIES=	www python www japanese
MASTER_SITES=	http://www005.upp.so-net.ne.jp/nakagami/Download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www005.upp.so-net.ne.jp/nakagami/tips/jaMailHost.html
COMMENT=	Zope hotfix Product to send mail in Japanese

PYTHON_VERSIONS_ACCEPTED=	24
ZOPE_VERSION_ACCEPTED=		29 210

ZOPE_PRODUCT_NAME=	jaMailHost
ZOPE_PRODUCT_VER=	0.4.4
WRKSRC=			${WRKDIR}/${ZOPE_PRODUCT_NAME}

.include "../../www/zope/product.mk"
.include "../../mk/bsd.pkg.mk"

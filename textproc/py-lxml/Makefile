# $NetBSD: Makefile,v 1.20 2014/01/01 11:52:36 wiz Exp $

DISTNAME=	lxml-3.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://lxml.de/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxml.de/
COMMENT=	Python binding for libxml2 and libxslt
LICENSE=	modified-bsd

TEST_TARGET=	test_inplace
PYTHON_VERSIONS_INCLUDE_3X=	yes

.include "../../lang/python/egg.mk"
BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.7.8
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxslt+=	libxslt>=1.1.26
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

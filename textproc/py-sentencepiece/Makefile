# $NetBSD: Makefile,v 1.2 2023/04/25 14:55:28 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

WRKSRC=		${WRKDIR}/${DISTNAME}/python

USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../textproc/sentencepiece/Makefile.common"
.include "../../textproc/sentencepiece/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

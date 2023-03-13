# $NetBSD: Makefile,v 1.1 2023/03/13 14:18:27 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}

WRKSRC=		${WRKDIR}/${DISTNAME}/python

USE_TOOLS+=	pkg-config

.include "../../textproc/sentencepiece/Makefile.common"
.include "../../textproc/sentencepiece/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

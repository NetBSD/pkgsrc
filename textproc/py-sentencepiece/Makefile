# $NetBSD: Makefile,v 1.3 2025/06/06 07:51:53 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
GITHUB_PROJECT=	sentencepiece

WRKSRC=		${WRKDIR}/${DISTNAME}/python

USE_TOOLS+=	cmake pkg-config

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

pre-configure:
	${ECHO} '#!/bin/sh' > ${BUILDLINK_DIR}/bin/nproc
	${ECHO} 'echo 1' > ${BUILDLINK_DIR}/bin/nproc
	${CHMOD} 555 ${BUILDLINK_DIR}/bin/nproc

.include "../../textproc/sentencepiece/Makefile.common"
.include "../../textproc/sentencepiece/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"

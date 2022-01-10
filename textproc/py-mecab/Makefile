# $NetBSD: Makefile,v 1.18 2022/01/10 07:55:48 wiz Exp $

PKGREVISION= 1
.include "../../textproc/mecab/Makefile.common"

DISTNAME=	mecab-python-${MECAB_VERSION}
PKGNAME=	${PYPKGPREFIX}-mecab-${MECAB_VERSION}
CATEGORIES+=	python

COMMENT=	MeCab python module
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1 OR modified-bsd

USE_LANGUAGES=	c c++

TEST_ENV+=	PYTHONPATH=${WRKSRC:Q}/build/lib.${LOWER_OPSYS}-${OS_VERSION}-${MACHINE_ARCH}-${PYVERSSUFFIX}

do-test:
	${RUN}								\
	cd ${WRKSRC};							\
	env ${TEST_ENV} ${PYTHONBIN} test.py

BUILDLINK_API_DEPENDS.mecab+=	mecab>=${MECAB_VERSION}

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 0.996

.include "../../textproc/mecab/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

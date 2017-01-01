# $NetBSD: Makefile,v 1.13 2017/01/01 14:44:01 wiz Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.996

.include "../../textproc/mecab/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"

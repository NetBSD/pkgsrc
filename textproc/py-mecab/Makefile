# $NetBSD: Makefile,v 1.9 2014/05/09 07:37:22 wiz Exp $

.include "../../textproc/mecab/Makefile.common"

DISTNAME=	mecab-python-${MECAB_VERSION}
PKGNAME=	${PYPKGPREFIX}-mecab-${MECAB_VERSION}
CATEGORIES+=	python

COMMENT=	MeCab python module
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1 OR modified-bsd

USE_LANGUAGES=	c c++

EGG_NAME=	${DISTNAME:S/-/_/}

TEST_ENV+=	PYTHONPATH=${WRKSRC:Q}/build/lib.${LOWER_OPSYS}-${OS_VERSION}-${MACHINE_ARCH}-${PYVERSSUFFIX}

do-test:
	${RUN}								\
	cd ${WRKSRC};							\
	env ${TEST_ENV} ${PYTHONBIN} test.py

BUILDLINK_API_DEPENDS.mecab+=	mecab>=${MECAB_VERSION}

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.996

.include "../../textproc/mecab/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"

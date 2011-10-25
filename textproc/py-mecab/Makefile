# $NetBSD: Makefile,v 1.5 2011/10/25 08:36:20 obache Exp $
#

.include "../../textproc/mecab/Makefile.common"

DISTNAME=	mecab-python-${MECAB_VERSION}
PKGNAME=	${PYPKGPREFIX}-mecab-${MECAB_VERSION}
PKGREVISION=	1
CATEGORIES+=	python

COMMENT=	MeCab python module
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1 OR modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++

EGG_NAME=	${DISTNAME:S/-/_/}

TEST_ENV+=	PYTHONPATH=${WRKSRC:Q}/build/lib.${LOWER_OPSYS}-${OS_VERSION}-${MACHINE_ARCH}-${PYVERSSUFFIX}

do-test:
	${RUN}								\
	cd ${WRKSRC};							\
	env ${TEST_ENV} ${PYTHONBIN} test.py

BUILDLINK_API_DEPENDS.mecab+=	mecab>=${MECAB_VERSION}

.include "../../textproc/mecab/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"

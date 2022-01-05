# $NetBSD: Makefile,v 1.6 2022/01/05 15:41:25 wiz Exp $

DISTNAME=	nltk-3.6.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nltk/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nltk.org/
COMMENT=	Natural Language Toolkit (NLTK)
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-joblib-[0-9]*:../../devel/py-joblib
DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-regex>=2021.8.3:../../textproc/py-regex
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
DEPENDS+=	${PYPKGPREFIX}-tqdm-[0-9]*:../../misc/py-tqdm
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	nltk_data-averaged_perceptron_tagger-[0-9]*:../../textproc/nltk_data-averaged_perceptron_tagger
TEST_DEPENDS+=	nltk_data-averaged_perceptron_tagger_ru-[0-9]*:../../textproc/nltk_data-averaged_perceptron_tagger_ru
TEST_DEPENDS+=	nltk_data-brown-[0-9]*:../../textproc/nltk_data-brown
TEST_DEPENDS+=	nltk_data-cess_cat-[0-9]*:../../textproc/nltk_data-cess_cat
TEST_DEPENDS+=	nltk_data-cess_esp-[0-9]*:../../textproc/nltk_data-cess_esp
TEST_DEPENDS+=	nltk_data-conll2007-[0-9]*:../../textproc/nltk_data-conll2007
TEST_DEPENDS+=	nltk_data-floresta-[0-9]*:../../textproc/nltk_data-floresta
TEST_DEPENDS+=	nltk_data-gutenberg-[0-9]*:../../textproc/nltk_data-gutenberg
TEST_DEPENDS+=	nltk_data-inaugural-[0-9]*:../../textproc/nltk_data-inaugural
TEST_DEPENDS+=	nltk_data-indian-[0-9]*:../../textproc/nltk_data-indian
TEST_DEPENDS+=	nltk_data-large_grammars-[0-9]*:../../textproc/nltk_data-large_grammars
TEST_DEPENDS+=	nltk_data-nombank.1.0-[0-9]*:../../textproc/nltk_data-nombank.1.0
TEST_DEPENDS+=	nltk_data-porter_test-[0-9]*:../../textproc/nltk_data-porter_test
TEST_DEPENDS+=	nltk_data-omw-[0-9]*:../../textproc/nltk_data-omw
TEST_DEPENDS+=	nltk_data-ptb-[0-9]*:../../textproc/nltk_data-ptb
TEST_DEPENDS+=	nltk_data-pl196x-[0-9]*:../../textproc/nltk_data-pl196x
TEST_DEPENDS+=	nltk_data-punkt-[0-9]*:../../textproc/nltk_data-punkt
TEST_DEPENDS+=	nltk_data-rte-[0-9]*:../../textproc/nltk_data-rte
TEST_DEPENDS+=	nltk_data-sinica_treebank-[0-9]*:../../textproc/nltk_data-sinica_treebank
TEST_DEPENDS+=	nltk_data-stopwords-[0-9]*:../../textproc/nltk_data-stopwords
TEST_DEPENDS+=	nltk_data-treebank-[0-9]*:../../textproc/nltk_data-treebank
TEST_DEPENDS+=	nltk_data-twitter_samples-[0-9]*:../../textproc/nltk_data-twitter_samples
TEST_DEPENDS+=	nltk_data-udhr-[0-9]*:../../textproc/nltk_data-udhr
TEST_DEPENDS+=	nltk_data-universal_tagset-[0-9]*:../../textproc/nltk_data-universal_tagset
TEST_DEPENDS+=	nltk_data-wmt15_eval-[0-9]*:../../textproc/nltk_data-wmt15_eval
TEST_DEPENDS+=	nltk_data-wordnet-[0-9]*:../../textproc/nltk_data-wordnet
TEST_DEPENDS+=	nltk_data-wordnet31-[0-9]*:../../textproc/nltk_data-wordnet31
TEST_DEPENDS+=	nltk_data-wordnet_ic-[0-9]*:../../textproc/nltk_data-wordnet_ic
TEST_DEPENDS+=	nltk_data-words-[0-9]*:../../textproc/nltk_data-words

REPLACE_PYTHON=		nltk/corpus/reader/knbc.py

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} nltk nltk-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"

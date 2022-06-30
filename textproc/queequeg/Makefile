# $NetBSD: Makefile,v 1.18 2022/06/30 11:18:55 nia Exp $

DISTNAME=	queequeg-0.91
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=queequeg/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://queequeg.sourceforge.net/index-e.html
COMMENT=	Tiny English grammar checker for non-native speakers
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-cdb-[0-9]*:../../databases/py-cdb
BUILD_DEPENDS+=	WordNet-[0-9]*:../../textproc/WordNet

USE_LANGUAGES=	# none
PY_PATCHPLIST=	yes
PYTHON_VERSIONS_ACCEPTED= 27 # py-cdb

SUBST_CLASSES+=			fix-python
SUBST_STAGE.fix-python=		pre-configure
SUBST_MESSAGE.fix-python=	Fixing python interpreter
SUBST_FILES.fix-python+=	*.py
SUBST_FILES.fix-python+=	qq
SUBST_FILES.fix-python+=	Makefile
SUBST_SED.fix-python+=		-e 's,/usr/bin/env python,${PYTHONBIN},'
SUBST_SED.fix-python+=		-e 's,python ,${PYTHONBIN} ,'

BUILD_TARGET=		dict
BUILD_MAKE_FLAGS=	WORDNETDICT=${LOCALBASE}/dict

INSTALLATION_DIRS=	bin ${PYSITELIB} dict

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qq ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/pstring.py \
		${WRKSRC}/dictionary.py \
		${WRKSRC}/abstfilter.py \
		${WRKSRC}/document.py \
		${WRKSRC}/sentence.py \
		${WRKSRC}/postagfix.py \
		${WRKSRC}/output.py \
		${WRKSRC}/constraint.py \
		${WRKSRC}/texparser.py \
		${WRKSRC}/sgmllib_rev.py \
		${WRKSRC}/markupbase_rev.py \
		${WRKSRC}/regpat.py \
		${WRKSRC}/grammarerror.py \
		${WRKSRC}/unification.py \
		${DESTDIR}${PREFIX}/${PYSITELIB}
	${INSTALL_DATA} ${WRKSRC}/dict.cdb ${DESTDIR}${PREFIX}/dict

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"

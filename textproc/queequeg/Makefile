# $NetBSD: Makefile,v 1.1.1.1 2011/08/06 22:55:34 ryoon Exp $
#

DISTNAME=	queequeg-0.91
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=queequeg/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://queequeg.sourceforge.net/index-e.html
COMMENT=	Tiny English grammar checker for non-native speakers
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-cdb-[0-9]*:../../databases/py-cdb
BUILD_DEPENDS+=	WordNet-[0-9]*:../../textproc/WordNet

USE_LANGUAGES=	# none
PY_PATCHPLIST=	yes

SUBST_CLASSES+=			fix-python
SUBST_STAGE.fix-python=		pre-configure
SUBST_MESSAGE.fix-python=	Fixing python interpreter
SUBST_FILES.fix-python+=	*.py
SUBST_FILES.fix-python+=	qq
SUBST_FILES.fix-python+=	Makefile
SUBST_SED.fix-python+=		-e 's,/usr/bin/env python,${PYTHONBIN},'
SUBST_SED.fix-python+=		-e 's,python ,${PYTHONBIN} ,'

FIND_PREFIX:=		WORDNETDIR=WordNet
.include "../../mk/find-prefix.mk"

BUILD_TARGET=		dict
BUILD_MAKE_FLAGS=	WORDNETDICT=${WORDNETDIR}/dict

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

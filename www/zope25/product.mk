# $NetBSD: product.mk,v 1.8 2006/01/12 23:50:14 rillig Exp $

DIST_SUBDIR=	zope
BUILDLINK_DEPENDS.zope?=	zope-2.*
DEPENDS+=	${BUILDLINK_DEPENDS.zope}:../../www/zope25
EVAL_PREFIX+=	BUILDLINK_PREFIX.zope=zope25
BUILDLINK_PREFIX.zope_DEFAULT=	${LOCALBASE}
WRKSRC?=	${WRKDIR}
NO_BUILD=	yes

PYTHON_VERSIONS_ACCEPTED=	21

ZOPEDIR=	${BUILDLINK_PREFIX.zope}/lib/zope
PRODNAMES?=	${PKGNAME:C/^zope25-(.*)-.*/\1/}
ZOPE_COPYPRODUCT?= zope-std-copyproduct-short

PRODSUBDIR=	lib/python/Products/${PRODNAME}

.PHONY: zope-std-copyproduct-long-nogarbage
zope-std-copyproduct-long-nogarbage:
	cd ${WRKSRC:Q} && ${PAX} -rw		\
		-s ',.*/CVS/.*,,'		\
		-s ',.*/CVS$$,,'		\
		-s ',.*/\.cvsignore$$,,'	\
		-s ',.*\.orig$$,,'		\
		lib ${ZOPEDIR}

zope-std-copyproduct-long:
	(cd ${WRKSRC}; ${PAX} -r -w lib ${ZOPEDIR})

zope-std-copyproduct-short:
.for i in ${PRODNAMES}
	(cd ${WRKSRC}; ${PAX} -r -w ${i} ${ZOPEDIR}/lib/python/Products)
.endfor

do-install: ${ZOPE_COPYPRODUCT}
.for i in ${PRODNAMES}
	(cd ${ZOPEDIR}/lib/python/Products/${i}; \
	 ${PYTHONBIN} ${ZOPEDIR}/inst/compilezpy.py || true)
.endfor

.include "../../lang/python/application.mk"

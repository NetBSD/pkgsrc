# $NetBSD: product.mk,v 1.13 2008/05/26 02:13:26 joerg Exp $

DIST_SUBDIR=	zope
BUILDLINK_API_DEPENDS.zope?=	zope>=2.5<2.7:../../www/zope25
DEPENDS+=	${BUILDLINK_API_DEPENDS.zope}
EVAL_PREFIX+=	BUILDLINK_PREFIX.zope=zope25
BUILDLINK_PREFIX.zope_DEFAULT=	${LOCALBASE}
WRKSRC?=	${WRKDIR}
NO_BUILD=	yes

USE_TOOLS+=	pax

PYTHON_VERSIONS_ACCEPTED=	21

ZOPEDIR=	${BUILDLINK_PREFIX.zope}/lib/zope
PRODNAMES?=	${PKGNAME:C/^zope25-(.*)-.*/\1/}
ZOPE_COPYPRODUCT?= zope-std-copyproduct-short

PRODSUBDIR=	lib/python/Products/${PRODNAME}

.PHONY: zope-std-copyproduct-long-nogarbage
zope-std-copyproduct-long-nogarbage:
	cd ${WRKSRC:Q} && pax -rw		\
		-s ',.*/CVS/.*,,'		\
		-s ',.*/CVS$$,,'		\
		-s ',.*/\.cvsignore$$,,'	\
		-s ',.*\.orig$$,,'		\
		lib ${ZOPEDIR}

.PHONY: zope-std-copyproduct-long
zope-std-copyproduct-long:
	(cd ${WRKSRC}; pax -r -w lib ${ZOPEDIR})

.PHONY: zope-std-copyproduct-short
zope-std-copyproduct-short:
.for i in ${PRODNAMES}
	(cd ${WRKSRC}; pax -r -w ${i} ${ZOPEDIR}/lib/python/Products)
.endfor

do-install: ${ZOPE_COPYPRODUCT}
.for i in ${PRODNAMES}
	(cd ${ZOPEDIR}/lib/python/Products/${i}; \
	 ${PYTHONBIN} ${ZOPEDIR}/inst/compilezpy.py || ${TRUE})
.endfor

.include "../../lang/python/application.mk"

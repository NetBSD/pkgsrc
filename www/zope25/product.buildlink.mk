# $NetBSD: product.buildlink.mk,v 1.1 2002/09/04 14:50:43 drochner Exp $

DIST_SUBDIR=	zope
DEPENDS+=	zope-2.5.*:../../www/zope25
EVAL_PREFIX+=	BUILDLINK_PREFIX.zope=zope25
WRKSRC?=	${WRKDIR}
NO_BUILD=	yes

PYTHON_VERSIONS_ACCEPTED=	21pth

ZOPEDIR=	${BUILDLINK_PREFIX.zope}/lib/zope
PRODNAMES?=	${PKGNAME:C/^zope25-(.*)-.*/\1/}
ZOPE_COPYPRODUCT?= zope-std-copyproduct-long

PRODSUBDIR=	lib/python/Products/${PRODNAME}

zope-std-copyproduct-long:
	(cd ${WRKSRC}; ${PAX} -r -w lib ${ZOPEDIR})

zope-std-copyproduct-short:
.for i in ${PRODNAMES}
	(cd ${WRKSRC}; ${PAX} -r -w $i ${ZOPEDIR}/lib/python/Products)
.endfor

do-install: ${ZOPE_COPYPRODUCT}
.for i in ${PRODNAMES}
	(cd ${ZOPEDIR}/lib/python/Products/$i; \
	 ${PYTHONBIN} ${ZOPEDIR}/inst/compilezpy.py || true)
.endfor

.include "../../lang/python/application.buildlink.mk"

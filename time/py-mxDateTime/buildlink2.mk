# $NetBSD: buildlink2.mk,v 1.4 2002/10/25 14:14:24 drochner Exp $

.if !defined(PY_MXDATETIME_BUILDLINK2_MK)
PY_MXDATETIME_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pymxdatetime
BUILDLINK_DEPENDS.pymxdatetime?=	${PYPKGPREFIX}-mxDateTime-[0-9]*
BUILDLINK_PKGSRCDIR.pymxdatetime?=	../../time/py-mxDateTime

EVAL_PREFIX+= BUILDLINK_PREFIX.pymxdatetime=${PYPKGPREFIX}-mxDateTime
BUILDLINK_PREFIX.pymxdatetime_DEFAULT= ${LOCALBASE}

BUILDLINK_FILES.pymxdatetime+= ${PYSITELIB}/mx/DateTime/mxDateTime/mxDateTime.h
BUILDLINK_FILES.pymxdatetime+= ${PYSITELIB}/mx/DateTime/mxDateTime/mxh.h
# XXX we need the transform because -I${PREFIX}/lib is not transformed
BUILDLINK_TRANSFORM.pymxdatetime+= \
	-e "s|${PYSITELIB}/mx/DateTime/mxDateTime|include|g"

BUILDLINK_TARGETS+=	pymxdatetime-buildlink

pymxdatetime-buildlink:	_BUILDLINK_USE

.endif	# PY_MXDATETIME_BUILDLINK2_MK

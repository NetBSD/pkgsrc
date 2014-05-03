# $NetBSD: buildlink3.mk,v 1.1 2014/05/03 15:34:22 rodent Exp $

BUILDLINK_TREE+=	py-cjson

.if !defined(PY_CJSON_BUILDLINK3_MK)
PY_CJSON_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-cjson+=	${PYPKGPREFIX}-cjson>=1.0.5
BUILDLINK_PKGSRCDIR.py-cjson?=	../../textproc/py-cjson
.endif	# PY_CJSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-cjson

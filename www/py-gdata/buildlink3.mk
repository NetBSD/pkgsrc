# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:25:37 joerg Exp $

BUILDLINK_TREE+=	py-gdata

.if !defined(PY_GDATA_BUILDLINK3_MK)
PY_GDATA_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-gdata+=	${PYPKGPREFIX}-gdata>=1.2.1
BUILDLINK_PKGSRCDIR.py-gdata?=	../../www/py-gdata
.endif # PY_GDATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-gdata

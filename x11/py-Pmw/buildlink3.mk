# $NetBSD: buildlink3.mk,v 1.9 2009/07/22 09:39:20 wiz Exp $

BUILDLINK_TREE+=	py-Pmw

.if !defined(PY_PMW_BUILDLINK3_MK)
PY_PMW_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-Pmw+=	${PYPKGPREFIX}-Pmw-[0-9]*
BUILDLINK_ABI_DEPENDS.py-Pmw?=	${PYPKGPREFIX}-Pmw>=1.2nb1
BUILDLINK_PKGSRCDIR.py-Pmw?=	../../x11/py-Pmw
.endif # PY_PMW_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-Pmw

# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:25:48 joerg Exp $

BUILDLINK_TREE+=	pypmw

.if !defined(PY_PMW_BUILDLINK3_MK)
PY_PMW_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pypmw+=	${PYPKGPREFIX}-Pmw-[0-9]*
BUILDLINK_ABI_DEPENDS.pypmw?=	${PYPKGPREFIX}-Pmw>=1.2nb1
BUILDLINK_PKGSRCDIR.pypmw?=	../../x11/py-Pmw
.endif # PY_PMW_BUILDLINK3_MK

BUILDLINK_TREE+=	-pypmw

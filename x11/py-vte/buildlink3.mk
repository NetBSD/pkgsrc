# $NetBSD: buildlink3.mk,v 1.30 2020/03/08 16:48:29 wiz Exp $

BUILDLINK_TREE+=	py-vte

.if !defined(PY_VTE_BUILDLINK3_MK)
PY_VTE_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-vte+=	${PYPKGPREFIX}-vte>=0.26.0
BUILDLINK_ABI_DEPENDS.py-vte+=	${PYPKGPREFIX}-vte>=0.28.1nb26
BUILDLINK_PKGSRCDIR.py-vte?=	../../x11/py-vte

.include "../../x11/vte/buildlink3.mk"
.endif # PY_VTE_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-vte

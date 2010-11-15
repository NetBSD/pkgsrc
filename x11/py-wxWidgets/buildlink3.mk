# $NetBSD: buildlink3.mk,v 1.21 2010/11/15 22:59:08 abs Exp $

BUILDLINK_TREE+=	${PYPKGPREFIX}-wxWidgets

.if !defined(PY_WXWIDGETS_BUILDLINK3_MK)
PY_WXWIDGETS_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-wxWidgets+=	${PYPKGPREFIX}-wxWidgets>=2.6.1.0
BUILDLINK_ABI_DEPENDS.${PYPKGPREFIX}-wxWidgets?=	${PYPKGPREFIX}-wxWidgets>=2.8.10.1nb5
BUILDLINK_PKGSRCDIR.${PYPKGPREFIX}-wxWidgets?=	../../x11/py-wxWidgets

.include "../../x11/wxGTK28/buildlink3.mk"
.endif # PY_WXWIDGETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-${PYPKGPREFIX}-wxWidgets

# $NetBSD: buildlink3.mk,v 1.54 2020/03/10 22:09:12 wiz Exp $

BUILDLINK_TREE+=	${PYPKGPREFIX}-wxWidgets

.if !defined(PY_WXWIDGETS_BUILDLINK3_MK)
PY_WXWIDGETS_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-wxWidgets+=	${PYPKGPREFIX}-wxWidgets>=2.6.1.0
BUILDLINK_ABI_DEPENDS.${PYPKGPREFIX}-wxWidgets+=	${PYPKGPREFIX}-wxWidgets>=2.8.12.0nb15
BUILDLINK_ABI_DEPENDS.${PYPKGPREFIX}-wxWidgets?=	${PYPKGPREFIX}-wxWidgets>=2.8.12.0nb6
BUILDLINK_PKGSRCDIR.${PYPKGPREFIX}-wxWidgets?=		../../x11/py-wxWidgets

.include "../../x11/wxGTK28/buildlink3.mk"
.endif # PY_WXWIDGETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-${PYPKGPREFIX}-wxWidgets

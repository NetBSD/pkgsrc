# $NetBSD: buildlink3.mk,v 1.11 2012/08/21 23:49:26 marino Exp $

BUILDLINK_TREE+=	pytk

.if !defined(PYTK_BUILDLINK3_MK)
PYTK_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pytk+=	${PYPKGPREFIX}-Tk-[0-9]*
BUILDLINK_ABI_DEPENDS.pytk+=	${PYPKGPREFIX}-Tk>=0nb6
BUILDLINK_PKGSRCDIR.pytk?=	../../x11/py-Tk

.include "../../x11/tk/buildlink3.mk"
.endif # PYTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-pytk

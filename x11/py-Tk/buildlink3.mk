# $NetBSD: buildlink3.mk,v 1.12 2013/06/03 10:06:22 wiz Exp $

BUILDLINK_TREE+=	pytk

.if !defined(PYTK_BUILDLINK3_MK)
PYTK_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pytk+=	${PYPKGPREFIX}-Tk-[0-9]*
BUILDLINK_ABI_DEPENDS.pytk+=	${PYPKGPREFIX}-Tk>=2.7.5nb1
BUILDLINK_PKGSRCDIR.pytk?=	../../x11/py-Tk

.include "../../x11/tk/buildlink3.mk"
.endif # PYTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-pytk

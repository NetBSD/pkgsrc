# $NetBSD: buildlink3.mk,v 1.4 2009/08/26 19:57:05 sno Exp $

BUILDLINK_TREE+=	py-kiwi

.if !defined(PY_KIWI_BUILDLINK3_MK)
PY_KIWI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-kiwi+=	${PYPKGPREFIX}-kiwi>=1.9.22
BUILDLINK_ABI_DEPENDS.py-kiwi?=	py25-kiwi>=1.9.22nb1
BUILDLINK_PKGSRCDIR.py-kiwi?=	../../x11/py-kiwi

.include "../../x11/py-gtk2/buildlink3.mk"
.endif # PY_KIWI_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-kiwi

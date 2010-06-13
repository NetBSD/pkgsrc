# $NetBSD: buildlink3.mk,v 1.6 2010/06/13 22:45:49 wiz Exp $

BUILDLINK_TREE+=	py-kiwi

.if !defined(PY_KIWI_BUILDLINK3_MK)
PY_KIWI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-kiwi+=	${PYPKGPREFIX}-kiwi>=1.9.22
BUILDLINK_ABI_DEPENDS.py-kiwi?=	${PYPKGPREFIX}-kiwi>=1.9.22nb2
BUILDLINK_PKGSRCDIR.py-kiwi?=	../../x11/py-kiwi

.include "../../x11/py-gtk2/buildlink3.mk"
.endif # PY_KIWI_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-kiwi

# $NetBSD: buildlink3.mk,v 1.12 2020/06/02 08:23:07 adam Exp $

BUILDLINK_TREE+=	py-keybinder

.if !defined(PY_KEYBINDER_BUILDLINK3_MK)
PY_KEYBINDER_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-keybinder+=	${PYPKGPREFIX}-keybinder>=0.3.0
BUILDLINK_ABI_DEPENDS.py-keybinder?=	${PYPKGPREFIX}-keybinder>=0.3.0nb11
BUILDLINK_PKGSRCDIR.py-keybinder?=	../../x11/py-keybinder

.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/keybinder/buildlink3.mk"
.endif	# PY_KEYBINDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-keybinder

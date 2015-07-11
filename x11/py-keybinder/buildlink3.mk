# $NetBSD: buildlink3.mk,v 1.1 2015/07/11 11:13:28 kamil Exp $

BUILDLINK_TREE+=	py-keybinder

.if !defined(PY_KEYBINDER_BUILDLINK3_MK)
PY_KEYBINDER_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-keybinder+=	${PYPKGPREFIX}-keybinder>=0.3.0
BUILDLINK_PKGSRCDIR.py-keybinder?=	../../x11/py-keybinder

.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/keybinder/buildlink3.mk"
.endif	# PY_KEYBINDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-keybinder

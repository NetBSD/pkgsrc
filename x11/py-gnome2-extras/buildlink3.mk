# $NetBSD: buildlink3.mk,v 1.58 2020/03/10 22:09:11 wiz Exp $

BUILDLINK_TREE+=	pygnome2ex

.if !defined(PYGNOME2EX_BUILDLINK3_MK)
PYGNOME2EX_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pygnome2ex+=	${PYPKGPREFIX}-gnome2-extras>=2.12.0nb3
BUILDLINK_ABI_DEPENDS.pygnome2ex+=	${PYPKGPREFIX}-gnome2-extras>=2.25.3nb43
BUILDLINK_PKGSRCDIR.pygnome2ex?=	../../x11/py-gnome2-extras

.include "../../x11/py-gnome2/buildlink3.mk"
.endif # PYGNOME2EX_BUILDLINK3_MK

BUILDLINK_TREE+=	-pygnome2ex

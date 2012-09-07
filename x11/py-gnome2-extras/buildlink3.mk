# $NetBSD: buildlink3.mk,v 1.29 2012/09/07 19:17:50 adam Exp $

BUILDLINK_TREE+=	pygnome2ex

.if !defined(PYGNOME2EX_BUILDLINK3_MK)
PYGNOME2EX_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pygnome2ex+=	${PYPKGPREFIX}-gnome2-extras>=2.12.0nb3
BUILDLINK_ABI_DEPENDS.pygnome2ex+=	py27-gnome2-extras>=2.25.3nb11
BUILDLINK_PKGSRCDIR.pygnome2ex?=	../../x11/py-gnome2-extras

.include "../../x11/py-gnome2/buildlink3.mk"
.endif # PYGNOME2EX_BUILDLINK3_MK

BUILDLINK_TREE+=	-pygnome2ex

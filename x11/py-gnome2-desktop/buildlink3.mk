# $NetBSD: buildlink3.mk,v 1.7 2010/11/15 22:59:07 abs Exp $

BUILDLINK_TREE+=	py-gnome2-desktop

.if !defined(PY_GNOME2_DESKTOP_BUILDLINK3_MK)
PY_GNOME2_DESKTOP_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-gnome2-desktop+=	${PYPKGPREFIX}-gnome2-desktop>=2.16.0
BUILDLINK_ABI_DEPENDS.py-gnome2-desktop?=	${PYPKGPREFIX}-gnome2-desktop>=2.30.2nb5
BUILDLINK_PKGSRCDIR.py-gnome2-desktop?=		../../x11/py-gnome2-desktop

.include "../../x11/py-gnome2/buildlink3.mk"
.endif # PY_GNOME2_DESKTOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-gnome2-desktop

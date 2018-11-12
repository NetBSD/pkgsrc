# $NetBSD: buildlink3.mk,v 1.43 2018/11/12 03:51:33 ryoon Exp $

BUILDLINK_TREE+=	py-gnome2-desktop

.if !defined(PY_GNOME2_DESKTOP_BUILDLINK3_MK)
PY_GNOME2_DESKTOP_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-gnome2-desktop+=	${PYPKGPREFIX}-gnome2-desktop>=2.16.0
BUILDLINK_ABI_DEPENDS.py-gnome2-desktop?=	${PYPKGPREFIX}-gnome2-desktop>=2.32.0nb60
BUILDLINK_ABI_DEPENDS.py-gnome2-desktop?=	${PYPKGPREFIX}-gnome2-desktop>=2.32.0nb51
BUILDLINK_PKGSRCDIR.py-gnome2-desktop?=		../../x11/py-gnome2-desktop

.include "../../x11/py-gnome2/buildlink3.mk"
.endif # PY_GNOME2_DESKTOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-gnome2-desktop

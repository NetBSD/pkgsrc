# $NetBSD: buildlink3.mk,v 1.70 2020/06/02 08:23:06 adam Exp $

BUILDLINK_TREE+=	pygnome2

.if !defined(PYGNOME2_BUILDLINK3_MK)
PYGNOME2_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pygnome2+=	${PYPKGPREFIX}-gnome2>=2.10.0
BUILDLINK_ABI_DEPENDS.pygnome2+=	${PYPKGPREFIX}-gnome2>=2.28.1nb45
BUILDLINK_PKGSRCDIR.pygnome2?=		../../x11/py-gnome2

.include "../../net/py-ORBit/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.endif # PYGNOME2_BUILDLINK3_MK

BUILDLINK_TREE+=	-pygnome2

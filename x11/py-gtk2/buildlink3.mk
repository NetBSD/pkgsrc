# $NetBSD: buildlink3.mk,v 1.70 2022/11/23 16:19:11 adam Exp $

BUILDLINK_TREE+=	pygtk2

.if !defined(PYGTK2_BUILDLINK3_MK)
PYGTK2_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.8.4
BUILDLINK_ABI_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.24.0nb40
BUILDLINK_PKGSRCDIR.pygtk2?=	../../x11/py-gtk2

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # PYGTK2_BUILDLINK3_MK

BUILDLINK_TREE+=	-pygtk2

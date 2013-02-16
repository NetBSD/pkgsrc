# $NetBSD: buildlink3.mk,v 1.43 2013/02/16 11:18:42 wiz Exp $

BUILDLINK_TREE+=	pygtk2

.if !defined(PYGTK2_BUILDLINK3_MK)
PYGTK2_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.8.4
BUILDLINK_ABI_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.24.0nb10
BUILDLINK_PKGSRCDIR.pygtk2?=	../../x11/py-gtk2

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.if (!empty(MACHINE_ARCH:Mi386) || !empty(MACHINE_ARCH:Mx86_64) || \
	!empty(MACHINE_ARCH:Mia64) || !empty(MACHINE_ARCH:Mpowerpc*) || \
	!empty(MACHINE_ARCH:Mhppa) || !empty(MACHINE_ARCH:Msparc*) || \
	!empty(MACHINE_ARCH:Malpha) || !empty(MACHINE_ARCH:Mmips*))
.include "../../math/py-numpy/buildlink3.mk"
.endif
.include "../../x11/gtk2/buildlink3.mk"
.endif # PYGTK2_BUILDLINK3_MK

BUILDLINK_TREE+=	-pygtk2

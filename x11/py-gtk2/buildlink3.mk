# $NetBSD: buildlink3.mk,v 1.48 2013/07/10 20:12:59 wiz Exp $

BUILDLINK_TREE+=	pygtk2

.if !defined(PYGTK2_BUILDLINK3_MK)
PYGTK2_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.8.4
BUILDLINK_ABI_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.24.0nb13
BUILDLINK_PKGSRCDIR.pygtk2?=	../../x11/py-gtk2

pkgbase := pygtk2
.include "../../mk/pkg-build-options.mk"

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.pygtk2:Mpy-numpy)
.include "../../math/py-numpy/buildlink3.mk"
.endif
.include "../../x11/gtk2/buildlink3.mk"
.endif # PYGTK2_BUILDLINK3_MK

BUILDLINK_TREE+=	-pygtk2

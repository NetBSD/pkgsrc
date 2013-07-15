# $NetBSD: buildlink3.mk,v 1.49 2013/07/15 03:26:51 obache Exp $

BUILDLINK_TREE+=	pygtk2

.if !defined(PYGTK2_BUILDLINK3_MK)
PYGTK2_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.8.4
BUILDLINK_ABI_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.24.0nb13
BUILDLINK_PKGSRCDIR.pygtk2?=	../../x11/py-gtk2

pkgbase := ${PYPKGPREFIX}-gtk2
.include "../../mk/pkg-build-options.mk"

.include "../../devel/py-gobject/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.${PYPKGPREFIX}-gtk2:Mpy-numpy)
.include "../../math/py-numpy/buildlink3.mk"
.endif
.include "../../x11/gtk2/buildlink3.mk"
.endif # PYGTK2_BUILDLINK3_MK

BUILDLINK_TREE+=	-pygtk2

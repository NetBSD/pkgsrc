# $NetBSD: buildlink2.mk,v 1.2 2003/11/12 01:31:53 salo Exp $

.if !defined(PYGNOME2_BUILDLINK2_MK)
PYGNOME2_BUILDLINK2_MK=	# defined

PYTHON_VERSIONS_ACCEPTED=	23pth 22pth
.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pygnome2
BUILDLINK_DEPENDS.pygnome2?=		${PYPKGPREFIX}-gnome2>=2.0.0nb1
BUILDLINK_PKGSRCDIR.pygnome2?=		../../x11/py-gnome2

EVAL_PREFIX+=	BUILDLINK_PREFIX.pygnome2=${PYPKGPREFIX}-gnome2
BUILDLINK_PREFIX.pygnome2_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pygnome2+=	lib/pkgconfig/gnome-python-2.0.pc

.include "../../www/libgtkhtml/buildlink2.mk"
.include "../../net/py-ORBit/buildlink2.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../sysutils/nautilus/buildlink2.mk"
.include "../../x11/libzvt/buildlink2.mk"
.include "../../x11/gnome-panel/buildlink2.mk"
.include "../../x11/py-gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	pygnome2-buildlink

pygnome2-buildlink: _BUILDLINK_USE

.endif	# PYGNOME2_BUILDLINK2_MK

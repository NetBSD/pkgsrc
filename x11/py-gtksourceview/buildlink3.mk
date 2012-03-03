# $NetBSD: buildlink3.mk,v 1.4 2012/03/03 00:11:56 wiz Exp $

BUILDLINK_TREE+=	py_gtksourceview

.if !defined(PY_GTKSOURCEVIEW_BUILDLINK3_MK)
PY_GTKSOURCEVIEW_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py_gtksourceview+=	${PYPKGPREFIX}-gtksourceview>=2.8.0nb1
BUILDLINK_ABI_DEPENDS.py_gtksourceview?=	${PYPKGPREFIX}-gtksourceview>=2.10.1nb6
BUILDLINK_PKGSRCDIR.py_gtksourceview?=	../../x11/py-gtksourceview

#.include "../../devel/py-gobject-shared/buildlink3.mk"
#.include "../../devel/glib2/buildlink3.mk"
.endif # PY_GTKSOURCEVIEW_BUILDLINK3_MK

BUILDLINK_TREE+=	-py_gtksourceview

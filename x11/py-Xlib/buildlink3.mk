# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:25:48 joerg Exp $

BUILDLINK_TREE+=	py-Xlib

.if !defined(PY_XLIB_BUILDLINK3_MK)
PY_XLIB_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-Xlib+=	${PYPKGPREFIX}-Xlib>=0.12
BUILDLINK_ABI_DEPENDS.py-Xlib?=	${PYPKGPREFIX}-Xlib>=0.12nb1
BUILDLINK_PKGSRCDIR.py-Xlib?=	../../x11/py-Xlib
.endif # PY_XLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-Xlib

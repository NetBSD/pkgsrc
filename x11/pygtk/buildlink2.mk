# $NetBSD: buildlink2.mk,v 1.1.2.2 2002/08/22 20:45:57 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pygtk
BUILDLINK_DEPENDS.pygtk?=	${PYPKGPREFIX}-gtk-*
BUILDLINK_PKGSRCDIR.pygtk?=	../../x11/pygtk

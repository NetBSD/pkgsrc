# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:55 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pygtk
BUILDLINK_DEPENDS.pygtk?=	${PYPKGPREFIX}-gtk-*
BUILDLINK_DEPENDS.pygtk?=	../../x11/pygtk

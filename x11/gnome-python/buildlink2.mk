# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:50 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pygnome
BUILDLINK_DEPENDS.pygnome?=	${PYPKGPREFIX}-gnome-*
BUILDLINK_PKGSRCDIR.pygnome?=	../../x11/gnome-python

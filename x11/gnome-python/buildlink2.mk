# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:23:29 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pygnome
BUILDLINK_DEPENDS.pygnome?=	${PYPKGPREFIX}-gnome-*
BUILDLINK_PKGSRCDIR.pygnome?=	../../x11/gnome-python

# $NetBSD: buildlink2.mk,v 1.7 2004/01/03 18:49:56 reed Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pygnome
BUILDLINK_DEPENDS.pygnome?=	${PYPKGPREFIX}-gnome>=1.4.4nb4
BUILDLINK_PKGSRCDIR.pygnome?=	../../x11/gnome-python

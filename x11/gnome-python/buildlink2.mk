# $NetBSD: buildlink2.mk,v 1.5 2003/05/02 11:57:02 wiz Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pygnome
BUILDLINK_DEPENDS.pygnome?=	${PYPKGPREFIX}-gnome>=1.4.4nb1
BUILDLINK_PKGSRCDIR.pygnome?=	../../x11/gnome-python

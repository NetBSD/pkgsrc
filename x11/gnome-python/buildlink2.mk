# $NetBSD: buildlink2.mk,v 1.6 2003/07/13 13:53:57 wiz Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pygnome
BUILDLINK_DEPENDS.pygnome?=	${PYPKGPREFIX}-gnome>=1.4.4nb2
BUILDLINK_PKGSRCDIR.pygnome?=	../../x11/gnome-python

# $NetBSD: buildlink2.mk,v 1.3 2002/09/10 16:06:53 wiz Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pygnome
BUILDLINK_DEPENDS.pygnome?=	${PYPKGPREFIX}-gnome>=1.4.0nb2
BUILDLINK_PKGSRCDIR.pygnome?=	../../x11/gnome-python

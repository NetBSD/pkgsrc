# $NetBSD: buildlink2.mk,v 1.8 2004/03/26 02:27:59 wiz Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pygnome
BUILDLINK_DEPENDS.pygnome?=	${PYPKGPREFIX}-gnome>=1.4.4nb4
BUILDLINK_RECOMMENDED.pygnome?=	${PYPKGPREFIX}-gnome>=1.4.4nb5
BUILDLINK_PKGSRCDIR.pygnome?=	../../x11/gnome-python

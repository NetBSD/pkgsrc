# $NetBSD: buildlink.mk,v 1.1 2002/01/19 11:44:20 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPENDS.pygnome?= ${PYPKGPREFIX}-gnome-*
DEPENDS+= ${BUILDLINK_DEPENDS.pygnome}:../../x11/gnome-python

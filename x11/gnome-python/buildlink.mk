# $NetBSD: buildlink.mk,v 1.2 2002/09/10 16:06:53 wiz Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPENDS.pygnome?= ${PYPKGPREFIX}-gnome>=1.4.0nb2
DEPENDS+= ${BUILDLINK_DEPENDS.pygnome}:../../x11/gnome-python

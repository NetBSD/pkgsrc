# $NetBSD: buildlink.mk,v 1.1.1.1 2002/02/18 11:55:02 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPENDS.pygtk?= ${PYPKGPREFIX}-gtk-*
DEPENDS+= ${BUILDLINK_DEPENDS.pygtk}:../../x11/pygtk

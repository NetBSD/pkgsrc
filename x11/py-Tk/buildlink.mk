# $NetBSD: buildlink.mk,v 1.1 2002/01/28 17:34:29 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPENDS.pytk?= ${PYPKGPREFIX}-Tk-*
DEPENDS+= ${BUILDLINK_DEPENDS.pytk}:../../x11/py-Tk

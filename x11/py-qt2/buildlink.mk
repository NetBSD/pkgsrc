# $NetBSD: buildlink.mk,v 1.1.1.1 2002/04/17 10:31:36 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPENDS.pyqt2?= ${PYPKGPREFIX}-qt2-[0-9]*
DEPENDS+= ${BUILDLINK_DEPENDS.pyqt2}:../../x11/py-qt2

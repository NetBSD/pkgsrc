# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:54 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyqt2
BUILDLINK_DEPENDS.pyqt2?=	${PYPKGPREFIX}-qt2-[0-9]*
BUILDLINK_DEPENDS.pyqt2?=	../../x11/py-qt2

# $NetBSD: buildlink2.mk,v 1.1.2.2 2002/08/22 20:45:22 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyqt2
BUILDLINK_DEPENDS.pyqt2?=	${PYPKGPREFIX}-qt2-[0-9]*
BUILDLINK_PKGSRCDIR.pyqt2?=	../../x11/py-qt2

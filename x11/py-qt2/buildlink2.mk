# $NetBSD: buildlink2.mk,v 1.3 2004/03/29 05:05:50 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyqt2
BUILDLINK_PKGBASE.pyqt2?=	${PYPKGPREFIX}-qt2
BUILDLINK_DEPENDS.pyqt2?=	${PYPKGPREFIX}-qt2-[0-9]*
BUILDLINK_PKGSRCDIR.pyqt2?=	../../x11/py-qt2

# $NetBSD: buildlink2.mk,v 1.1.2.1 2002/06/23 23:04:54 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyqt2sip
BUILDLINK_DEPENDS.pyqt2sip?=	${PYPKGPREFIX}-qt2-sip-*
BUILDLINK_DEPENDS.pyqt2sip?=	../../x11/py-qt2-sip

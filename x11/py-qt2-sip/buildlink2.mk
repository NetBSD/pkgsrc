# $NetBSD: buildlink2.mk,v 1.2 2002/08/25 19:23:57 jlam Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyqt2sip
BUILDLINK_DEPENDS.pyqt2sip?=	${PYPKGPREFIX}-qt2-sip-*
BUILDLINK_PKGSRCDIR.pyqt2sip?=	../../x11/py-qt2-sip

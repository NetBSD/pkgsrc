# $NetBSD: buildlink.mk,v 1.1.1.1 2002/04/17 10:29:01 drochner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPENDS.pyqt2sip?= ${PYPKGPREFIX}-qt2-sip-*
DEPENDS+= ${BUILDLINK_DEPENDS.pyqt2sip}:../../x11/py-qt2-sip

# $NetBSD: buildlink2.mk,v 1.1 2003/05/09 18:06:13 drochner Exp $

.if !defined(PYWXWINDOWS_BUILDLINK2_MK)
PYWXWINDOWS_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pywxWindows
BUILDLINK_DEPENDS.pywxWindows?=		${PYPKGPREFIX}-wxWindows-*
BUILDLINK_PKGSRCDIR.pywxWindows?=	../../x11/py-wxWindows

.endif	# PYWXWINDOWS_BUILDLINK2_MK

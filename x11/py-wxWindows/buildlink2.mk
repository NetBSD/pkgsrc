# $NetBSD: buildlink2.mk,v 1.2 2004/03/26 02:28:02 wiz Exp $

.if !defined(PYWXWINDOWS_BUILDLINK2_MK)
PYWXWINDOWS_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pywxWindows
BUILDLINK_DEPENDS.pywxWindows?=		${PYPKGPREFIX}-wxWindows-*
BUILDLINK_RECOMMENDED.pywxWindows?=	${PYPKGPREFIX}-wxWindows>=2.4.2.4nb4
BUILDLINK_PKGSRCDIR.pywxWindows?=	../../x11/py-wxWindows

.endif	# PYWXWINDOWS_BUILDLINK2_MK

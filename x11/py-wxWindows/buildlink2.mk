# $NetBSD: buildlink2.mk,v 1.3 2004/03/29 05:05:53 jlam Exp $

.if !defined(PYWXWINDOWS_BUILDLINK2_MK)
PYWXWINDOWS_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pywxWindows
BUILDLINK_PKGBASE.pywxWindows?=		${PYPKGPREFIX}-wxWindows
BUILDLINK_DEPENDS.pywxWindows?=		${PYPKGPREFIX}-wxWindows-[0-9]*
BUILDLINK_RECOMMENDED.pywxWindows?=	${PYPKGPREFIX}-wxWindows>=2.4.2.4nb4
BUILDLINK_PKGSRCDIR.pywxWindows?=	../../x11/py-wxWindows

.endif	# PYWXWINDOWS_BUILDLINK2_MK

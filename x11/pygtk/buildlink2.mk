# $NetBSD: buildlink2.mk,v 1.6 2004/01/03 18:50:00 reed Exp $

.if !defined(PY_GTK_BUILDLINK2_MK)

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pygtk
BUILDLINK_DEPENDS.pygtk?=	${PYPKGPREFIX}-gtk>=0.6.9nb4
BUILDLINK_PKGSRCDIR.pygtk?=	../../x11/pygtk

.endif	# PY_GTK_BUILDLINK2_MK

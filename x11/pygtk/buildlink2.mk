# $NetBSD: buildlink2.mk,v 1.4 2003/05/02 11:57:30 wiz Exp $

.if !defined(PY_GTK_BUILDLINK2_MK)

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pygtk
BUILDLINK_DEPENDS.pygtk?=	${PYPKGPREFIX}-gtk>=0.6.9nb2
BUILDLINK_PKGSRCDIR.pygtk?=	../../x11/pygtk

.endif	# PY_GTK_BUILDLINK2_MK

# $NetBSD: buildlink2.mk,v 1.5 2003/07/13 13:54:28 wiz Exp $

.if !defined(PY_GTK_BUILDLINK2_MK)

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pygtk
BUILDLINK_DEPENDS.pygtk?=	${PYPKGPREFIX}-gtk>=0.6.9nb3
BUILDLINK_PKGSRCDIR.pygtk?=	../../x11/pygtk

.endif	# PY_GTK_BUILDLINK2_MK

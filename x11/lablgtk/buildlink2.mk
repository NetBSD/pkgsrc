# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/10/16 16:40:25 dillo Exp $
#
# This Makefile fragment is included by packages that use lablgtk.

.if !defined(LABLGTK_BUILDLINK2_MK)
LABLGTK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			lablgtk
BUILDLINK_DEPENDS.lablgtk?=		lablgtk>=1.2.5
BUILDLINK_PKGSRCDIR.lablgtk?=		../../dillo/lablgtk

EVAL_PREFIX+=	BUILDLINK_PREFIX.lablgtk=lablgtk
BUILDLINK_PREFIX.lablgtk_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.lablgtk+=	lib/ocaml/lablgtk/*

.include "../../x11/gtk/buildlink2.mk"
.include "../../lang/ocaml/buildlink2.mk"

BUILDLINK_TARGETS+=	lablgtk-buildlink

lablgtk-buildlink: _BUILDLINK_USE

.endif	# LABLGTK_BUILDLINK2_MK

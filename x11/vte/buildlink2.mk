# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/13 17:54:15 xtraeme Exp $
#
# This Makefile fragment is included by packages that use vte.
#
# This file was created automatically using createbuildlink 2.7.
#

.if !defined(VTE_BUILDLINK2_MK)
VTE_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			vte
BUILDLINK_DEPENDS.vte?=		vte>=0.11.10
BUILDLINK_PKGSRCDIR.vte?=		../../x11/vte

EVAL_PREFIX+=	BUILDLINK_PREFIX.vte=vte
BUILDLINK_PREFIX.vte_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.vte+=	include/vte/*.h
BUILDLINK_FILES.vte+=	lib/libvte.*
BUILDLINK_FILES.vte+=	lib/pkgconfig/vte.pc
BUILDLINK_FILES.vte+=	lib/vte/decset
BUILDLINK_FILES.vte+=	lib/vte/interpret
BUILDLINK_FILES.vte+=	lib/vte/iso8859mode
BUILDLINK_FILES.vte+=	lib/vte/nativeecho
BUILDLINK_FILES.vte+=	lib/vte/osc
BUILDLINK_FILES.vte+=	lib/vte/slowcat
BUILDLINK_FILES.vte+=	lib/vte/utf8echo
BUILDLINK_FILES.vte+=	lib/vte/utf8mode
BUILDLINK_FILES.vte+=	lib/vte/vterdb
BUILDLINK_FILES.vte+=	lib/vte/window

.include "../../x11/libzvt/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	vte-buildlink

vte-buildlink: _BUILDLINK_USE

.endif	# VTE_BUILDLINK2_MK

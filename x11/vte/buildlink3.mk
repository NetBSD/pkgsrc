# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 07:11:28 xtraeme Exp $
#
# This Makefile fragment is included by packages that use vte.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
VTE_BUILDLINK3_MK:=	${VTE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	vte
.endif

.if !empty(VTE_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		vte
BUILDLINK_DEPENDS.vte+=		vte>=0.11.10nb1
BUILDLINK_PKGSRCDIR.vte?=	../../x11/vte

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

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libzvt/buildlink3.mk"

.endif # VTE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

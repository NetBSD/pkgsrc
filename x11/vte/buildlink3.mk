# $NetBSD: buildlink3.mk,v 1.4 2004/04/01 18:49:52 jmmv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
VTE_BUILDLINK3_MK:=	${VTE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	vte
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nvte}
BUILDLINK_PACKAGES+=	vte

.if !empty(VTE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.vte+=		vte>=0.11.10nb2
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
.endif	# VTE_BUILDLINK3_MK

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libzvt/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

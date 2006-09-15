# $NetBSD: buildlink3.mk,v 1.15 2006/09/15 15:16:42 jmmv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
VTE_BUILDLINK3_MK:=	${VTE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	vte
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nvte}
BUILDLINK_PACKAGES+=	vte
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}vte

.if !empty(VTE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.vte+=	vte>=0.14.0
BUILDLINK_PKGSRCDIR.vte?=	../../x11/vte
.endif	# VTE_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libzvt/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

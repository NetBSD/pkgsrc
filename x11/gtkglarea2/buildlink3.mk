# $NetBSD: buildlink3.mk,v 1.1 2004/02/18 15:48:00 minskim Exp $
#
# This Makefile fragment is included by packages that use gtkglarea2.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GTKGLAREA2_BUILDLINK3_MK:=	${GTKGLAREA2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkglarea2
.endif

.if !empty(GTKGLAREA2_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gtkglarea2
BUILDLINK_DEPENDS.gtkglarea2+=		gtkglarea2>=1.99.0nb3
BUILDLINK_PKGSRCDIR.gtkglarea2?=		../../x11/gtkglarea2

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif # GTKGLAREA2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

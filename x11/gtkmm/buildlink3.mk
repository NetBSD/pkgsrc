# $NetBSD: buildlink3.mk,v 1.1 2004/03/09 20:56:35 minskim Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GTKMM_BUILDLINK3_MK:=	${GTKMM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkmm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtkmm}
BUILDLINK_PACKAGES+=	gtkmm

.if !empty(GTKMM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gtkmm+=	gtkmm>=2.2.8nb2
BUILDLINK_PKGSRCDIR.gtkmm?=	../../x11/gtkmm

.include "../../devel/libsigc++/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif	# GTKMM_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

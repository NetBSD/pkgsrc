# $NetBSD: buildlink3.mk,v 1.1 2004/04/26 22:07:06 snj Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GTKMM_BUILDLINK3_MK:=	${GTKMM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkmm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtkmm}
BUILDLINK_PACKAGES+=	gtkmm

.if !empty(GTKMM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gtkmm+=	gtk-->=1.2.10nb3
BUILDLINK_PKGSRCDIR.gtkmm?=	../../x11/gtk--
.endif	# GTKMM_BUILDLINK3_MK

.include "../../devel/libsigc++10/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

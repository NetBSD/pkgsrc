# $NetBSD: buildlink3.mk,v 1.6 2006/02/05 23:11:35 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GTKMM_BUILDLINK3_MK:=	${GTKMM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtkmm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtkmm}
BUILDLINK_PACKAGES+=	gtkmm

.if !empty(GTKMM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gtkmm+=	gtkmm>=2.6.3
BUILDLINK_RECOMMENDED.gtkmm?=	gtkmm>=2.8.2nb2
BUILDLINK_PKGSRCDIR.gtkmm?=	../../x11/gtkmm
.endif	# GTKMM_BUILDLINK3_MK

.include "../../devel/glibmm/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

# $NetBSD: buildlink3.mk,v 1.2 2004/09/24 01:56:54 rh Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNUSTEP_BACK_BUILDLINK3_MK:=	${GNUSTEP_BACK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnustep-back
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnustep-back}
BUILDLINK_PACKAGES+=	gnustep-back

.if !empty(GNUSTEP_BACK_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnustep-back+=	gnustep-back>=0.9.2
BUILDLINK_RECOMMENDED.gnustep-back+=	gnustep-back>=0.9.3nb1
BUILDLINK_PKGSRCDIR.gnustep-back?=	../../x11/gnustep-back
.endif	# GNUSTEP_BACK_BUILDLINK3_MK

.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gnustep-gui/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

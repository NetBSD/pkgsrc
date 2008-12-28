# $NetBSD: buildlink3.mk,v 1.10 2008/12/28 07:56:38 adam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
GNUSTEP_PREFERENCES_BUILDLINK3_MK:=	${GNUSTEP_PREFERENCES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnustep-preferences
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnustep-preferences}
BUILDLINK_PACKAGES+=	gnustep-preferences
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnustep-preferences

.if !empty(GNUSTEP_PREFERENCES_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gnustep-preferences+=	gnustep-preferences>=1.2.0
BUILDLINK_ABI_DEPENDS.gnustep-preferences+=	gnustep-preferences>=1.2.0nb16
BUILDLINK_PKGSRCDIR.gnustep-preferences?=	../../x11/gnustep-preferences
.endif	# GNUSTEP_PREFERENCES_BUILDLINK3_MK

.include "../../x11/gnustep-back/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}

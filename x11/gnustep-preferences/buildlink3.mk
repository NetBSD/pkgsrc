# $NetBSD: buildlink3.mk,v 1.2 2006/01/24 07:32:52 wiz Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
GNUSTEP_PREFERENCES_BUILDLINK3_MK:=	${GNUSTEP_PREFERENCES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnustep-preferences
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnustep-preferences}
BUILDLINK_PACKAGES+=	gnustep-preferences

.if !empty(GNUSTEP_PREFERENCES_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnustep-preferences+=	gnustep-preferences>=1.2.0
BUILDLINK_RECOMMENDED.gnustep-preferences?=	gnustep-preferences>=1.2.0nb12
BUILDLINK_PKGSRCDIR.gnustep-preferences?=	../../x11/gnustep-preferences
.endif	# GNUSTEP_PREFERENCES_BUILDLINK3_MK

#.include "../../x11/gnustep-back/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

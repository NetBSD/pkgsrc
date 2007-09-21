# $NetBSD: buildlink3.mk,v 1.14 2007/09/21 13:04:31 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNUSTEP_BACK_BUILDLINK3_MK:=	${GNUSTEP_BACK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnustep-back
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnustep-back}
BUILDLINK_PACKAGES+=	gnustep-back
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnustep-back

.if !empty(GNUSTEP_BACK_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gnustep-back+=	gnustep-back>=0.9.2
BUILDLINK_ABI_DEPENDS.gnustep-back+=	gnustep-back>=0.10.3nb1
BUILDLINK_PKGSRCDIR.gnustep-back?=	../../x11/gnustep-back
.endif	# GNUSTEP_BACK_BUILDLINK3_MK

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glitz/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../x11/gnustep-gui/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}

# $NetBSD: buildlink3.mk,v 1.5 2006/01/17 07:42:41 adam Exp $

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

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glitz/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gnustep-gui/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

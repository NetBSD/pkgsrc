# $NetBSD: buildlink3.mk,v 1.7 2006/02/05 23:11:33 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNUSTEP_BACK_BUILDLINK3_MK:=	${GNUSTEP_BACK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnustep-back
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnustep-back}
BUILDLINK_PACKAGES+=	gnustep-back

.if !empty(GNUSTEP_BACK_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnustep-back+=	gnustep-back>=0.9.2
BUILDLINK_RECOMMENDED.gnustep-back+=	gnustep-back>=0.10.2nb2
BUILDLINK_PKGSRCDIR.gnustep-back?=	../../x11/gnustep-back
.endif	# GNUSTEP_BACK_BUILDLINK3_MK

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glitz/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gnustep-gui/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

# $NetBSD: buildlink3.mk,v 1.2 2004/09/24 01:56:53 rh Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GNUSTEP_GUI_BUILDLINK3_MK:=	${GNUSTEP_GUI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gnustep-gui
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnustep-gui}
BUILDLINK_PACKAGES+=	gnustep-gui

.if !empty(GNUSTEP_GUI_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gnustep-gui+=		gnustep-gui>=0.9.2
BUILDLINK_RECOMMENDED.gnustep-gui+=	gnustep-gui>=0.9.3nb1
BUILDLINK_PKGSRCDIR.gnustep-gui?=	../../x11/gnustep-gui
.endif	# GNUSTEP_GUI_BUILDLINK3_MK

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

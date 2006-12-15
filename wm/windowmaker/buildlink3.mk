# $NetBSD: buildlink3.mk,v 1.15 2006/12/15 20:33:03 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
WINDOWMAKER_BUILDLINK3_MK:=	${WINDOWMAKER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	windowmaker
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nwindowmaker}
BUILDLINK_PACKAGES+=	windowmaker
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}windowmaker

.if !empty(WINDOWMAKER_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.windowmaker+=		windowmaker>=0.80.2nb3
BUILDLINK_ABI_DEPENDS.windowmaker+=	windowmaker>=0.92.0nb7
BUILDLINK_PKGSRCDIR.windowmaker?=	../../wm/windowmaker
.endif	# WINDOWMAKER_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}

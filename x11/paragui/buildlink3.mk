# $NetBSD: buildlink3.mk,v 1.16 2006/07/08 23:11:15 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PARAGUI_BUILDLINK3_MK:=	${PARAGUI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	paragui
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nparagui}
BUILDLINK_PACKAGES+=	paragui
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}paragui

.if !empty(PARAGUI_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.paragui+=	paragui>=1.0.4nb3
BUILDLINK_ABI_DEPENDS.paragui+=	paragui>=1.0.4nb12
BUILDLINK_PKGSRCDIR.paragui?=	../../x11/paragui
.endif	# PARAGUI_BUILDLINK3_MK

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

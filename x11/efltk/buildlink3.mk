# $NetBSD: buildlink3.mk,v 1.9 2006/07/08 23:11:13 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EFLTK_BUILDLINK3_MK:=	${EFLTK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	efltk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nefltk}
BUILDLINK_PACKAGES+=	efltk
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}efltk

.if !empty(EFLTK_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.efltk+=	efltk>=2.0.5nb1
BUILDLINK_ABI_DEPENDS.efltk?=	efltk>=2.0.5nb7
BUILDLINK_PKGSRCDIR.efltk?=	../../x11/efltk
.endif	# EFLTK_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

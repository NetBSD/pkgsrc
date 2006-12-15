# $NetBSD: buildlink3.mk,v 1.10 2006/12/15 20:33:03 joerg Exp $

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
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

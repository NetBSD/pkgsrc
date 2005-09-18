# $NetBSD: buildlink3.mk,v 1.2 2005/09/18 21:18:53 minskim Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EFLTK_BUILDLINK3_MK:=	${EFLTK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	efltk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nefltk}
BUILDLINK_PACKAGES+=	efltk

.if !empty(EFLTK_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.efltk+=	efltk>=2.0.5nb1
BUILDLINK_PKGSRCDIR.efltk?=	../../x11/efltk
.endif	# EFLTK_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

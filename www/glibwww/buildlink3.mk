# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:18:26 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GLIBWWW_BUILDLINK3_MK:=	${GLIBWWW_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	glibwww
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nglibwww}
BUILDLINK_PACKAGES+=	glibwww

.if !empty(GLIBWWW_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.glibwww?=	glibwww>=0.2nb5
BUILDLINK_RECOMMENDED.glibwww+=	glibwww>=0.2nb7
BUILDLINK_PKGSRCDIR.glibwww?=	../../www/glibwww
.endif	# GLIBWWW_BUILDLINK3_MK

.include "../../www/libwww/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

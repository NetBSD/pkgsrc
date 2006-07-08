# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:11:17 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XSCREENSAVER_BUILDLINK3_MK:=	${XSCREENSAVER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xscreensaver
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxscreensaver}
BUILDLINK_PACKAGES+=	xscreensaver
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xscreensaver

.if !empty(XSCREENSAVER_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.xscreensaver+=	xscreensaver>=4.14
BUILDLINK_ABI_DEPENDS.xscreensaver?=	xscreensaver>=4.22nb3
BUILDLINK_PKGSRCDIR.xscreensaver?=	../../x11/xscreensaver
.endif	# XSCREENSAVER_BUILDLINK3_MK

.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}

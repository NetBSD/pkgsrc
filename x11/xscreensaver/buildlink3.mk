# $NetBSD: buildlink3.mk,v 1.4 2006/02/05 23:11:49 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XSCREENSAVER_BUILDLINK3_MK:=	${XSCREENSAVER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xscreensaver
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxscreensaver}
BUILDLINK_PACKAGES+=	xscreensaver

.if !empty(XSCREENSAVER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xscreensaver+=	xscreensaver>=4.14
BUILDLINK_RECOMMENDED.xscreensaver?=	xscreensaver>=4.22nb3
BUILDLINK_PKGSRCDIR.xscreensaver?=	../../x11/xscreensaver
.endif	# XSCREENSAVER_BUILDLINK3_MK

.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

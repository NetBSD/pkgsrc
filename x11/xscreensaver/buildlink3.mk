# $NetBSD: buildlink3.mk,v 1.3 2004/03/18 09:12:18 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XSCREENSAVER_BUILDLINK3_MK:=	${XSCREENSAVER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xscreensaver
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxscreensaver}
BUILDLINK_PACKAGES+=	xscreensaver

.if !empty(XSCREENSAVER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xscreensaver+=	xscreensaver>=4.14
BUILDLINK_PKGSRCDIR.xscreensaver?=	../../x11/xscreensaver
.endif	# XSCREENSAVER_BUILDLINK3_MK

.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

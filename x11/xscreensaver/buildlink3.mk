# $NetBSD: buildlink3.mk,v 1.1 2004/02/26 17:31:40 jmmv Exp $
#
# This Makefile fragment is included by packages that use xscreensaver.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XSCREENSAVER_BUILDLINK3_MK:=	${XSCREENSAVER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xscreensaver
.endif

.if !empty(XSCREENSAVER_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			xscreensaver
BUILDLINK_DEPENDS.xscreensaver+=		xscreensaver>=4.14
BUILDLINK_PKGSRCDIR.xscreensaver?=		../../x11/xscreensaver

.include "../../textproc/libxml2/buildlink3.mk"

.endif # XSCREENSAVER_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

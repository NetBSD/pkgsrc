# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/04/18 17:06:39 reed Exp $
#
# This Makefile fragment is included by packages that use xproto.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XPROTO_BUILDLINK3_MK:=	${XPROTO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xproto
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxproto}
BUILDLINK_PACKAGES+=	xproto

.if !empty(XPROTO_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.xproto?=		xproto>=6.6
BUILDLINK_PKGSRCDIR.xproto?=		../../wip/xproto
BUILDLINK_DEPMETHOD.xproto?=		build
.endif # XPROTO_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

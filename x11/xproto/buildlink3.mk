# $NetBSD: buildlink3.mk,v 1.5 2006/07/11 14:42:04 joerg Exp $
#
# This Makefile fragment is included by packages that use xproto.
#

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "xorg"
.include "../../mk/x11.buildlink3.mk"
.else

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XPROTO_BUILDLINK3_MK:=	${XPROTO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xproto
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxproto}
BUILDLINK_PACKAGES+=	xproto
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xproto

.if !empty(XPROTO_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.xproto?=		xproto>=6.6
BUILDLINK_PKGSRCDIR.xproto?=		../../x11/xproto
BUILDLINK_DEPMETHOD.xproto?=		build
.endif # XPROTO_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}

.endif

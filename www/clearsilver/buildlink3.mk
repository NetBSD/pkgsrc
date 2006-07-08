# $NetBSD: buildlink3.mk,v 1.6 2006/07/08 23:11:12 jlam Exp $

BUILDLINK_DEPMETHOD.clearsilver?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
CLEARSILVER_BUILDLINK3_MK:=	${CLEARSILVER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	clearsilver-base
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nclearsilver-base}
BUILDLINK_PACKAGES+=	clearsilver-base
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}clearsilver-base

.if !empty(CLEARSILVER_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.clearsilver+=		clearsilver-base>=0.9.0
BUILDLINK_ABI_DEPENDS.clearsilver+=	clearsilver>=0.10.1
BUILDLINK_PKGSRCDIR.clearsilver?=	../../www/clearsilver-base
.endif

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}

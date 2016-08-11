# $NetBSD: buildlink3.mk,v 1.1 2016/08/11 12:51:15 schmonz Exp $

BUILDLINK_TREE+=	swill

.if !defined(SWILL_BUILDLINK3_MK)
SWILL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.swill+=	swill>=0.3nb2
BUILDLINK_PKGSRCDIR.swill?=	../../www/swill
.endif	# SWILL_BUILDLINK3_MK

BUILDLINK_TREE+=	-swill

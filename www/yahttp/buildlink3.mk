# $NetBSD: buildlink3.mk,v 1.1 2015/04/02 23:52:50 rodent Exp $

BUILDLINK_TREE+=	yahttp

.if !defined(YAHTTP_BUILDLINK3_MK)
YAHTTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.yahttp+=	yahttp>=0.1.5
BUILDLINK_PKGSRCDIR.yahttp?=	../../www/yahttp

.endif	# YAHTTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-yahttp

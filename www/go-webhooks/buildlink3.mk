# $NetBSD: buildlink3.mk,v 1.1 2018/07/14 22:20:10 minskim Exp $

BUILDLINK_TREE+=	go-webhooks

.if !defined(GO_WEBHOOKS_BUILDLINK3_MK)
GO_WEBHOOKS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-webhooks=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-webhooks?=	build

BUILDLINK_API_DEPENDS.go-webhooks+=	go-webhooks>=3.12.0
BUILDLINK_PKGSRCDIR.go-webhooks?=	../../www/go-webhooks

.include "../../www/go-gogs-client/buildlink3.mk"
.endif	# GO_WEBHOOKS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-webhooks

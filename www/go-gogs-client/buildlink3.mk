# $NetBSD: buildlink3.mk,v 1.1 2018/07/13 00:56:23 minskim Exp $

BUILDLINK_TREE+=	go-gogs-client

.if !defined(GO_GOGS_CLIENT_BUILDLINK3_MK)
GO_GOGS_CLIENT_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-gogs-client=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-gogs-client?=		build

BUILDLINK_API_DEPENDS.go-gogs-client+=	go-gogs-client>=0.0.20171114
BUILDLINK_PKGSRCDIR.go-gogs-client?=	../../www/go-gogs-client
.endif	# GO_GOGS_CLIENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-gogs-client

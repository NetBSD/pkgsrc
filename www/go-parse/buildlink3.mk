# $NetBSD: buildlink3.mk,v 1.1 2018/11/18 08:42:16 ryoon Exp $

BUILDLINK_TREE+=	go-parse

.if !defined(GO_PARSE_BUILDLINK3_MK)
GO_PARSE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-parse=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-parse?=		build

BUILDLINK_API_DEPENDS.go-parse+=	go-parse>=2.3.3
BUILDLINK_PKGSRCDIR.go-parse?=		../../www/go-parse
.endif	# GO_PARSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-parse

# $NetBSD: buildlink3.mk,v 1.1 2018/11/18 07:36:50 ryoon Exp $

BUILDLINK_TREE+=	go-urlesc

.if !defined(GO_URLESC_BUILDLINK3_MK)
GO_URLESC_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-urlesc=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-urlesc?=		build

BUILDLINK_API_DEPENDS.go-urlesc+=	go-urlesc>=0.0.0.20170810
BUILDLINK_PKGSRCDIR.go-urlesc?=		../../www/go-urlesc
.endif	# GO_URLESC_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-urlesc

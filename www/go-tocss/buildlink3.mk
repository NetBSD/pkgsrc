# $NetBSD: buildlink3.mk,v 1.1 2018/11/18 08:48:11 ryoon Exp $

BUILDLINK_TREE+=	go-tocss

.if !defined(GO_TOCSS_BUILDLINK3_MK)
GO_TOCSS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-tocss=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-tocss?=		build

BUILDLINK_API_DEPENDS.go-tocss+=	go-tocss>=0.5.0
BUILDLINK_PKGSRCDIR.go-tocss?=		../../www/go-tocss

.endif	# GO_TOCSS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-tocss

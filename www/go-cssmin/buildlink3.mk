# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:15 jperkin Exp $

BUILDLINK_TREE+=	go-cssmin

.if !defined(GO_CSSMIN_BUILDLINK3_MK)
GO_CSSMIN_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-cssmin=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-cssmin?=		build

BUILDLINK_API_DEPENDS.go-cssmin+=	go-cssmin>=0.0
BUILDLINK_PKGSRCDIR.go-cssmin?=		../../www/go-cssmin

.endif  # GO_CSSMIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-cssmin

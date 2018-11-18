# $NetBSD: buildlink3.mk,v 1.1 2018/11/18 08:40:17 ryoon Exp $

BUILDLINK_TREE+=	go-minify

.if !defined(GO_MINIFY_BUILDLINK3_MK)
GO_MINIFY_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-minify=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-minify?=		build

BUILDLINK_API_DEPENDS.go-minify+=	go-minify>=2.3.5
BUILDLINK_PKGSRCDIR.go-minify?=		../../www/go-minify

.endif	# GO_MINIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-minify

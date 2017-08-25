# $NetBSD: buildlink3.mk,v 1.2 2017/08/25 16:49:15 jperkin Exp $

BUILDLINK_TREE+=	go-gohtml

.if !defined(GO_GOHTML_BUILDLINK3_MK)
GO_GOHTML_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-gohtml=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-gohtml?=		build

BUILDLINK_API_DEPENDS.go-gohtml+=	go-gohtml>=0.0
BUILDLINK_PKGSRCDIR.go-gohtml?=		../../www/go-gohtml

.include "../../net/go-net/buildlink3.mk"
.endif  # GO_GOHTML_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-gohtml

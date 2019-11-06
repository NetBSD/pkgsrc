# $NetBSD: buildlink3.mk,v 1.1 2019/11/06 13:35:18 ng0 Exp $

BUILDLINK_TREE+=	go-mux

.if !defined(GO_MUX_BUILDLINK3_MK)
GO_MUX_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-mux=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-mux?=		build

BUILDLINK_API_DEPENDS.go-mux+=	go-mux>=1.7.2
BUILDLINK_PKGSRCDIR.go-mux?=	../../www/go-mux
.endif	# GO_MUX_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-mux

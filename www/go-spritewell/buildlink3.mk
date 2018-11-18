# $NetBSD: buildlink3.mk,v 1.1 2018/11/18 08:46:07 ryoon Exp $

BUILDLINK_TREE+=	go-spritewell

.if !defined(GO_SPRITEWELL_BUILDLINK3_MK)
GO_SPRITEWELL_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-spritewell=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-spritewell?=		build

BUILDLINK_API_DEPENDS.go-spritewell+=	go-spritewell>=0.5.0
BUILDLINK_PKGSRCDIR.go-spritewell?=	../../www/go-spritewell
.endif	# GO_SPRITEWELL_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-spritewell

# $NetBSD: buildlink3.mk,v 1.1 2018/11/18 08:37:22 ryoon Exp $

BUILDLINK_TREE+=	go-libsass

.if !defined(GO_LIBSASS_BUILDLINK3_MK)
GO_LIBSASS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-libsass=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-libsass?=	build

BUILDLINK_API_DEPENDS.go-libsass+=	go-libsass>=0.9.2
BUILDLINK_PKGSRCDIR.go-libsass?=	../../www/go-libsass

.endif	# GO_LIBSASS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-libsass

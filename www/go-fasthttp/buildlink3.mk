# $NetBSD: buildlink3.mk,v 1.1 2019/11/06 12:32:28 ng0 Exp $

BUILDLINK_TREE+=	go-fasthttp

.if !defined(GO_FASTHTTP_BUILDLINK3_MK)
GO_FASTHTTP_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-fasthttp=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-fasthttp?=	build

BUILDLINK_API_DEPENDS.go-fasthttp+=	go-fasthttp>=1.3.0
BUILDLINK_PKGSRCDIR.go-fasthttp?=	../../www/go-fasthttp

.include "../../devel/go-bytebufferpool/buildlink3.mk"
.include "../../net/go-tcplisten/buildlink3.mk"
.include "../../net/go-net/buildlink3.mk"
.include "../../devel/go-cpuid/buildlink3.mk"
.include "../../devel/go-compress/buildlink3.mk"
.endif	# GO_FASTHTTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-fasthttp

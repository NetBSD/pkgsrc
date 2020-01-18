# $NetBSD: buildlink3.mk,v 1.22 2020/01/18 21:48:30 jperkin Exp $

BUILDLINK_TREE+=	serf

.if !defined(SERF_BUILDLINK3_MK)
SERF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.serf+=	serf>=1.1.1
BUILDLINK_ABI_DEPENDS.serf+=	serf>=1.3.9nb1
BUILDLINK_PKGSRCDIR.serf?=	../../www/serf

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # SERF_BUILDLINK3_MK

BUILDLINK_TREE+=	-serf

# $NetBSD: buildlink3.mk,v 1.4 2014/02/12 23:18:47 tron Exp $

BUILDLINK_TREE+=	serf

.if !defined(SERF_BUILDLINK3_MK)
SERF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.serf+=	serf0>=0.1.0
BUILDLINK_ABI_DEPENDS.serf+=	serf0>=0.7.2nb2
BUILDLINK_PKGSRCDIR.serf?=	../../www/serf0

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # SERF_BUILDLINK3_MK

BUILDLINK_TREE+=	-serf

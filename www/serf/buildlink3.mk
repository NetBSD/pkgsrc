# $NetBSD: buildlink3.mk,v 1.23 2023/10/24 22:11:33 wiz Exp $

BUILDLINK_TREE+=	serf

.if !defined(SERF_BUILDLINK3_MK)
SERF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.serf+=	serf>=1.1.1
BUILDLINK_ABI_DEPENDS.serf+=	serf>=1.3.10nb2
BUILDLINK_PKGSRCDIR.serf?=	../../www/serf

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # SERF_BUILDLINK3_MK

BUILDLINK_TREE+=	-serf

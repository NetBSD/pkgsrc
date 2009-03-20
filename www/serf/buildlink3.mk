# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:25:38 joerg Exp $

BUILDLINK_TREE+=	serf

.if !defined(SERF_BUILDLINK3_MK)
SERF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.serf+=	serf>=0.1.0
BUILDLINK_ABI_DEPENDS.serf?=	serf>=0.1.2nb3
BUILDLINK_PKGSRCDIR.serf?=	../../www/serf

.include "../../devel/apr/buildlink3.mk"
.include "../../devel/apr-util/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # SERF_BUILDLINK3_MK

BUILDLINK_TREE+=	-serf

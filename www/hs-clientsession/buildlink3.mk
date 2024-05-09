# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:52 pho Exp $

BUILDLINK_TREE+=	hs-clientsession

.if !defined(HS_CLIENTSESSION_BUILDLINK3_MK)
HS_CLIENTSESSION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-clientsession+=	hs-clientsession>=0.9.2
BUILDLINK_ABI_DEPENDS.hs-clientsession+=	hs-clientsession>=0.9.2.0nb2
BUILDLINK_PKGSRCDIR.hs-clientsession?=		../../www/hs-clientsession

.include "../../converters/hs-base64-bytestring/buildlink3.mk"
.include "../../devel/hs-cereal/buildlink3.mk"
.include "../../security/hs-crypto-api/buildlink3.mk"
.include "../../security/hs-crypton/buildlink3.mk"
.include "../../security/hs-entropy/buildlink3.mk"
.include "../../devel/hs-setenv/buildlink3.mk"
.include "../../security/hs-skein/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.endif	# HS_CLIENTSESSION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-clientsession

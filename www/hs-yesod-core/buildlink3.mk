# $NetBSD: buildlink3.mk,v 1.4 2024/05/09 01:32:56 pho Exp $

BUILDLINK_TREE+=	hs-yesod-core

.if !defined(HS_YESOD_CORE_BUILDLINK3_MK)
HS_YESOD_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-yesod-core+=	hs-yesod-core>=1.6.25
BUILDLINK_ABI_DEPENDS.hs-yesod-core+=	hs-yesod-core>=1.6.25.1nb1
BUILDLINK_PKGSRCDIR.hs-yesod-core?=	../../www/hs-yesod-core

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-attoparsec-aeson/buildlink3.mk"
.include "../../devel/hs-auto-update/buildlink3.mk"
.include "../../textproc/hs-blaze-html/buildlink3.mk"
.include "../../textproc/hs-blaze-markup/buildlink3.mk"
.include "../../textproc/hs-case-insensitive/buildlink3.mk"
.include "../../devel/hs-cereal/buildlink3.mk"
.include "../../www/hs-clientsession/buildlink3.mk"
.include "../../devel/hs-conduit/buildlink3.mk"
.include "../../devel/hs-conduit-extra/buildlink3.mk"
.include "../../www/hs-cookie/buildlink3.mk"
.include "../../security/hs-entropy/buildlink3.mk"
.include "../../sysutils/hs-fast-logger/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../devel/hs-memory/buildlink3.mk"
.include "../../devel/hs-monad-logger/buildlink3.mk"
.include "../../www/hs-path-pieces/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-resourcet/buildlink3.mk"
.include "../../textproc/hs-shakespeare/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../devel/hs-unliftio/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../www/hs-wai/buildlink3.mk"
.include "../../www/hs-wai-extra/buildlink3.mk"
.include "../../www/hs-wai-logger/buildlink3.mk"
.include "../../www/hs-warp/buildlink3.mk"
.include "../../devel/hs-word8/buildlink3.mk"
.endif	# HS_YESOD_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-yesod-core

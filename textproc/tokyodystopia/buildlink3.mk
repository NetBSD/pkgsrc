# $NetBSD: buildlink3.mk,v 1.6 2009/03/21 05:35:38 obache Exp $

BUILDLINK_TREE+=	tokyodystopia

.if !defined(TOKYODYSTOPIA_BUILDLINK3_MK)
TOKYODYSTOPIA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tokyodystopia+=	tokyodystopia>=0.9.5
BUILDLINK_ABI_DEPENDS.tokyodystopia+=	tokyodystopia>=0.9.9nb1
BUILDLINK_PKGSRCDIR.tokyodystopia?=	../../textproc/tokyodystopia

.include "../../databases/tokyocabinet/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.endif # TOKYODYSTOPIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-tokyodystopia

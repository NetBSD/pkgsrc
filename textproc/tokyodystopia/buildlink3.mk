# $NetBSD: buildlink3.mk,v 1.7 2009/12/19 12:56:45 obache Exp $

BUILDLINK_TREE+=	tokyodystopia

.if !defined(TOKYODYSTOPIA_BUILDLINK3_MK)
TOKYODYSTOPIA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tokyodystopia+=	tokyodystopia>=0.9.5
BUILDLINK_ABI_DEPENDS.tokyodystopia+=	tokyodystopia>=0.9.13nb1
BUILDLINK_PKGSRCDIR.tokyodystopia?=	../../textproc/tokyodystopia

.include "../../databases/tokyocabinet/buildlink3.mk"
.endif # TOKYODYSTOPIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-tokyodystopia

# $NetBSD: buildlink3.mk,v 1.30 2022/04/18 19:10:11 adam Exp $

BUILDLINK_TREE+=	mono-xsp

.if !defined(MONO_XSP_BUILDLINK3_MK)
MONO_XSP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mono-xsp+=	mono-xsp>=2.0
BUILDLINK_ABI_DEPENDS.mono-xsp+=	mono-xsp>=4.7.1nb3
BUILDLINK_PKGSRCDIR.mono-xsp?=		../../www/mono-xsp

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.endif # MONO_XSP_BUILDLINK3_MK

BUILDLINK_TREE+=	-mono-xsp

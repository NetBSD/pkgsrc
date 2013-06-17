# $NetBSD: buildlink3.mk,v 1.11 2013/06/17 12:44:55 wiz Exp $

BUILDLINK_TREE+=	mono-xsp

.if !defined(MONO_XSP_BUILDLINK3_MK)
MONO_XSP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mono-xsp+=	mono-xsp>=2.0
BUILDLINK_ABI_DEPENDS.mono-xsp+=	mono-xsp>=2.10.2nb6
BUILDLINK_PKGSRCDIR.mono-xsp?=	../../www/mono-xsp

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../lang/mono2/buildlink3.mk"
.endif # MONO_XSP_BUILDLINK3_MK

BUILDLINK_TREE+=	-mono-xsp

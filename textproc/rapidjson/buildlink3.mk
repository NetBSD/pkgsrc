# $NetBSD: buildlink3.mk,v 1.1 2017/11/26 23:37:18 minskim Exp $

BUILDLINK_TREE+=	rapidjson

.if !defined(RAPIDJSON_BUILDLINK3_MK)
RAPIDJSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rapidjson+=	rapidjson>=1.1.0
BUILDLINK_DEPMETHOD.rapidjson?=		build
BUILDLINK_PKGSRCDIR.rapidjson?=		../../textproc/rapidjson
.endif	# RAPIDJSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-rapidjson

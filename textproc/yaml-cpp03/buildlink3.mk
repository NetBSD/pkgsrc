# $NetBSD: buildlink3.mk,v 1.2 2018/06/02 19:04:32 joerg Exp $

BUILDLINK_TREE+=	yaml-cpp

.if !defined(YAML_CPP_BUILDLINK3_MK)
YAML_CPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.yaml-cpp+=	yaml-cpp>=0.3.0<0.4
BUILDLINK_PKGSRCDIR.yaml-cpp?=		../../textproc/yaml-cpp03

.endif	# YAML_CPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-yaml-cpp

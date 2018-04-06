# $NetBSD: buildlink3.mk,v 1.1 2018/04/06 03:41:07 maya Exp $

BUILDLINK_TREE+=	yaml-cpp

.if !defined(YAML_CPP_BUILDLINK3_MK)
YAML_CPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.yaml-cpp+=	yaml-cpp>=0.3.0
BUILDLINK_PKGSRCDIR.yaml-cpp?=		../../textproc/yaml-cpp03

.endif	# YAML_CPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-yaml-cpp

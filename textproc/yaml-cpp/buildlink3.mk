# $NetBSD: buildlink3.mk,v 1.4 2023/07/20 09:46:34 nia Exp $

BUILDLINK_TREE+=	yaml-cpp

.if !defined(YAML_CPP_BUILDLINK3_MK)
YAML_CPP_BUILDLINK3_MK:=

USE_CXX_FEATURES+=			c++11

BUILDLINK_API_DEPENDS.yaml-cpp+=	yaml-cpp>=0.5.0
BUILDLINK_PKGSRCDIR.yaml-cpp?=		../../textproc/yaml-cpp

.endif	# YAML_CPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-yaml-cpp
